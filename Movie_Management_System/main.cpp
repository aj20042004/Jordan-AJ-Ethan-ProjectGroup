
// Importing the modules
#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>
#include "Movie_Management_System.h"
#include "Status.h"
#include "Date.h"
#include "Movie.h"

using namespace std;

// Creating the main
int main() {

	// Creating a movie management system object
	Movie_Management_System movie_mange_system_obj;

	// Loading the file
	movie_mange_system_obj.load_from_file("Test.txt");

	// Creating the variables
	int choice_number;
	bool loop_switch = true;

	// Creating the while loop
	while (loop_switch) {

		// Menu system that takes users through the UI with a series of inputs
		cout << "Welcome to the Movie Management System" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "1. Display Movies" << endl;
		cout << "2. Add Movies" << endl;
		cout << "3. Edit release dates" << endl;
		cout << "4. Edit movie description" << endl;
		cout << "5. Start showing movies in the theater" << endl;
		cout << "6. Number of movies before a date" << endl;
		cout << "7. Save to file" << endl;
		cout << "8. Exit\n" << endl;

		cout << "Enter the choice number: ";
		cin >> choice_number;
		cout << endl;
		
		/**	Function to determine if the user's input was 1 
			Calls the display movies function from the movie_manage_system header file
		*/
		if (choice_number == 1) {
			movie_mange_system_obj.display_movies();
			cout << endl;
		}

		/**	Function to determine if the user's input was 2 and guides the user through the process of adding a new movie 
			Receives the name, release date, description, receive date, and status
		*/
		else if (choice_number == 2) {

			// Creating the variables
			string movie_name_str, release_date_str, description_str, receive_date_str, status_str;
			Date obj_release_date;
			Date obj_receive_date;
			Status status;

			// Input to get the name of the new movie the user wants to add
			cout << "Please enter a movie name to add: ";
			getline(cin >> ws, movie_name_str);
			cout << endl;

			// Checking whether the movie already exists in the showing list
			if (!movie_mange_system_obj.check_movie_in_showinglist(movie_name_str)) {

				// Input to get the release date of the new movie 
				cout << "Please enter a release date (format: MM/DD/YYYY - 01/09/2023) to add: ";
				cin >> release_date_str;
				cout << endl;

				// Input to get the description of the new movie
				cout << "Please enter a description to add: ";
				getline(cin >> ws, description_str);
				cout << endl;

				// Input to get the receive date of the new movie
				cout << "Please enter a receive date (format: MM/DD/YYYY - 01/09/2023) to add: ";
				cin >> receive_date_str;
				cout << endl;

				status = RECEIVED;

				// Parsing the release date
				if (obj_release_date.parse_from_string(release_date_str)) {
					// Successfully parsed the release date
				}
				else {
					cout << "Error in parsing the release date" << endl;
					continue;
				}

				// Parsing the receive date
				if (obj_receive_date.parse_from_string(receive_date_str)) {
					// "Successfully parsed the receive date"
				}
				else {
					cout << "Error in parsing the release date" << endl;
					continue;
				}

				// Creating and adding the movie to the coming list
				Movie new_movie(movie_name_str, obj_release_date, description_str, obj_receive_date, status);
				movie_mange_system_obj.add_movie(new_movie);
				cout << endl;
			}

			else {
				cout << "Sorry! Cannot add... the Movie already exists in the lists.\n" << endl;
			}
		}


		/**	Function to determine if the user's input was 3 and guides the user through the
		    process to edit the release date of a movie 
		*/
		else if (choice_number == 3) {

			// Creating the variables
			string edit_movie_name, release_date_str;
			Date edit_new_release_date;

			// Input to get the name of the movie to be edited
			cout << "Enter the movie name to edit: ";
			getline(cin >> ws, edit_movie_name);
			cout << endl;

			// Checking if the movie exists in the coming list
			if (movie_mange_system_obj.check_movie_in_showinglist(edit_movie_name)) {

				// Input to get the new release date of the movie 
				cout << "Enter the new release date (format: MM/DD/YYYY - 01/09/2023) to change: ";
				cin >> release_date_str;
				cout << endl;

				// Parsing the release date
				edit_new_release_date.parse_from_string(release_date_str);

				movie_mange_system_obj.edit_coming_movie_releaseDate(edit_movie_name, edit_new_release_date);

				cout << endl;
			}
			else {
				cout << "Sorry!The movie does not exit...Try again later\n" << endl;
			}
		}

		/**	Function to determine if the user's input was 4 and guides the user through the process to
		    edit a movie's description. Calls upon the edit_movie_name and the edit_new_description function from
			the header file to edit the movie description. 
		*/
		else if (choice_number == 4) {

			string edit_movie_name, edit_new_description;

			// Input to get the new name of the movie 
			cout << "Enter the movie name to edit: ";
			getline(cin >> ws, edit_movie_name);
			cout << endl;

			// Checking whether the movie exists in the showing list
			if (movie_mange_system_obj.check_movie_in_showinglist(edit_movie_name)) {

				// Input to get the new description of the movie 
				cout << "Enter the new description to change: ";
				getline(cin >> ws, edit_new_description);
				cout << endl;

				movie_mange_system_obj.edit_coming_movie_description(edit_movie_name, edit_new_description);

				cout << endl;
			}
			else { 
				cout << "Sorry!The movie does not exit...Try again later\n" << endl; 
			}
		}

		/**	Function to determine if the user's input was 5 and guides them through the process of moving a 
		    movie from the coming list to the showing list
		*/
		else if (choice_number == 5) {

			// Creating variables
			string specified_release_date_str;
			Date specified_release_date;

			cout << "Enter the specified release date (format: MM/DD/YYYY - 01/09/2023) to display the movies: " << endl;
			
			cin >> specified_release_date_str;
			cout << endl;

			// parsing the specified date
			specified_release_date.parse_from_string(specified_release_date_str);

			// Calling the start_showing_movie method
			movie_mange_system_obj.start_showing_movie(specified_release_date);

		}

		/**	Function to determine if the user's input was 6
			Shows how many number of movies are in the list before a specified date
		*/
		else if (choice_number == 6) {

			// Creating the variables
			string specified_release_date_str_cnt;
			Date specified_release_date_cnt;

			cout << "Enter the specified release date (format: MM/DD/YYYY - 01/09/2023): " << endl;
			cin >> specified_release_date_str_cnt;
			cout << endl;

			// Parsing the specified date
			specified_release_date_cnt.parse_from_string(specified_release_date_str_cnt);

			// Calling the count_coming_movies_before_date method
			movie_mange_system_obj.count_coming_movies_before_date(specified_release_date_cnt);
			cout << endl;
			cout << endl;
		}

		/**	Function to determine if the user's input was 7
			Saves the current list of movies to the text file
		*/
		else if (choice_number == 7) {
			movie_mange_system_obj.save_to_file("Test.txt");
		}

		/**	Function to determine if the user's input was 8
			Exits the program
		*/
		else if (choice_number == 8) {

			cout << "Thank you" << endl;
			loop_switch = false;
		}

		// Prompts the user to try again if they enter an invalid number
		else {
			cout << "Invalid Option number!!! Please Try again..." << endl;
			cout << endl;
		}

	}

	system("pause");

	// return
	return 0;
}