// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <cctype> 
#include "Car.h"

using namespace std;
namespace sdds{
Car::Car()
{
	make = "";
	cond = "";
	maxSpeed = 0;
}

Car::Car(std::istream& is)
{
	std::string field;
	std::string comma;
	std::string::size_type pos;
	std::getline(is, field, ',');

	do {
		if (field[0] == ' ') {
			field.erase(0, 1);
		}

		if (field[field.size() - 1] == ' ') {
			field.erase(field.size() - 1, 1);
		}
	} while (field[0] == ' ' || field[field.size() - 1] == ' ');

	make = field;

	std::getline(is, field, ',');


	do {
		pos = field.find(' ');
		if (pos != std::string::npos) {
			field.erase(pos, 1);
		}
	} while (pos != std::string::npos);

	if (field == "" || field == " ") {
		cond = "n";
	}
	else if (!(field == "n" || field == "u" || field == "b")) {
		is >> field;
		is.ignore();
		throw 1;
	}
	else {
		cond = field;
	}

	is >> field;

	do {
		pos = field.find(',');

		if (pos != string::npos) {
			field.erase(pos, 1);
		}
	} while (pos != string::npos);
	for (string::size_type i = 0; i < field.size(); ++i) {
		if (isalpha(field[i])) {
			is >> field;
			is.ignore();
			throw 1;
		}
	}


	maxSpeed = stod(field);

	is.ignore();
}

string Car::condition() const
{
	std::string str;

	if (cond == "n") {

		str= "new";
	}
	else if (cond == "u") {

		str= "used";
	}
	else if (cond == "b") {

		str= "broken";
	}

	return str;
}

void Car::display(std::ostream& out) const{
      out << "| " << std::setw(10) << std::right << make << " | " 
			<< std::setw(6) << std::left << condition()<< " | " 
			<< std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() 
			<< " |";
    }
}


