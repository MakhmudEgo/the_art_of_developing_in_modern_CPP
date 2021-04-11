//
// Created by Mahmud Jego on 4/11/21.
//

#include "phone_number.h"
#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number) {
	std::stringstream ss;
	ss << international_number;
	char c;

	ss >> c;
	if (c != '+') {
		throw std::invalid_argument("no start with '+'");
	}
	std::getline(ss, this->country_code_, '-');
	if (ss.eof() || country_code_.empty()) {
		throw std::invalid_argument("not find city code");
	}
	std::getline(ss, this->city_code_, '-');
	if (ss.eof() || this->city_code_.empty()) {
		throw std::invalid_argument("not find local number");
	}
	ss >> this->local_number_;
}

string PhoneNumber::GetCountryCode() const {
	return this->country_code_;
}

string PhoneNumber::GetCityCode() const {
	return this->city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return this->local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return '+' + this->country_code_ + '-' + this->city_code_ + '-' +this->local_number_;
}
