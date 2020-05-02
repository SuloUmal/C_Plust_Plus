#ifndef SDDS_LINEMANAGER__H
#define SDDS_LINEMANAGER__H
#include "Task.h"
#include "CustomerOrder.h"
#include <deque>
#include <string>
#include <vector>

class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	
public:
	LineManager(const std::string& filename, std::vector<Task*>& taskVec, std::vector<CustomerOrder>& custVec);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};


#endif
