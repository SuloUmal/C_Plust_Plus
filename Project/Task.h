#ifndef SDDS_TASK__H
#define SDDS_TASK__H
#include "Item.h"
#include "CustomerOrder.h"
#include <deque>
#include <string>
class Task : public Item {
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task(const std::string& str);
	Task(const Task&) = delete;
	Task& operator=(const Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;
	void runProcess(std::ostream& os);
	bool moveTask();
	void setNextTask(Task& obj);
	bool getCompleted(CustomerOrder& obj);
	void validate(std::ostream& os);
	Task& operator+=(CustomerOrder&& obj);
};

#endif

