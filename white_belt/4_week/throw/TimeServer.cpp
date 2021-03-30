//
// Created by Mahmud Jego on 3/30/21.
//
#include <iostream>

/*std::string AskTimeServer()
{
	throw std::system_error(std::error_code());
}*/

class TimeServer {
public:
	std::string GetCurrentTime() {
		try {
			std::string currTime = AskTimeServer();
			this->last_fetched_time = currTime;
		} catch (std::system_error& e) {
		}
		return (this->last_fetched_time);
	}

private:
	std::string last_fetched_time = "00:00:00";
};

/*
int main() {
	TimeServer server;

	try {
		std::cout << server.GetCurrentTime() << std::endl;
	} catch (std::system_error& e) {
		std::cerr << e.what() << std::endl;
	}
}*/
