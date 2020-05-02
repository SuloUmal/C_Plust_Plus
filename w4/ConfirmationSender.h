#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__
#include "Reservation.h"
#include "Restaurant.h"
namespace sdds{
  class ConfirmationSender{
   const sdds::Reservation** reserv;
   size_t counter;
   public:
   ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& obj);
		ConfirmationSender& operator=(const ConfirmationSender& obj);
		ConfirmationSender(ConfirmationSender&& obj);
		ConfirmationSender&& operator=(ConfirmationSender&& obj);
		virtual ~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj);
  };
}
#endif