#ifndef MOVIE_MANAGEMENT_SYSTEM_H
#define MOVIE_MANAGEMENT_SYSTEM_H

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

class Movie_Management_System {

public:
	void display_movies();
	void add_movie(const Movie&);  
	void start_showing_movie(const Date&);
	void edit_coming_movie_releaseDate(const string&, const Date&);
	void edit_coming_movie_description(const string&, const string&);
	int  count_coming_movies_before_date(const Date&);
	void save_to_file(const string&);
	void load_from_file(const string&);

private:
	list<Movie> showing_list;
	list<Movie> coming_list;

	bool isValidDate(const Date& date);

};

#endif