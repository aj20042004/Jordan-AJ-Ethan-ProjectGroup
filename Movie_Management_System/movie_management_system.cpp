
// Importing the header files
#include "Movie_Management_System.h"
#include "Date.h"
#include "Status.h"
#include "Movie.h"


/** Checks whether the date is valid or not.
	@param date: a date to validate
	@return: {true} if the date is valid; {false} otherwise
*/
bool Movie_Management_System::isValidDate(const Date& date) {
	return date.isValid();
}

// Function to display movies from coming and showing list
void Movie_Management_System::display_movies() {

	cout << "The Showing Movies: " << endl;
	cout << "-------------------" << endl;

	// Iterating through the showing list to display movies
	for (list<Movie>::iterator it = showing_list.begin(); it != showing_list.end(); ++it) {
		cout << it->get_movie_name() << endl;
	}

	cout << " " << endl;
	cout << "The Coming Movies: " << endl;
	cout << "-------------------" << endl;

	// Iterating through the coming list to display movies
	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {
		cout << it->get_movie_name() << endl;
	}

}

/** Adds the movie details to the coming list in non-decreasing order sorted by the release date.
	@param new_movie: a movie object to add in the coming list
*/
void Movie_Management_System::add_movie(const Movie& new_movie) {

	// Checking whether the receive and release dates are valid
	if (!isValidDate(new_movie.get_receive_date()) || !isValidDate(new_movie.get_release_date())) {
		cout << "Invalid date !! Cannot be added .. Please check!" << endl;
		return;
	}

	// Checking whether the release date is less than the receive date
	if (new_movie.get_release_date() <= new_movie.get_receive_date()) {
		cout << "Release date cannot be earlier or equal to the receive date!! Try again ..." << endl;
		return;
	}

	cout << "Adding the movie to the list...Please wait!" << endl;

	// Adds to the showing list if the movie's status is 'received'.
	if (new_movie.get_status() == RECEIVED) {

		// Checking whether the coming_list is empty
		if (coming_list.empty()) {
			coming_list.push_back(new_movie);
			return;
		}

		// Finding the correct position to insert the new movie
		list<Movie>::iterator insertion_place = std::find_if(coming_list.begin(), coming_list.end(), [&](const Movie& current) {
			return current.get_release_date() > new_movie.get_release_date();
			});

		// Checking whether the insertion_place iterator is in the end of the coming list
		if (insertion_place == coming_list.end()) {
			coming_list.push_back(new_movie);
		}
		else {
			coming_list.insert(insertion_place, new_movie);
		}

	}

	cout << "Movie was successfully added to the list. Thank you!!" << endl;
}


