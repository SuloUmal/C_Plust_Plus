// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <string>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
#include "Vehicle.h"
using namespace std;
namespace sdds{
Vehicle* createInstance(istream& in)
{
	string line;
	getline(in, line, ',');

	for (string::size_type i = 0; i < line.size(); ++i) {

		if (line[i] != ' ') {
			if (line[i] == 'c' || line[i] == 'C') {
				Vehicle* aVehicle = new Car(in);
				return aVehicle;
			}
			else if (line[i] == 'r' || line[i] == 'R') {
				Vehicle* aVehicle = new Racecar(in);
				return aVehicle;
			}
			else {
				string::size_type pos; 
				do {
					pos = line.find(' ');
					if (pos != string::npos) {
						line.erase(pos, 1);
					}
				} while (pos != string::npos);
				char tag[2];
				tag[0] = line[0];
				tag[1] = '\0';
				getline(in,line);
				throw tag;
			}
		}
	}

	return nullptr;
}
}