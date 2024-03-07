#ifndef MOVIE_H
#define MOVIE_H

// Importing the modules
#include <iostream>
#include "Date.h"
#include "Status.h"

using namespace std;

// Creating the movie class
class Movie {

public:
	// Constructor
	Movie(const string&, const Date&, const string&, const Date&, Status);  // Constructor with values of "movie_name" , "release_date", "description", "receive_date", "status".

	// Getters
	string get_movie_name() const;   // returns the movie name
	Date get_release_date() const;   // returns the release date 
	string get_description() const;  // returns the description of the movie 
	Date get_receive_date() const;   // returns the receive date
	Status get_status() const;       // returns the status of the movie

	// Setters
	void set_movie_name(string);     // Updates the movie name
	void set_release_date(Date);     // Updates the release date
	void set_description(string);    // Updates the description of the movie
	void set_receive_date(Date);     // Updates the receive date
	void set_status(Status);         // Updates the status of the movie

private:
	// Data fields
	string movie_name;   // Stores the movie name
	Date release_date;   // Stores the release date
	string description;  // stores the description
	Date receive_date;   // stores the receive date
	Status status;       // stores the status of the movie
}; 


#endif