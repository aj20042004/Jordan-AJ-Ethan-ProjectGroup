#ifndef MOVIE_MANAGEMENT_SYSTEM_H
#define MOVIE_MANAGEMENT_SYSTEM_H

// Importing the modules
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "Date.h"
#include "Status.h"
#include "Movie.h"

using namespace std;

// Creating the class
class Movie_Management_System {

public:

	// Class-member functions

	// Displaying the movies of both showing and coming list
	void display_movies();

	// Adding the movie to the coming list
	void add_movie(const Movie&);  

	// Moving the movies from coming list to showing list
	void start_showing_movie(const Date&);

	// Editing the movie's release date from the coming list
	void edit_coming_movie_releaseDate(const string&, const Date&);

	// Editing the movie's description from the coming list
	void edit_coming_movie_description(const string&, const string&);

	// Counting the movies in coming list
	int  count_coming_movies_before_date(const Date&);

	// Saving the data in the output file
	void save_to_file(const string&);

	// Loading the data from the input file
	void load_from_file(const string&);

	// checking whether the movie exists in coming list or not
	bool check_movie_in_showinglist(const string&);

private:
	// Data fields
	list<Movie> showing_list;  // Stores the movies in the showing list
	list<Movie> coming_list;   // Stores the movies in the coming list

	bool isValidDate(const Date& date);  // Validates the date

};

#endif