#include "Utilities.h"


char Utilities::m_delimiter;
  void Utilities::setFieldWidth(size_t size) {
    m_widthField = size;
  }
  size_t Utilities::getFieldWidth() const{
    return m_widthField;
  }
  const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    std::string token;
    if (str.length() > next_pos) {
	token = str.substr(next_pos, str.find(m_delimiter, next_pos) - next_pos);
	if (token == "") throw std::string("No token found");
	else {
		more = true;
		if (token.length() > m_widthField && next_pos == 0) setFieldWidth(token.length());
	}}
  else {
    more = false;
  }
	return token;
  }
  void Utilities::setDelimiter(const char del){
    m_delimiter = del;
  }
  const char Utilities::getDelimiter() const{
    return m_delimiter;
  }
  
