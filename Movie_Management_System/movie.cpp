#include "Date.h"
#include "Status.h"
#include "Movie.h"

Movie::Movie(const string& movie_name_1, const Date& release_date_1, const string& description_1, const Date& receive_date_1, Status status_1) {
	movie_name = movie_name_1;
	release_date = release_date_1;
	description = description_1;
	receive_date = receive_date_1;
	status = status_1;
}

string Movie::get_movie_name() const {
	return movie_name;
}

Date Movie::get_release_date() const {
	return release_date;
}

string Movie::get_description() const {
	return description;
}

Date Movie::get_receive_date() const {
	return receive_date;
}

Status Movie::get_status() const {
	return status;
}


void Movie::set_movie_name(string new_movie_name) {

	movie_name = new_movie_name;
}

void Movie::set_release_date(Date new_release_date) {

	release_date = new_release_date;
}

void Movie::set_description(string new_description) {

	description = new_description;
}

void Movie::set_receive_date(Date new_receive_date) {

	receive_date = new_receive_date;
}

void Movie::set_status(Status new_status) {

	status = new_status;
}