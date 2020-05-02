#include "CustomerOrder.h"
#include "Task.h"
#include <iostream>
Task::Task(const std::string& str): Item(str){
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os){
	if (!m_orders.empty() && !m_orders.back().getOrderFillState()) {
		m_orders.back().fillItem(*this, os);
	}
}

bool Task::moveTask(){

	bool move = false;

	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(getName()) && m_pNextTask) {
			*m_pNextTask += std::move(m_orders.back());
			m_orders.pop_back();
		}
		move = true;
	}
	return move;
}

void Task::setNextTask(Task& obj){
	m_pNextTask = &obj;
}

bool Task::getCompleted(CustomerOrder& obj)
{
	bool done = false;
	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(getName())) {
			obj = std::move(m_orders.back());
			m_orders.pop_back();
			done = true;
		}
	}
	return done;
}

void Task::validate(std::ostream& os){
	os << getName() << " --> ";
	if (m_pNextTask) {
		os << m_pNextTask->getName();
	}
	else {
		os << "END OF LINE";
	}
	os << std::endl;
}

Task& Task::operator+=(CustomerOrder&& obj){
	m_orders.push_front(std::move(obj));
	return *this;
}
