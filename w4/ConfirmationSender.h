#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
#include <iostream>

using namespace std;
namespace sdds{

	class ConfirmationSender {

		sdds::Reservation** arr;
		int amount;

	public:

		ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender (ConfirmationSender&& r);
		ConfirmationSender(const ConfirmationSender& r);

		friend ostream& operator<<(ostream& os, ConfirmationSender& res);

	};
}

#endif