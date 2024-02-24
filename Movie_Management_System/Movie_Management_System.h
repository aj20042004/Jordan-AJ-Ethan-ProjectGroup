#ifndef MOVIE_MANAGEMENT_SYSTEM_H
#define MOVIE_MANAGEMENT_SYSTEM_H
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Date.h"
#include "Status.h"
#include "Movie.h"

using namespace std;



class Movie_Management_System {

public:
	void display_movies();
	void add_movie(const Movie&);  // adding to the coming list
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

bool Movie_Management_System::isValidDate(const Date& date) {
	return date.isValid();
}


void Movie_Management_System::display_movies() {

	cout << "The Showing Movies: " << endl;
	cout << "-------------------" << endl;

	for (list<Movie>::iterator it = showing_list.begin(); it != showing_list.end(); ++it) {
		cout << it->get_movie_name() << endl;
	}

	cout << " " << endl;
	cout << "The Coming Movies: " << endl;
	cout << "-------------------" << endl;

	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {
		cout << it->get_movie_name() << endl;
	}

}

void Movie_Management_System::add_movie(const Movie& new_movie) {

	if (!isValidDate(new_movie.get_receive_date()) || !isValidDate(new_movie.get_release_date())) {
		cout << "Invalid date !! Cannot be added .. Please check!" << endl;
		return;
	}

	if (new_movie.get_release_date() <= new_movie.get_receive_date()) {
		cout << "Release date cannot be earlier or equal to the receive data !! Try again ..." << endl;
		return;
	}

	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (new_movie.get_movie_name() == it->get_movie_name()) {
			cout << "The Movie already exists in the lists" << endl;
			return;
		}
	}

	cout << "Adding the movie to the list...Please wait!" << endl;

	if (new_movie.get_status() == RECEIVED) {
		coming_list.push_back(new_movie);
	}
	else {
		showing_list.push_back(new_movie);
	}

	cout << "Movie was successfully added to the list. Thank you!!" << endl;

}

void Movie_Management_System::start_showing_movie(const Date& specified_released_date) {

	if (!isValidDate(specified_released_date)) {
		cout << "The release date is invalid... Sorry! Try again" << endl;
		return;
	}

	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		// Checking whether the movie exists in coming list
		if (it->get_release_date() == specified_released_date) {

			// checking whether the movie already exists in showing list
			for (list<Movie>::iterator it_1 = showing_list.begin(); it_1 != showing_list.end(); ++it_1) {
				if (it->get_movie_name() == it_1->get_movie_name()) {
					cout << "The movie already exists in showing list" << endl;
				}
			}

			// checking whether it is a valid date
			if (!isValidDate(specified_released_date)) {
				cout << "The release date is invalid... Sorry! Try again" << endl;
			}

			cout << endl;

			if (it->get_status() == 0) {
				Status status = RELEASED;
				it->set_status(status);
			}

			showing_list.push_back(*it);
			coming_list.erase(it);
			return;

		}
	}

	cout << "Cannot find any movies that matches the specified date!! Try again ..." << endl;
}


void Movie_Management_System::edit_coming_movie_releaseDate(const string& movie_name_to_edit, const Date& new_release_date) {

	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (it->get_movie_name() == movie_name_to_edit) {

			if (new_release_date <= it->get_receive_date()) {
				cout << "New Release date cannot be earlier or equal to the receive data !! Try again ..." << endl;
				return;
			}

			if (!isValidDate(new_release_date)) {
				cout << "The release date is invalid... Sorry! Try again" << endl;
				return;
			}

			list<Movie>::iterator insertion_place;

			for (insertion_place = coming_list.begin(); insertion_place != coming_list.end(); ++insertion_place) {

				if (insertion_place->get_release_date() > new_release_date) {
					
					coming_list.insert(insertion_place, *it);
					insertion_place--;
					insertion_place->set_release_date(new_release_date);
					coming_list.erase(it);
					break;

				}

			};

			if (insertion_place == coming_list.end()) {
				
				coming_list.insert(insertion_place, *it);
				insertion_place--;
				insertion_place->set_release_date(new_release_date);
				coming_list.erase(it);
			}

			
			cout << "Movie information was successfully edited!! Thank you.." << endl;
			return;
		}
	}

	cout << "Sorry! The movie does not exists in the coming lists" << endl;
}



void Movie_Management_System::edit_coming_movie_description(const string& movie_name_to_edit, const string& new_description) {

	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (it->get_movie_name() == movie_name_to_edit) {

			it->set_description(new_description);
			cout << "Movie information was successfully edited!! Thank you.." << endl;
			return;
		}
	}

	cout << "Sorry! The movie does not exists in the coming lists" << endl;
}



