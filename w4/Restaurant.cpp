#include <iostream>
#include <cstddef>
#include "Restaurant.h"
#include "Reservation.h"
namespace sdds{
Restaurant::Restaurant(){
reserv = nullptr;
count = 0;
}
Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
if(cnt > 0 && reserv != nullptr){
  reserv = new Reservation[cnt];
  for (int i = 0; i < cnt; i++) reserv[i] = *reservations[i];
  count = cnt;
}
}
Restaurant::Restaurant(const Restaurant& obj){
*this = obj;
}
Restaurant& Restaurant::operator=(const Restaurant& obj){
if (this != &obj)
		{
      count = obj.count;
	  if (obj.reserv != nullptr) {
		  reserv = new Reservation[count];
		  for (int i = 0; i < count; i++) {
			  reserv[i] = obj.reserv[i];
		  }
	  }
	  else reserv = nullptr;
	  }
		return *this;

}
Restaurant::Restaurant(Restaurant&& obj){
*this = std::move(obj);
}
Restaurant& Restaurant::operator=(Restaurant&& obj){
	if (this != &obj) {
		reserv = obj.reserv;
		count = obj.count;
		obj.reserv = nullptr;
		obj.count = 0;
	}
	return *this;	
}
Restaurant::~Restaurant(){
  delete[] reserv;
  reserv = nullptr;
}
std::ostream& operator<<(std::ostream& os, const Restaurant& obj){
os << "-----------------------" << std::endl;
os << "Fancy Resturnat" << std::endl;
os << "-----------------------" << std::endl;
  if (obj.count != 0 && obj.reserv != nullptr){
    for (int i = 0; i < obj.count; i++){
      os << obj.reserv[i]; } 
      } else {
      os << "This object is empty!" << std::endl;
    }
  os << "-----------------------" << std::endl;
    return os;
  }
size_t Restaurant::size() const{
return count;
}
}
