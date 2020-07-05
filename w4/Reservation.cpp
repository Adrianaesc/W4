#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

using namespace std;
namespace sdds {

	Reservation::Reservation() {
		resId=nullptr;
		name="";
		email="";
		numOfPeople=0;
		dayOfMonth=0;
		hour=0;
	}

	Reservation::Reservation(const string& res) {
		resId = nullptr;
		name = "";
		email = "";
		numOfPeople = 0;
		dayOfMonth = 0;
		hour = 0;

		string resTemp = "";
			resTemp=res;
		char delim = ',';

		resTemp.erase(remove(resTemp.begin(), resTemp.end(), ' '), resTemp.end());


		size_t place = resTemp.find(":");
		resId = new char[place+2];

		string temp = resTemp.substr(0,place+1);
		strcpy(resId, temp.c_str());
		temp = "";
		resTemp.erase(0,place+1);

		size_t newPlace = resTemp.find(delim);
		name = resTemp.substr(0, newPlace);
		resTemp.erase(0, newPlace + 1);

		place = resTemp.find(delim);
		email = resTemp.substr(0, place);
		resTemp.erase(0, place + 1);

		newPlace = resTemp.find(delim);
		numOfPeople = stoi(resTemp.substr(0, newPlace));
		resTemp.erase(0, newPlace + 1);

		place = resTemp.find(delim);
		dayOfMonth = stoi(resTemp.substr(0, place));
		resTemp.erase(0, place + 1);


		newPlace = resTemp.find(delim);
		hour = stoi(resTemp.substr(0, newPlace));
		resTemp.erase(0, place + 1);

	}


	ostream& operator<<(ostream& os, Reservation& res) {
		if (res.resId != nullptr) {
			//os<< "print"<<endl;
			os << "Reservation " << res.resId<<" "
				<< setfill(' ') << setw(10) << right << res.name
				<< "  " << "<" << setfill(' ') << setw(20) << left << res.email + ">";

			if (res.hour >= 6 && res.hour <= 9) {
				//6AM-9AM
				os << "   Breakfast";
			}
			else if (res.hour >= 11 && res.hour <= 15) {
				//11AM-3PM
				os << "   Lunch";
			}
			else if (res.hour >= 17 && res.hour <= 21) {
				//5PM-9PM
				os << "   Dinner";
			}
			else {
				os << "   Drinks";
			}
			os << " on day " << res.dayOfMonth << " @ " << res.hour << ":00 for " << res.numOfPeople << " people." << endl;

		}
		return os;

	}

	Reservation::~Reservation() {
		if(resId!=nullptr)
		delete [] resId;
	}

	Reservation& Reservation::operator=(const Reservation& re) {
		if (re.resId != this->resId) {
			if (this->resId == nullptr) {
				int length=strlen(re.resId);
				//delete[] resId;
				//resId = nullptr;
				resId = new char[length+1];
				strcpy(this->resId, re.resId);
				name = "";
				email = "";

				name = re.name;
				email = re.email;
				numOfPeople = re.numOfPeople;
				dayOfMonth = re.dayOfMonth;
				hour = re.hour;
			}
		}
		return *this;
	}


}