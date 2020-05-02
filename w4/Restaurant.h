#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__
#include <iostream>
#include <cstddef>
#include "Reservation.h"
namespace sdds{
class Restaurant{
Reservation* reserv;
size_t count;
public:
Restaurant();
Restaurant(Reservation* reservations[], size_t cnt);
Restaurant(const Restaurant& obj);
Restaurant& operator=(const Restaurant& obj);
Restaurant(Restaurant&& obj);
Restaurant& operator=(Restaurant&& obj);
virtual ~Restaurant();
size_t size() const;
friend std::ostream& operator<<(std::ostream& os, const Restaurant& obj);
};
}
#endif