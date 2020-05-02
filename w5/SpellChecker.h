#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__
#include <iostream>
using namespace std;
namespace sdds{
	class SpellChecker{
	  string m_badWords[5];
	  string m_goodWords[5];
	  public:
	  SpellChecker(const char* filename);
	  void operator()(std::string& text) const;
	};
}
#endif