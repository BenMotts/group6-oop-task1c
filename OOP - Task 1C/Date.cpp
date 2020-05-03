
#include "Date.h"


Date::Date()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	this->day = ltm->tm_mday;
	this->month = ltm->tm_mon + 1;
	this->year = ltm->tm_year + 1900;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::~Date()
{
}

const Date Date::CurrentDate() {
	return Date();
}

bool Date::setDate(const int& day, const int& month, const int& year) {
	if (checkDate(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
		return true;
	}
	return false;
}

std::string Date::printDate() const {
	std::ostringstream os;
	os << day;
	os << " - ";
	os << month;
	os << " - ";
	os << year;
	return os.str();
}

bool Date::checkDate(const int& day, const int& month, const int& year) const {
	return (day > 0 && day < 32 && month > 0 && month < 13);
}

bool Date::operator< (const Date& d2) const {
	return ((d2.getYear() > year) || 
		(d2.getYear() == year && d2.getMonth() > month) || 
		(d2.getYear() == year && d2.getMonth() == month && d2.getDay() > day));
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}
