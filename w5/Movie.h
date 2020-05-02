#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__
#include <ostream>
#include <string>
using namespace std;
namespace sdds{
  class Movie{
    string movieTitle;
    size_t movieYear;
    string movieDesc;
    public:
    Movie();
    Movie(const std::string& strMovie);
    const std::string& title() const{return movieTitle;};
    friend ostream& operator<<(ostream& os, const Movie& obj);
    void removeSpace(string& str);
	template<typename T>
	void fixSpelling(T spellChecker) {
		spellChecker(movieTitle);
		spellChecker(movieDesc);
	}
  };
}
#endif