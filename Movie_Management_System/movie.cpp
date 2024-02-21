#include "movie.h"
#include "date.h"
#include <ostream>

void Movie::format(std::ostream& out) {
	out << name << ", ";
	releaseDate.format(out);
	out << ", " << description << ", ";
	receiveDate.format(out);
	out << ", ";
	if (status == Status::RELEASED) out << "Released";
	else if (status == Status::RECEIVED) out << "Received";
	else throw "status is not Status::RELEASED or Status::RECEIVED.";
}

Movie::Movie(std::string name, Date& releaseDate, std::string description, Date& receiveDate, Status status) : releaseDate(releaseDate), receiveDate(receiveDate) {
	this->name = name;
	this->description = description;
	this->status = status;
}