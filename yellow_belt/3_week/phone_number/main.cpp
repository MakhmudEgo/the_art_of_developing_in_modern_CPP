//
// Created by Mahmud Jego on 4/11/21.
//

#include "phone_number.h"
#include <iostream>

int main() {
	PhoneNumber phoneNumber("+7-495-111-22-33");
	std::cout << phoneNumber.GetCountryCode() << '-' << phoneNumber.GetCityCode() << '-' << phoneNumber.GetLocalNumber() << std::endl;
	std::cout << phoneNumber.GetInternationalNumber();
//	PhoneNumber phoneNumber("+74951112233");

}