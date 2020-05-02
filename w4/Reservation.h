#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__
#include <iostream>
#include <cstddef>
namespace sdds{
class Reservation{
  std::string reservationId;
  std::string reservationName;
  std::string email;
  size_t peopleInParty;
  size_t dayToCome;
  size_t hourToCome;
  public:
  Reservation();
  Reservation(const std::string& m_res);
friend std::ostream& operator<<(std::ostream& os, const Reservation& obj);
};
}
#endif