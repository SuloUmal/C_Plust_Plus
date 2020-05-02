#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"  

namespace sdds{

unsigned int g_maxSize=3;

String::String(const char* str){   
m_str = new char[g_maxSize+1];
if (str != nullptr){
        strncpy(m_str, str, g_maxSize);
		m_str[g_maxSize] = '\0';
      } else m_str[0] = '\0';
     }

 void String::display(std::ostream& os){
     os << m_str;
   }

std::ostream& operator<<(std::ostream& os, String& obj){
static int count = 1;
os << count++ << ": ";
obj.display(os);
return os;
 }

}
