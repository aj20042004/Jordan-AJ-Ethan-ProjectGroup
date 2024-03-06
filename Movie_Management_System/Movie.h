#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include "Date.h"
#include "Status.h"

using namespace std;

class Movie {

public:
	// Constructor
	Movie(const string&, const Date&, const string&, const Date&, Status);

	// Getters
	string get_movie_name() const;
	Date get_release_date() const;
	string get_description() const;
	Date get_receive_date() const;
	Status get_status() const;

	// Setters
	void set_movie_name(string);
	void set_release_date(Date);
	void set_description(string);
	void set_receive_date(Date);
	void set_status(Status);

private:
	string movie_name;
	Date release_date;
	string description;
	Date receive_date;
	Status status;
};


#endif