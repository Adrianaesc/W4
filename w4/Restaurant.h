#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <string.h>
#include "Reservation.h"
using namespace std;
namespace sdds {

	class Restaurant {
		Reservation* arr;
	
	public:
		Restaurant(Reservation* reservations[], std::size_t cnt);
		int arr_size;
		std::size_t size() const;
		Restaurant(Restaurant&& r);
		Restaurant(const Restaurant& r);
		friend ostream& operator<<(ostream& os, Restaurant& res);

	};
}


#endif