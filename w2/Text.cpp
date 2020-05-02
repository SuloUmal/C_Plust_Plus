#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "Text.h"
namespace sdds{
  Text::Text(const std::string& filename){
    std::ifstream f(filename.c_str());
	n = 0;
    line = nullptr;
    if(!f) return;
    do{
      char c = f.get();
      if(c== ' ') n++;
    } while (!f.eof());
    f.seekg(std::ios::beg);
    line = new std::string[n];
    for (int i=0; i<n;i++) std::getline(f,line[i], ' ');
  }

  Text::Text(){
    line = nullptr;
  }
  Text::Text(const Text& obj){
    *this = obj;
  }
   Text::Text(Text&& obj){
	   *this = std::move(obj);
   }
    Text& Text::operator=(Text&& obj){
		if (this != &obj) {
			line = obj.line;
			n = obj.n;
			obj.line = nullptr;
			obj.n = 0;
      }
	  return *this;
    }
  
  Text& Text::operator=(const Text& obj){
	  if (this != &obj) {
		n = obj.n;
		line = new std::string[n];
		for (int i = 0; i < n; i++) {
		line[i] = obj.line[i];			
		}
	  }
    return *this;
  }

  Text::~Text(){
	delete[] line;
	line = nullptr;
  }

  size_t Text::size() const{
    return n;
  }

}