/** Moves the movies from the coming list to the showing list
	@param specified_released_date: a date to search in the coming list
*/
void Movie_Management_System::start_showing_movie(const Date& specified_released_date) {

	// Checking whether the specified is valid or not
	if (!isValidDate(specified_released_date)) {
		cout << "The release date is invalid... Sorry! Try again.\n" << endl;
		return;
	}

	// Checking whether the coming list is empty
	if (coming_list.empty()) {
		cout << "Sorry! Coming list is empty, cannot move any movies to showing list...\n" << endl;
		return;
	}

	// Creating a linked list "matching_movies" to store the movie data
	list<Movie> matching_movies;

	// Initializing the iterator to the beginning of the coming list
	list<Movie>::iterator it = coming_list.begin();

	// Iterating through the coming list
	while (it != coming_list.end()) {

		// Checking whether the movie exists in coming list
		if (it->get_release_date() != specified_released_date) {

			++it;
			continue;
		}

		// Creating a copy of the movie that matched the specified date
		Movie copy_of_movie = *it;

		// Deleting the movie that matched the specified date from the coming list
		it = coming_list.erase(it);

		// Initializing the iterator to the beginning of the showing list
		list<Movie>::iterator it_1 = showing_list.begin();

		// Iterating through the showing list
		while (it_1 != showing_list.end()) {

			// Checking whether the movie already exists in the showing list
			if (copy_of_movie.get_movie_name() == it_1->get_movie_name()) {

				cout << "The movie " << copy_of_movie.get_movie_name() << " already exists in showing list.\n" << endl;
				copy_of_movie = *it_1;
				it_1 = showing_list.erase(it_1);
				break;
			}
			it_1++;
		}


		// Checking whether the movie status = recieved
		if (copy_of_movie.get_status() == 0) {
			Status status = RELEASED;
			copy_of_movie.set_status(status);
		}

		// Adding the movie to the matching_movies list
		matching_movies.push_back(copy_of_movie);

	}

	// Checking whether the matching movies list is empty or not
	if (matching_movies.empty()) {

		cout << "No movies found with specified release date.\n" << endl;
		return;

	}

	// Moves movies from the coming list to the showing list
	for (list<Movie>::iterator it_3 = matching_movies.begin(); it_3 != matching_movies.end(); it_3++) {

		list<Movie>::iterator insertion = showing_list.begin();

		// Iterating through the showing list to find the right position to insert the movie object in the matching movies list
		for (; insertion != showing_list.end(); insertion++) {
			
			if (insertion->get_release_date() > it_3->get_release_date()) {
				showing_list.insert(insertion, *it_3);
				break;
			}

		}

		if (insertion == showing_list.end()) {
			showing_list.push_back(*it_3);
		}

	}

	cout << "Successfully moved the movies from coming list to showing list! Thank you...\n" << endl;


}


/** Finds and edits the movie release date in the coming list
	@param movie_name_to_edit: movie name to edit, new_release_date: new release date to be updated
*/
void Movie_Management_System::edit_coming_movie_releaseDate(const string& movie_name_to_edit, const Date& new_release_date) {

	list<Movie>::iterator delete_place = coming_list.end();

	// Iterating through the coming list to check whether the movie exists or not
	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (it->get_movie_name() == movie_name_to_edit) {
            
			// Checking whether the new release date is lesser than the receive date
			if (new_release_date <= it->get_receive_date()) {
				cout << "New Release date cannot be earlier or equal to the receive data !! Try again ...\n" << endl;
				return;
			}

			// Checking whether the new release date is valid
			if (!isValidDate(new_release_date)) {
				cout << "The release date is invalid... Sorry! Try again.\n" << endl;
				return;
			}

			delete_place = it;
			break;
		}
	}

	list<Movie>::iterator insertion_place;

	// Iterating through the coming list to update the new release date
	for (insertion_place = coming_list.begin(); insertion_place != coming_list.end(); ++insertion_place) {

		// Finding the correct position to insert the new release date
		if (insertion_place->get_release_date() > new_release_date) {

			coming_list.insert(insertion_place, *delete_place);
			insertion_place--;
			insertion_place->set_release_date(new_release_date);
			coming_list.erase(delete_place);
			break;

		}
	}

	// Checking whether the insertion_place is at the end of the coming list
	if (insertion_place == coming_list.end()) {

		coming_list.insert(insertion_place, *delete_place);
		insertion_place--;
		insertion_place->set_release_date(new_release_date);
		coming_list.erase(delete_place);
	}

	cout << "The movie information was successfully edited! Thank you.." << endl;
	return;
}


/** Finds and edits the movie description in the coming list
	@param movie_name_to_edit: movie name to edit, new_description: new description to be updated
*/
void Movie_Management_System::edit_coming_movie_description(const string& movie_name_to_edit, const string& new_description) {

	// Iterating through the coming list to update the new description
	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (it->get_movie_name() == movie_name_to_edit) {

			it->set_description(new_description);
			cout << "Movie information was successfully edited!! Thank you.." << endl;
			return;
		}
	}

	
}


/** Counts the number of movies which has release date lesser than specified date
	@param specified_date: A date to check
	@return: number of movies which has release date lesser than specified date
*/
int Movie_Management_System::count_coming_movies_before_date(const Date& specified_date) {

	int count = 0;

	// Checking whether specified date is valid or not
	if (!isValidDate(specified_date)) {

		cout << "The release date is invalid!!! Sorry, Try again.." << endl;
		return count;
	}

	// Iterating through the coming list to count the number of movies 
	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); ++it) {

		if (it->get_release_date() < specified_date) {
			count += 1;
		}
	}

	cout << "The Total number of movies: " << count;
	return count;

}

