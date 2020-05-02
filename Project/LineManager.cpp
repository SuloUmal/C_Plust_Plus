#include "LineManager.h"
#include "Utilities.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

unsigned int starting;
unsigned int ending;

LineManager::LineManager(const std::string& filename,
	std::vector<Task*>& taskVec,
	std::vector<CustomerOrder>& custVec) {
	Utilities util;
	size_t start = 0;
	std::vector<std::string> temp;
	bool more = true;
	std::ifstream file(filename);
	std::string str;

	while (!file.eof()) {
		std::getline(file, str);
		while (more) {
			temp.push_back(util.extractToken(str, start, more));
			start += temp[temp.size() - 1].length() + 1;
		}
		temp.pop_back();
		start = 0;
		more = true;
	}
	starting = (unsigned int)std::distance(
		taskVec.begin(),
		std::find_if(taskVec.begin(), taskVec.end(),
			[=](Task* it) { return it->getName() == temp[0]; }));
	ending = (unsigned int)std::distance(taskVec.begin(),
		std::find_if(taskVec.begin(), taskVec.end(), [=](Task* it) {
		return it->getName() == temp[temp.size() - 1];
	}));
	for (Task* it : taskVec) {
		size_t index = std::distance(
			std::find_if(temp.rbegin(), temp.rend(), [=](std::string itemName) {
			return itemName == it->getName();}), temp.rend());
		if (index != temp.size()) {
			auto nextTask =
				std::find_if(taskVec.begin(), taskVec.end(), [=](Task* targetTask) {
				return targetTask->getName() == temp[index + 1];
			});
			it->setNextTask(**nextTask);
		}
	}
	m_cntCustomerOrder = (unsigned int)custVec.size();
	for (size_t num = 0; num < custVec.size(); num++) {
		ToBeFilled.push_front(std::move(custVec[num]));
	}

	custVec.clear();
	AssemblyLine = taskVec;
}

bool LineManager::run(std::ostream& os) {
	bool done = true;

	if (!ToBeFilled.empty()) {
		*AssemblyLine[starting] += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}

	for (Task* task : AssemblyLine) {
		task->runProcess(std::cout);
	}

	CustomerOrder temp;

	if (AssemblyLine[ending]->getCompleted(temp)) {
		Completed.push_back(std::move(temp));
	}

	for (Task* task : AssemblyLine) {
		if (task->moveTask()) {
			done = false;
		}
	}

	return done;
}

void LineManager::displayCompleted(std::ostream& os) const {
	for (auto& i : Completed)
		i.display(os);
}
void LineManager::validateTasks() const {
	for (auto it : AssemblyLine)
		it->validate(std::cout);
}