#pragma once
#include<iostream>

class Date {
public:
	unsigned int month;
	unsigned int day;
	unsigned int year;
	unsigned int getYear();
	unsigned int getMonth();
	unsigned int getDay();
	void setYear(unsigned int);
	void setMonth(unsigned int);
	void setDay(unsigned int);
	void format(std::ostream&);
	Date(unsigned int year = 1, unsigned int month = 1, unsigned int day = 1);
};