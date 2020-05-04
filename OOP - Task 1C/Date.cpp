
#include "Date.h"
#include <iomanip>

Date::Date()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	this->day = ltm->tm_mday;
	this->month = ltm->tm_mon + 1;
	this->year = ltm->tm_year + 1900;
}

Date::Date(int day, int month, int year)
{
	if (checkDate(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
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
	os <<std::setfill('0')<< std::setw(4)<<year;
	os << "-";
	os << std::setfill('0') << std::setw(2) << month;
	os << "-";
	os << std::setfill('0') << std::setw(2) << day;

	return os.str();
}

bool Date::checkDate(const int& day, const int& month, const int& year) const {
	if (month > 0 && month <= 12 && day > 0 && year > 1950 && year < 9999) {
		switch (month) {
		case 9:
		case 4:
		case 6:
		case 11:
			if (day > 30)
				return false;
			break;
		case 2:
			if (day > 29)
				return false;
			break;
		default:
			break;
		}
		return true;
	}
	return false;
}

bool Date::operator< (const Date& d2) const {
	return ((d2.getYear() > year) || 
		(d2.getYear() == year && d2.getMonth() > month) || 
		(d2.getYear() == year && d2.getMonth() == month && d2.getDay() > day) ||
		d2.getYear() == year && d2.getMonth() == month && d2.getDay() == day);
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
