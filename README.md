                                                    Movie Management System
Overview:
 - This project is a Movie Management System that helps in maintaining two lists of movies: movies currently "showing" in the theater and movies "coming" to the theater. The system utilizes doubly-linked lists and iterators for efficient management of movie data.

Technical Requirements:
1. Movie Attributes:
 - release_date: Date when the movie is released.
 - name: Movie name (string).
 - description: Movie description (string).
 - receive_date: Date when the movie is received.
 - status: Enum type indicating whether the movie is received or released.

2. Functionality:
 - Display Movies: Display both "showing" and "coming" movies.
 - Add Movie: Add a new movie to the "coming" list, considering various constraints.
 - Start Showing Movies: Move movies from "coming" to "showing" list based on a specified release date, considering constraints.
 - Edit Movie: Edit a movie in the "coming" list (e.g., update release date or description).
 - Order Coming List: Keep the "coming" list ordered by release date.
 - Count Coming Movies: Count the number of "coming" movies with a release date earlier than a specified date.
 - Menu-based Interface: Implement a menu-based interface for user interaction.
 - File I/O: Read movies from an initial file, and write changes back to the file.

3. File Format:
 - The input file for movie data has the following format:

   Glass, 01/18/2019, Drama/Fantasy, 01/12/2019, released
   Miss Bala, 02/01/2019, Mystery/Thriller, 01/17/2019, received
   
   Each line represents a movie, and the information is structured as follows: name, release_date, description, receive_date, status.

Implementation: 
 - Data Structures: Utilizes doubly-linked lists for efficient movie management.
 - Iterator Usage: Implements iterators for traversing through the movie lists.

How to Use:
 - Clone the repository to your local machine.
 - Compile and run the program.
 - Follow the menu-based interface for various operations.

Contributing:
 - Feel free to contribute to the project by submitting bug reports, feature requests, or pull requests.

License:
 - This project is licensed under the MIT License.
 - 
Author:
 - Athul Jaishankar, Jordan Pham.

Version:
 - 1.0.0

Changelog:
 - 1.0.0 (Date): Initial release.

Future Improvements:
