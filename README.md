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
- User Authentication:
  Implementation of user authentication for secure access to the system. We can achieve this by creating usernames and passwords for logging into the system safely.
  
-	Search and Filtering:
  Adding search and filtering options for efficient and fast retrieval of movie information. Designing an effective algorithm will be fundamental for performance.
 	
-	GUI Interface:
  Develop a graphical user interface for a more user-friendly experience.
 	
-	Database Integration:
  Integration of a back-end database system would be better for data management and persistence. By using open-source relational databases, long-term data could be archived and retrieved more efficiently.
 	
-	Error Handling:
  Enhancing error handling and providing meaningful error messages for better user guidance.
 	
-	Sorting Algorithms:
  Implementation of more efficient algorithms for large datasets would reduce the customer wait time.
 	
-	Data Validation:
  Improve input validation to handle various edge cases for detail.
 	
-	Reporting:
  Add reporting features to generate statistics and insights about movie data. We can perform graphical analysis for better comprehension.
 	
-	Notification System:
  Implementation of a notification system for important events or upcoming movie releases.
 	
- Creating rating and expiration date feature:
  Create a rating and expiration date feature for gaining insights about customer satisfaction. Enabling customers to rate the movies would be useful for determining whether a movie should be displayed in the 
  theater or not. Having an expiration date feature pushes the movie to the archive when the movie passes the expiration date. This would be helpful in keeping track of current movies and getting rid of unwanted 
  movies.

