// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
using namespace std;
namespace sdds
{
	class Racecar : public Car {

		double boost;
	public:
		Racecar(istream& is); 
		void display(ostream& out) const; 
		double topSpeed() const;
	};
}



#endif // !SDDS_RACECAR_H

