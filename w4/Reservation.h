#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>

using namespace std;
namespace sdds{

	class Reservation {

		char* resId;
		string name;
		string email;
		int numOfPeople;
		int dayOfMonth;
		int hour;

	public:
		Reservation();
		Reservation(const std::string& res);
		Reservation& operator=(const Reservation& re);
		~Reservation();

		friend ostream& operator<<(ostream& os, Reservation& res);

	};

}

#endif