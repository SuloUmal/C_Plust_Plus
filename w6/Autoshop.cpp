// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Autoshop.h"
#include "Vehicle.h"

using namespace std;
namespace sdds{
Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
{
	m_vehicle.push_back(theVehicle);

	return *this;
}
void Autoshop::display(ostream& out) const
{

	out << "--------------------------------" << endl;
	out << "| " << "Cars in the autoshop!" << "        |" << endl;
	out << "--------------------------------" << endl;

	for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
		(*i)->display(out);
		out << endl;
	}

	out << "--------------------------------" << endl;

}

Autoshop::~Autoshop()
{
	for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
		delete *i;
	}
}
}