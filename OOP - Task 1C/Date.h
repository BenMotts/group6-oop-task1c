#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <sstream>
class Date
{
private:
	int day, month, year;
	bool checkDate(const int&, const int&, const int&) const;
public:
	Date(int, int, int);
	Date();
	~Date();
	const static Date CurrentDate();
	bool setDate(const int&, const int&, const int&);
	std::string printDate() const;
	bool operator < (const Date&) const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
};

