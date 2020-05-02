#ifndef SDDS__STRING_H
#define SDDS__STRING_H 

namespace sdds{
extern unsigned int g_maxSize;
 class String{
   char* m_str;
   public:
   String(const char* str);
   void display(std::ostream& os);
 };
 std::ostream& operator<<(std::ostream& os, String& obj);
}
#endif