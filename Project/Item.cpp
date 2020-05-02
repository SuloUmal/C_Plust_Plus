#include "Item.h"
#include <iomanip>
#include "Utilities.h"
#include <iostream>
#include <string>
size_t Item::m_widthField = 1;
	Item::Item(std::string str) {
		Utilities obj;
		size_t start = 0;
		bool more = false;
		m_name = obj.extractToken(str, start, more);
		start = str.find(obj.getDelimiter(), start + 1) + 1;
		m_serialNumber = std::stoi(obj.extractToken(str, start, more));
		start = str.find(obj.getDelimiter(), start + 1) + 1;
		m_quantity = std::stoi(obj.extractToken(str, start, more));
		start = str.find(obj.getDelimiter(), start + 1) + 1;
		m_description = obj.extractToken(str, start, more);

		if (m_widthField < m_name.length())
		{
			m_widthField = m_name.length();
		}
	}
const std::string& Item::getName() const{
  return m_name;
}
const unsigned int Item::getSerialNumber(){
  return m_serialNumber;
}
const unsigned int Item::getQuantity(){
  return m_quantity;
}
void Item::updateQuantity(){
  if(m_quantity >= 1)
  m_quantity -= 1;
}
void Item::display(std::ostream& os, bool full) const{
	os << setw(12) << std::setfill(' ') << std::left << getName();
	os << " [" << std::setfill('0') << std::setw(6) << right << m_serialNumber << "] ";
  if (full) 
  os << "Quantity: " << std::setfill(' ') << std::setw(m_widthField) << left << m_quantity << " Description: " << left << m_description;
  os << endl;
}
