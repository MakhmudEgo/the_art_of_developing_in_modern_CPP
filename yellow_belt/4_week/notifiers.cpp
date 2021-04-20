//
// Created by Mahmud Jego on 4/20/21.
//

#include <iostream>

class INotifier {
public:
	virtual void Notify(const std::string& message) = 0;
};

class SmsNotifier : public INotifier {
public:
	SmsNotifier(const std::string& number) : _number(number) {}

	void Notify(const std::string &message) override {
		SendSms(_number, message);
	}
private:
	void SendSms(const std::string& number, const std::string& message) {
		std::cout << "Send '" << message << "' to number " << number << std::endl;
	}
	const std::string _number;
};

class EmailNotifier : public INotifier {
public:
	EmailNotifier(const std::string& email) : _email(email) {}
	void Notify(const std::string &message) override {
		SendEmail(_email, message);
	}

private:
	void SendEmail(const std::string& email, const std::string& message) {
		std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
	}
	const std::string _email;
};

int main() {
	SmsNotifier sms{"+7-495-777-77-77"};
	EmailNotifier email{"na-derevnyu@dedushke.ru"};

	sms.Notify("I have White belt in C++");
	email.Notify("And want a Yellow one");
	return 0;
}