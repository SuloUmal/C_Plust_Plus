#include <iostream>
#include <iomanip>
#include "Movie.h"
namespace sdds{
Movie::Movie(): movieTitle{""}, movieYear{0}, movieDesc{""}  {};
Movie::Movie(const std::string& strMovie){
  string str = strMovie;
  
  movieTitle = str.substr(0, str.find(','));
  removeSpace(movieTitle);
  str.erase(0, str.find(',')+1 );

  movieYear = stoi(str.substr(0, str.find(',')));
  str.erase(0, str.find(',')+1 );

  movieDesc = str.substr(0, str.find(','));
  removeSpace(movieDesc);
  str.erase(0, str.length() );
}
void Movie::removeSpace(string& str){
 //remove spaces begining
  int i = 0;
  while(str[i] == ' ' ){ i++; }
  str = str.substr(i);
  //remove spaces end
  i = str.length();
  while(str[i] == ' ' ){i--;}
  str = str.substr(0, i);
  }

std::ostream& operator<<(std::ostream& os, const Movie& obj) {
	os << setw(40) << obj.movieTitle << " | " << setw(4) << obj.movieYear << " | " << obj.movieDesc << endl;
	return os;
}
}
