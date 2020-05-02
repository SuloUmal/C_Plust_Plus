#include <iostream>
#include <string>
#include <fstream> 
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		string check;
		if (!file) {
			throw "Bad file name!";
		}
		else {
			for (int i = 0; i < 5; i++) {
				file >> m_badWords[i];
				file >> m_goodWords[i];
			}
		}
	}
		
	void SpellChecker::operator()(std::string& text) const{
		for (int i = 0; i < 5; i++) {
			size_t pos = text.find(m_badWords[i]);

			while (pos != text.npos) {
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				pos = text.find(m_badWords[i], pos + m_goodWords[i].size());
			}
		}
	}
}
