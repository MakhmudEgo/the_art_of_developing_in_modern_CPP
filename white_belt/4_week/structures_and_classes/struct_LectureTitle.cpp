//
// Created by Mahmud Jego on 1/7/21.
//

#include <iostream>

struct Specialization {
	std::string szSrc;
	explicit Specialization(const std::string& szNewSrc)
	{
		szSrc = szNewSrc;
	}
};

struct Course {
	std::string szSrc;
	explicit Course(const std::string& szNewSrc)
	{
		szSrc = szNewSrc;
	}
};

struct Week {
	std::string szSrc;
	explicit Week(const std::string& szNewSrc)
	{
		szSrc = szNewSrc;
	}
};

struct LectureTitle {
	LectureTitle(const Specialization& newSpec, const Course& newCourse, const Week& newWeek)
	{
		specialization = newSpec.szSrc;
		course = newCourse.szSrc;
		week = newWeek.szSrc;
	}
	std::string specialization;
	std::string course;
	std::string week;
};

int main()
{
	LectureTitle title(
			Specialization("C++"),
			Course("White belt"),
			Week("4th")
	);

	// no valid
	/*LectureTitle title1("C++", "White belt", "4th");

	LectureTitle title2(std::string("C++"), std::string("White belt"), std::string("4th"));

	LectureTitle title3 = {"C++", "White belt", "4th"};

	LectureTitle title4 = {{"C++"}, {"White belt"}, {"4th"}};

	LectureTitle title5(
			Course("White belt"),
			Specialization("C++"),
			Week("4th")
	);

	LectureTitle title6(
			Specialization("C++"),
			Week("4th"),
			Course("White belt")
	);*/
}
