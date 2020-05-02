#include <iostream>
#include "CustomerOrder.h"
#include "Utilities.h"
#include <iomanip> 
#include <algorithm>
size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	ItemInfo** m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const CustomerOrder& obj) {
	throw std::string("ERROR: Cannot make copies.");
}

CustomerOrder::CustomerOrder(std::string str) {
	Utilities obj;
	char delimiter = obj.getDelimiter();
	bool more = false;
	size_t start = 0;

	m_name = str.substr(start, str.find(delimiter));
	start = str.find(obj.getDelimiter(), start + 1) + 1;
	m_product = obj.extractToken(str, start, more);
	m_cntItem = std::count(str.begin(), str.end(), delimiter) - 1;
	if (m_cntItem > 0){
	m_lstItem = new ItemInfo *[m_cntItem];
		for (auto i = 0u; i < this->m_cntItem - 1; i++){
			start = str.find(obj.getDelimiter(), start + 1) + 1;
			m_lstItem[i] = new ItemInfo(obj.extractToken(str, start, more));
		}
		start = str.find(obj.getDelimiter(), start + 1) + 1;
		m_lstItem[m_cntItem - 1] = new ItemInfo(str.substr(start));
	}
	if (m_widthField < m_name.length()){
		m_widthField = m_name.length();
	}
}

CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept {
	*this = std::move(obj);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) {
	if (this != &obj) {
	
		m_name = obj.m_name;
		m_product = obj.m_product;
		m_cntItem = obj.m_cntItem;
		m_lstItem = obj.m_lstItem;

		obj.m_name = "";
		obj.m_product = "";
		obj.m_cntItem = 0;
		obj.m_lstItem = nullptr;
	}

	return *this;
}

CustomerOrder::~CustomerOrder() {

	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string str) const {
	bool ans = true;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str)
			ans = (m_lstItem[i]->m_fillState) ? true : false;
	}
	return ans;
}

bool CustomerOrder::getOrderFillState() const {
	bool ans = true;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false) ans = false;
	}
	return ans;
}


void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (item.getName() == m_lstItem[i]->m_itemName) {
			if (item.getQuantity() == 0) {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
			else {
				item.updateQuantity();
			}
			m_lstItem[i]->m_serialNumber = item.getSerialNumber();
			m_lstItem[i]->m_fillState = true;
			os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
		if (m_lstItem[i]->m_fillState == true)
			os << "FILLED";

		else
			os << "MISSING";

		os << std::endl;
	}
}