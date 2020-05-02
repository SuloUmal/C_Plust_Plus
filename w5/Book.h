#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <ostream>
#include <string>
using namespace std;
namespace sdds{
  class Book{
    string bookAuthor;
    string bookTitle;
    string bookCountry;
    size_t bookYear;
    double bookPrice;
    string bookDesc;
    public:
    Book();
    Book(const std::string strBook);
    const std::string& title() const{return bookTitle;};
    const string& country() const{return bookCountry;};
    const size_t& year() const{return bookYear;};
    double& price(){return bookPrice;};
    friend ostream& operator<<(ostream& os, Book& obj);
    void removeSpace(string& str);
    template<typename T>
	void fixSpelling(T str) {
			str(bookDesc);
		}
  };
}
#endif