int Movie_Management_System::count_coming_movies_before_date(const Date& specified_date) {

	int count = 0;

	if (!isValidDate(specified_date)) {

		cout << "The release date is invalid... Sorry! Try again" << endl;
		return count;
	}

	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (it->get_release_date() < specified_date) {
			count += 1;
		}
	}

	return count;

}

void Movie_Management_System::save_to_file(const string& output_file_name) {

	ofstream output_file(output_file_name);

	if (!output_file) {
		cout << "Sorry! Error in opening file.." << endl;
		return;
	}

	output_file << "The Showing Movies: " << endl;
	output_file << " " << endl;

	// showing movies
	for (list<Movie>::iterator it = showing_list.begin(); it != showing_list.end(); ++it) {

		output_file << it->get_movie_name() << ", " << it->get_release_date().get_month() << "/" << it->get_release_date().get_day_of_month()
			<< "/" << it->get_release_date().get_year() << ", " << it->get_description() << ", " << it->get_receive_date().get_month()
			<< "/" << it->get_receive_date().get_day_of_month() << "/" << it->get_receive_date().get_year() << ", ";

		if (it->get_status() == 0) {
			output_file << "received" << endl;
		}
		else {
			output_file << "released" << endl;
		}


	}

	output_file << " " << endl;

	output_file << "The Coming Movies: " << endl;

	output_file << " " << endl;

	// Coming movies
	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		output_file << it->get_movie_name() << ", " << it->get_release_date().get_month() << "/" << it->get_release_date().get_day_of_month()
			<< "/" << it->get_release_date().get_year() << ", " << it->get_description() << ", " << it->get_receive_date().get_month()
			<< "/" << it->get_receive_date().get_day_of_month() << "/" << it->get_receive_date().get_year() << ", ";

		if (it->get_status() == 0) {
			output_file << "received" << endl;
		}
		else {
			output_file << "released" << endl;
		}
	}

	output_file << " " << endl;

	output_file.close();

	cout << "successfully saved the data to the file " << output_file_name << endl;
	cout << endl;
}

void Movie_Management_System::load_from_file(const string& input_file_name) {

	string read_line;
	ifstream input_file(input_file_name);

	if (!input_file) {
		cout << "Sorry! Cannot open the file" << endl;
		return;
	}

	while (getline(input_file, read_line)) {

		stringstream read_string(read_line);
		string name_str, release_date_str, description_str, receive_date_str, status_str;
		Status status;
		Date obj_release_date;
		Date obj_receive_date;

		getline(read_string >> ws, name_str, ',');
		getline(read_string >> ws, release_date_str, ',');
		getline(read_string >> ws, description_str, ',');
		getline(read_string >> ws, receive_date_str, ',');
		getline(read_string >> ws, status_str, ',');

		// Changing the string format of status to enum
		if (status_str == "released") {
			status = RELEASED;
		}
		else {
			status = RECEIVED;
		}

		if (obj_release_date.parse_from_string(release_date_str)) {
			// Successfully loaded the release date
		}
		else {
			cout << "Error in parsing the release date" << endl;
			continue;
		}


		if (obj_receive_date.parse_from_string(receive_date_str)) {
			// "Successfully loaded the receive date"
		}
		else {
			cout << "Error in parsing the release date" << endl;
			continue;
		}

		Movie obj_movie(name_str, obj_release_date, description_str, obj_receive_date, status);


		if (status == RECEIVED) {

			if (coming_list.empty()) {
				coming_list.push_back(obj_movie);
				continue;
			}

			list<Movie>::iterator insertion_place = std::find_if(coming_list.begin(), coming_list.end(), [&](const Movie& current) {
				return current.get_release_date() > obj_release_date;
				});

			if (insertion_place == coming_list.end()) {
				coming_list.push_back(obj_movie);
			}
			else {
				coming_list.insert(insertion_place, obj_movie);
			}

		}



		else {

			if (showing_list.empty()) {
				showing_list.push_back(obj_movie);
				continue;
			}

			list<Movie>::iterator insertion_place = find_if(showing_list.begin(), showing_list.end(), [&](const Movie& current) {
				return current.get_release_date() > obj_release_date;
				});

			if (insertion_place == showing_list.end()) {
				showing_list.push_back(obj_movie);
			}
			else {
				showing_list.insert(insertion_place, obj_movie);
			}

		}

	}

	input_file.close();
	cout << " " << endl;
	// Successfully loaded all the data

}


#endif
