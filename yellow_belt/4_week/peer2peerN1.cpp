//
// Created by Mahmud Jego on 4/21/21.
//

#include <iostream>
#include <string>
#include <vector>

class Person {
public:
	Person(const std::string& name, const std::string& typePerson)
			: Name(name), TypePerson(typePerson) {}

	virtual void Walk(const std::string& destination) const {
		Doing(" walks to: " + destination );
	};

	void Doing(const std::string& target) const {
		std::cout << TypePerson << ": " << Name << target << std::endl;
	}

	const std::string Name, TypePerson;
};

class Student : public Person {
public:
	Student(const std::string& name, const std::string& favouriteSong)
			: Person(name, "Student"), FavouriteSong(favouriteSong){
	}

	void Learn() const {
		Doing(" learns");
	}

	void Walk(const std::string& destination) const {
		Doing(" walks to: " + destination);
		Doing(" sings a song: " + FavouriteSong);
	}

	void SingSong() const {
		Doing(" sings a song: " + FavouriteSong);
	}

private:
	const std::string FavouriteSong;
};


class Teacher : public Person {
public:

	Teacher(const std::string& name, const std::string& subject)
			: Person(name, "Teacher"), Subject(subject) {}

	void Teach() const {
		Doing(" teaches: " + Subject);
	}

private:
	const std::string Subject;
};


class Policeman : public Person {
public:
	Policeman(const std::string& name) : Person(name, "Policeman") {}

	void Check(const Person& p) const {
		Doing(" checks Teacher. Teacher's name is: " + p.Name);
	}
};


void VisitPlaces(const Person& p, const std::vector<std::string>& places) {
	for (const auto& place : places) {
		p.Walk(place);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, {"Moscow", "London"});
	p.Check(s);
	VisitPlaces(s, {"Moscow", "London"});
	return 0;
}
