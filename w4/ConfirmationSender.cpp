#include <iostream>
#include <string>
#include "Reservation.h"
#include "ConfirmationSender.h"
#include <iomanip> 
namespace sdds{
  ConfirmationSender::ConfirmationSender(){
reserv = nullptr;
counter = 0;
  }
		ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj){
      *this = obj;
    }
		ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& obj){
      if (this != &obj){
        counter = obj.counter;
		if (obj.reserv != nullptr) {
			reserv = new const Reservation*[counter];
			for (int i = 0; i < obj.counter; i++) {
				reserv[i] = obj.reserv[i];
			}
		}
		else {
			reserv = nullptr;
		}
      }
	  return *this;
    }
		ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj){
      *this = std::move(obj);
    }
		ConfirmationSender&& ConfirmationSender::operator=(ConfirmationSender&& obj){
      if(this != &obj){
        reserv = obj.reserv;
        counter = obj.counter;
        obj.reserv = nullptr;
        obj.counter = 0;
      }
      return std::move(*this);
    }
		ConfirmationSender::~ConfirmationSender(){
      delete[] reserv;
      reserv = nullptr;
    }
		ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
      bool exist = false;
      for (int i = 0 ; i < counter; i++){
        if(reserv[i] == &res) exist = 1;
      }
      if (!(exist)) {
        const Reservation** newReserv = nullptr;
        newReserv = new const Reservation*[counter + 1];
		if (counter != 0) {
			for (int i = 0; i < counter; i++) {
				newReserv[i] = reserv[i];
			}
		}
        newReserv[counter] = &res;
		counter++;
        delete[] reserv;
        reserv = newReserv;
      }
      return *this;
    }
		ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
      for (int i = 0 ; i < counter; i++){
      if(&res == reserv[i]){
        counter--;
        const Reservation** newReserv = nullptr;
        newReserv = new const Reservation*[counter];
        for(int j = 0; j < counter; j++){
          if (i == j) j++;
          newReserv[j] = reserv[j];
        }
      }
    } return *this;
    }
		std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj){
	if (obj.reserv == nullptr) {
			os << "--------------------------" << std::endl;
			os << "Confirmations to Send" << std::endl;
			os << "--------------------------" << std::endl;
			os << "The object is empty!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		else {
			os << "--------------------------" << std::endl;
			os << "Confirmations to Send" << std::endl;
			os << "--------------------------" << std::endl;
			for (size_t i = 0; i < obj.counter; i++) {
				os << *obj.reserv[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
    }
}