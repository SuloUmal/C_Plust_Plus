#include <iostream>
#include <string>
#include "Reservation.h"
#include <iomanip> 
namespace sdds{
  Reservation::Reservation(){
	  reservationId = "";
	  reservationName = "";
	  email = "";
	  peopleInParty = 0u;
	  dayToCome = 0u;
	  hourToCome = 0u;
  }
  Reservation::Reservation(const std::string& m_res){
    std::string str;
    size_t count = 0;
    for (int i = 0; i < m_res.length(); i++ ){
      if (m_res[i] != ' ') str += m_res[i];
    }

    reservationId = str.substr(0, str.find(':'));
    str.erase(0, str.find(':')+1);

    reservationName = str.substr(0, str.find(','));
    str.erase(0, str.find(',')+1);
	
    email = str.substr(0, str.find(','));
    str.erase(0, str.find(',')+1);

    peopleInParty = std::stoi(str.substr(0, str.find(',')));
    str.erase(0, str.find(',')+1);

      dayToCome = std::stoi(str.substr(0, str.size()));
    str.erase(0, str.find(',') + 1 );

    hourToCome = std::stoi(str.substr(0, str.find(',')));
    str.erase(0, str.length()+1);

    
  }
std::ostream& operator<<(std::ostream& os, const Reservation& obj) {
		std::string email = "<" + obj.email + ">";
		if (obj.hourToCome >= 6 && obj.hourToCome <= 9) {	
			os << "Reservation " << obj.reservationId << ": "<< std::setw(10) << std::right << obj.reservationName << "  "
				<< std::left << std::setw(20) << email << "    Breakfast on day DAY @ " << obj.hourToCome
				<< ":00" << " for " << obj.peopleInParty << " people." << std::endl;
		}
		else if (obj.hourToCome >= 11 && obj.hourToCome <= 15) {
			os << "Reservation " << obj.reservationId << ": " << std::setw(10) << std::right << obj.reservationName << "  "
				<< std::left << std::setw(20) << email << "    Lunch on day DAY @ " << obj.hourToCome
				<< ":00" << " for " << obj.peopleInParty << " people." << std::endl;
		}
		else if (obj.hourToCome >= 17 && obj.hourToCome <= 21) {
			os << "Reservation " << obj.reservationId << ": " << std::setw(10) << std::right << obj.reservationName << "  "
				<< std::left << std::setw(20) << email << "    Dinner on day DAY @ " << obj.hourToCome
				<< ":00" << " for " << obj.peopleInParty << " people." << std::endl;
		}
		else {
			os << "Reservation " << obj.reservationId << ": " << std::setw(10) << std::right << obj.reservationName << "  "
				<< std::left << std::setw(20) << email << "    Drinks on day DAY @ " << obj.hourToCome
				<< ":00" << " for " << obj.peopleInParty << " people." << std::endl;
		}
		return os;
	}
}