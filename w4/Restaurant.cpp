#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {

	Restaurant::Restaurant(Reservation* reservations[], std::size_t cnt) {
		arr = new Reservation [cnt];
		this->arr_size = 0;
		this->arr_size = static_cast<int>(cnt);
		for (int i = 0; i < arr_size; i++) {
			arr[i]=*reservations[i];
		}
		
	}

	std::size_t Restaurant::size() const {
		return this->arr_size;
	}

	ostream& operator<<(ostream& os, Restaurant& res){
		os << "--------------------------" << endl;
		os<< "Fancy Restaurant" << endl;
		os	<< "--------------------------" << endl;
		if (res.arr_size == 0) {
			os << "The object is empty!" << endl;
		}
		else {
			for (int i = 0; i < res.arr_size; i++)
				os << res.arr[i];
		}
		os << "--------------------------" << endl;
		return os;
	}

	Restaurant::Restaurant(Restaurant&& r) {
		arr_size = 0;
		arr = nullptr;
		arr_size = r.arr_size;
		//if (arr != nullptr)
		//delete[]arr;
		arr = new Reservation[arr_size];
		for (int i = 0; i < arr_size; i++) {
			arr[i] = r.arr[i];
		}

		r.arr_size = 0;
		delete[] r.arr;
		r.arr = nullptr;
	}

	Restaurant::Restaurant(const Restaurant& r) {
		arr_size = 0;
		arr = nullptr;
		arr_size = r.arr_size;
		if(arr!=nullptr)
		delete[] arr;
		arr = nullptr;
		arr = new Reservation[arr_size];
		for (int i = 0; i < arr_size; i++) {
			arr[i] = r.arr[i];
		}
	}

}
