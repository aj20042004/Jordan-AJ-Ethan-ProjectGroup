#pragma once
#include "date.h"
#include "status.h"
#include <ostream>

class Movie {
public:
	std::string name;
	Date& releaseDate;
	std::string description;
	Date& receiveDate;
	Status status;
	void format(std::ostream&);
	Movie(std::string name, Date& releaseDate, std::string description, Date& receiveDate, Status status);
};