/** Saves the modified data to the output file
	@param output_file_name: name of the output file
*/
void Movie_Management_System::save_to_file(const string& output_file_name) {
	
	ofstream output_file(output_file_name);

	// Checking whether the output file can be opened or not
	if (!output_file) {
		cout << "Sorry! Error in opening file.." << endl;
		return;
	}

	// iterating through the showing list to display the movies
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

	// iterating through the coming list to display the movies 
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

	// closing the output file
	output_file.close();

	cout << "successfully saved the data to the file " << output_file_name << endl;
	cout << endl;
}

/** Checks whether the movie exists in the coming list or not
	@param movie_name: A movie name to compare
	@return: {true} if the movie exists in the coming list; {false} otherwise.
*/
bool Movie_Management_System::check_movie_in_showinglist(const string& movie_name) {

	// Iterating through the coming list to check whether the movie exists
	for (list<Movie>::iterator it = coming_list.begin(); it != coming_list.end(); it++) {
		if (it->get_movie_name() == movie_name) {
			return true;
		}
	}
	return false;
}

/** Loads the movie data from the input file
	@param input_file_name: name of the input file
*/
void Movie_Management_System::load_from_file(const string& input_file_name) {

	string read_line;
	ifstream input_file(input_file_name);

	// Checking whether the input file can be opened or not.
	if (!input_file) {
		cout << "Sorry! Cannot open the file" << endl;
		return;
	}

	// Checking whether the input file is empty
	if (input_file.peek() == ifstream::traits_type::eof()) {
		cout << "The input file is empty. Try again later!!!\n" << endl;
		input_file.close();
		exit(EXIT_FAILURE);
	}

    // Reading the data from the file
	while (getline(input_file, read_line)) {

		if (read_line.empty()) {
			break;
		}

		stringstream read_string(read_line);

		// Creating variables with appropriate data type
		string name_str, release_date_str, description_str, receive_date_str, status_str;
		Status status;
		Date obj_release_date;
		Date obj_receive_date;

		// Loading the data to the variables
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

		// Parsing the release date
		if (obj_release_date.parse_from_string(release_date_str)) {
			// Successfully loaded the release date
		}
		else {
			cout << "Error in parsing the release date" << endl;
			continue;
		}

		// Parsing the receive date
		if (obj_receive_date.parse_from_string(receive_date_str)) {
			// "Successfully loaded the receive date"
		}
		else {
			cout << "Error in parsing the release date" << endl;
			continue;
		}

		// Checking whether the release date is valid
		if (!isValidDate(obj_release_date)) {
			cout << "The release date is invalid... Sorry! Try again" << endl;
			return;
		}

		// Checking whether the receive date is valid 
		else if (!isValidDate(obj_receive_date)) {
			cout << "The receive date is invalid... Sorry! Try again" << endl;
			return;
		}

		// Checking whether the release date is lesser than the receive date
		if (obj_release_date <= obj_receive_date) {
			cout << "Release date cannot be earlier or equal to the receive date!! Error in loading the file, try again ..." << endl;
			input_file.close();
			exit(EXIT_FAILURE);
		}

		// Creating the movie object
		Movie obj_movie(name_str, obj_release_date, description_str, obj_receive_date, status);

		// Checking the movie has the status of "received".
		if (status == RECEIVED) {

			if (coming_list.empty()) {
				coming_list.push_back(obj_movie);
				continue;
			}

			// Finding the correct position to insert the new movie object
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

		// If the movie has the status of "released".
		else {

			if (showing_list.empty()) {
				showing_list.push_back(obj_movie);
				continue;
			}

			// Finding the correct position to insert the new movie object
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

	// Closing the input file
	input_file.close();
	cout << " " << endl;  // Successfully loaded all the data
	

}