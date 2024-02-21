#include "date.h"
#include <iomanip>

unsigned int Date::getYear() {
	return year;
}

unsigned int Date::getMonth() {
	return month;
}

unsigned int Date::getDay() {
	return day;
}

void Date::setYear(unsigned int year) {
	this->year = year;
}

void Date::setMonth(unsigned int month) {
	// Month must be between 1 and 12 inclusive.
	if (month < 1 && month > 12) throw "Month must be between 1 and 12 inclusive.";
	this->month = month;
}

void Date::setDay(unsigned int day) {
	if (day < 1) throw "Day must be at least 1.";
	switch (month) {
	case 2:
		// Febuary has 29 days on leap years otherwise 28.
		// Leap years occur every 4 years unless the year is evenly divisible by 100 but not if by 400.
		// e.g., 2000 is a leap year but 2100 is not.
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29) throw "Day must be no more than 30.";
			this->day = day;
		}
		else {
			if (day > 28) throw "Day must be no more than 29.";
			this->day = day;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		// April, June, September, and November have 30 days.
		if (day > 30) throw "Day must be no more than 30.";
		this->day = day;
		break;
	default:
		// January, March, May, July, August, October, and December have 31 days.
		if (day > 31) throw "Day must be no more than 31.";
		this->day = day;
	}
}

void Date::format(std::ostream& out) {
	out << std::setw(2) << std::setfill('0') << month << '/' << std::setw(2) << std::setfill('0') << day << '/' << std::setw(4) << std::setfill('0') << year;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	setYear(year);
	setMonth(month);
	setDay(day);
}