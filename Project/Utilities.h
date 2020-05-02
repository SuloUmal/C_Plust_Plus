#ifndef SDDS_UTILITIES__H
#define SDDS_UTILITIES__H
#include <string.h>
#include <iostream>
#include <cstddef>


  class Utilities{
    size_t m_widthField = 1;
    static char m_delimiter;
    public:
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char del);
    const char getDelimiter() const;
  };

#endif