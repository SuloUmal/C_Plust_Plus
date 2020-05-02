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
#include "Racecar.h"
using namespace std;
namespace sdds{
Racecar::Racecar(istream& is) :Car(is)
{
	string str;
	is >> str;
	boost = stod(str);
	is.ignore();
}

void Racecar::display(ostream& out) const
{
	Car::display(out);
	out << "*";
}

double Racecar::topSpeed() const
{
	return Car::topSpeed() * (1 + boost);
}
}