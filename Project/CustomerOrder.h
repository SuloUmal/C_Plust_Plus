#ifndef SDDS_CUSTOMERORDER__H
#define SDDS_CUSTOMERORDER__H
#include <iostream>
#include <string>
#include "Item.h"
struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;
	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder{
std::string m_name;
std::string m_product;
unsigned int m_cntItem;
ItemInfo** m_lstItem;
static size_t m_widthField;
public:
CustomerOrder();
CustomerOrder(std::string str);
CustomerOrder operator=(const CustomerOrder& obj) = delete;
CustomerOrder(const CustomerOrder& obj);
CustomerOrder(CustomerOrder&& obj) noexcept;
CustomerOrder& operator=(CustomerOrder&& obj);
virtual ~CustomerOrder();
bool getItemFillState(std::string str) const;
bool getOrderFillState() const;
void fillItem(Item& item, std::ostream& os);
void display(std::ostream& os) const;
};

#endif