
// Importing the header files
#include "Date.h"
#include "Status.h"
#include "Movie.h"


// Constructor for the movie class

// Constructor with values of "movie_name" , "release_date", "description", "receive_date", "status".
Movie::Movie(const string& movie_name_1, const Date& release_date_1, const string& description_1, const Date& receive_date_1, Status status_1) {
	movie_name = movie_name_1;
	release_date = release_date_1;
	description = description_1;
	receive_date = receive_date_1;
	status = status_1;
}

// Getters

/** Returns the name of the movie
	@return: name of the movie
*/
string Movie::get_movie_name() const {
	return movie_name;
}

/** Returns the release date of the movie
	@return: release date of the movie
*/
Date Movie::get_release_date() const {
	return release_date;
}

/** Returns the description of the movie
	@return: description of the movie
*/
string Movie::get_description() const {
	return description;
}

/** Returns the receive date of the movie
	@return: receive date of the movie
*/
Date Movie::get_receive_date() const {
	return receive_date;
}

/** Returns the status of the movie
	@return: status of the movie
*/
Status Movie::get_status() const {
	return status;
}


// Setters

/** Updates the name of the movie
	@param new_movie_name: updated name of the movie
*/
void Movie::set_movie_name(string new_movie_name) {

	movie_name = new_movie_name;
}

/** Updates the release date of the movie
	@param new_release_date: updated release date of the movie
*/
void Movie::set_release_date(Date new_release_date) {

	release_date = new_release_date;
}

/** Updates the description of the movie
	@param new_description: updated description of the movie
*/
void Movie::set_description(string new_description) {

	description = new_description;
}

/** Updates the receive date of the movie
	@param new_recieve_date: updated receive date of the movie
*/
void Movie::set_receive_date(Date new_receive_date) {

	receive_date = new_receive_date;
}

/** Updates the status of the movie
	@param new_status: updated status of the movie
*/
void Movie::set_status(Status new_status) {

	status = new_status;
}