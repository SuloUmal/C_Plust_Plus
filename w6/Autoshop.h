// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

using namespace std;
namespace sdds
{
	class Autoshop {
		vector<Vehicle*> m_vehicle;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(ostream& out) const; 
		virtual ~Autoshop();

		template<typename T>
		void select(T test, list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
				if (test(*i) == true) {
					vehicles.push_back(*i);
				}
			};
		}
	};
}




#endif
