#include <iostream>
#include <vector>
#include <string>

class Movie {
public:
    std::string title;
    std::string genre;
    std::string releaseDate;
    int availableSeats;

    Movie(const std::string& movieTitle, const std::string& movieGenre, const std::string& date, int seats)
        : title(movieTitle), genre(movieGenre), releaseDate(date), availableSeats(seats) {}

    bool booktickets(int numTickets) {
        if (numTickets <= availableSeats) {
            availableSeats -= numTickets;
            return true;
        } else {
            std::cout << "not enough available seats." << std::endl;
            return false;
        }
    }

    void cancelBooking(int numTickets) {
        availableSeats += numTickets;
    }
};

class User {
public:
    std::string userID;

    User(const std::string& id) : userID(id) {}
};

class BookingSystem {
private:
    std::vector<Movie> movies;
    std::vector<User> users;

public:
    void displayavailablemovies() const {
        std::cout << "\navailable movies:" << std::endl;
        for (size_t i = 0; i < movies.size(); ++i) {
            std::cout << i + 1 << ". movie: " << movies[i].title << std::endl;
            std::cout << "   genre: " << movies[i].genre << std::endl;
            std::cout << "   release Date: " << movies[i].releaseDate << std::endl;
            std::cout << "   available Seats: " << movies[i].availableSeats << std::endl;
            std::cout << std::endl;
        }
    }

    void booktickets(const std::string& userID) {
        int movieIndex, numTickets;
        std::cout << "Enter the movie number to book tickets: ";
        std::cin >> movieIndex;

        if (movieIndex < 1 || movieIndex > static_cast<int>(movies.size())) {
            std::cout << "invalid movie number." << std::endl;
            return;
        }

        std::cout << "Enter the number of tickets to book: ";
        std::cin >> numTickets;

        if (numTickets <= 0) {
            std::cout << "Invalid " << std::endl;
            return;
        }

        if (movies[movieIndex - 1].booktickets(numTickets)) {
            std::cout << " booked successfully!" << std::endl;
        }
    }

    void cancelBooking(const std::string& userID) {
        int movieIndex, numTickets;
        std::cout << "Enter the movie number to cancel booking: ";
        std::cin >> movieIndex;

        if (movieIndex < 1 || movieIndex > static_cast<int>(movies.size())) {
            std::cout << "nvalid movie number." << std::endl;
            return;
        }

        std::cout << "Enter the number of tickets to cancel: ";
        std::cin >> numTickets;

        if (numTickets <= 0) {
            std::cout << "Invalid no of tickets." << std::endl;
            return;
        }

        movies[movieIndex - 1].cancelBooking(numTickets);
        std::cout << "Booking canceled successfully!" << std::endl;
    }

    void addMovie(const std::string& title, const std::string& genre, const std::string& releaseDate, int seats) {
        movies.push_back(Movie(title, genre, releaseDate, seats));
    }
};

int main() {
    BookingSystem bookingSystem;

    bookingSystem.addMovie("x", "scifi", "today", 100);
    bookingSystem.addMovie("y", "fight", "tomorrow", 80);

    std::string userID = "001";  

    bool repeat = true;

    while (repeat) {
        std::cout << "\nwelcome to the online movie ticket booking system!\n"
                     "1. view available movies\n"
                     "2. book tickets\n"
                     "3. cancel booking\n"
                     "4. exit\n\n"
                     "enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.displayavailablemovies();
                break;
            case 2:
                bookingSystem.booktickets(userID);
                break;
            case 3:
                bookingSystem.cancelBooking(userID);
                break;
            case 4:
                repeat = false;
                std::cout << "exiting the online movie ticket booking system. thank you!\n";
                break;
            default:
                std::cout << "Invalid chice. getlost.\n";
                break;

        }
    }

    return 0;
}
