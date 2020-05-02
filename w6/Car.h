// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include <ostream>
#include <string>
#include "Vehicle.h"
using namespace std;
namespace sdds
{
	class Car : public Vehicle{
    string make;
    string cond;
    double maxSpeed;
	public:
    Car();
		Car(istream& is); 
		string condition() const;
		double topSpeed() const{return maxSpeed;};
		void display(ostream& os) const; 
  void removeSpace(string& str);
	};
}
#endif 

