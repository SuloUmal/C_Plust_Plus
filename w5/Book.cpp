#include <iostream>
#include <iomanip>
#include "Book.h"
namespace sdds{
Book::Book(): bookAuthor{""}, bookTitle{""}, bookCountry{""}, bookYear{0}, bookPrice{0}, bookDesc{""}  {};
Book::Book(const std::string strBook){
  string str = strBook;

  bookAuthor = str.substr(0, str.find(','));
  removeSpace(bookAuthor);
  str.erase(0, str.find(',')+1 );

  bookTitle = str.substr(0, str.find(','));
  removeSpace(bookTitle);
  str.erase(0, str.find(',')+1 );

  bookCountry = str.substr(0, str.find(','));
  removeSpace(bookCountry);
  str.erase(0, str.find(',')+1 );

  bookPrice = stod(str.substr(0, str.find(',')));
  str.erase(0, str.find(',')+1 );

  bookYear = stoi(str.substr(0, str.find(',')));
  str.erase(0, str.find(',')+1 );

  bookDesc = str.substr(0, str.find(','));
  removeSpace(bookDesc);
  str.erase(0, str.length() );
}

ostream& operator<<(ostream& os, Book& obj){
os << setw(20) << obj.bookAuthor << " | ";
os << setw(22)<< obj.bookTitle << " | ";
os << setw(5) << obj.bookCountry << " | ";
os << setw(4) << obj.bookYear << " | ";
os << setw(6) << std::fixed << std::setprecision(2) << obj.bookPrice << " | ";
os << obj.bookDesc << endl;
return os;
}

void Book::removeSpace(string& str){
 //remove spaces begining
  int i = 0;
  while(str[i] == ' ' ){ i++; }
  str = str.substr(i);
  //remove spaces end
  for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
  str = str.substr(0, i);
  }
}