#ifndef SDDS_ITEM__H
#define SDDS_ITEM__H
#include <string.h>
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

class Item{
  string m_name;
  string m_description;
  size_t m_serialNumber;
  size_t m_quantity;
  static size_t m_widthField;
public:
Item(std::string str);
const std::string& getName() const;
const unsigned int getSerialNumber();
const unsigned int getQuantity();
void updateQuantity();
void display(std::ostream& os, bool full) const;
};

#endif