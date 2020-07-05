#include <iostream>
#include "ConfirmationSender.h"


using namespace std;
namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		arr = new Reservation*[5];
		for (int i = 0; i < 5; i++)
			arr[i] = nullptr;
		amount = 0;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool n = false;
		if (arr != nullptr) {
			for (int i = 0; i < amount; i++) {
				if (arr[i]==&res) {
					n = true;
				}
			}
			if (n == false) {
				for (int i = 0; i <= amount; i++) {
					if (arr[i] == nullptr) {
						arr[i] =(Reservation*)&res;
						amount++;
						n = false;
						break;
					}
					else { n = true; }
				}
					if (n == true) {
						Reservation** temp = new Reservation * [amount + 1];
						for (int i = 0; i < amount+1; i++)
							temp[i]=arr[i];
						delete[] arr;
						arr = nullptr;

						arr = new Reservation * [amount + 1];
						for (int i = 0; i < amount+1; i++)
							arr[i]=temp[i];

						delete[]temp;
						temp = nullptr;

						for (int i = 0; i < amount+1; i++) {
							if (arr[i] == nullptr) {
								arr[i] = (Reservation*)&res;
								amount++;
								break;
							}
						}

					}
				
			}

		}
		
		return *this;

	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		if (arr != nullptr) {
			for (int i = 0; i < amount; i++) {
				if (arr[i] == &res) {
					arr[i] = nullptr;
					--amount;
				}
			}
		}
		return *this;
	}

	ostream& operator<<(ostream& os, ConfirmationSender& res) {
		os << "--------------------------" << endl;
		os	<< "Confirmations to Send" << endl;
		os	<< "--------------------------" << endl;

		if (res.amount == 0) {
			os << "The object is empty!" << endl;
		}
		else {
			for (int i = 0; i < res.amount; i++) {
				os<<*res.arr[i];
			}
		}
		os << "--------------------------" << endl;
		return os;

	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& r){
		arr = nullptr;
		amount = 0;
			arr = r.arr;
			amount = r.amount;

			//delete r.arr;
			r.arr = nullptr;
			r.amount = 0;
		
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& r) {
		arr = nullptr;
		amount = 0;
		arr = r.arr;
		amount = r.amount;
	}
	

}