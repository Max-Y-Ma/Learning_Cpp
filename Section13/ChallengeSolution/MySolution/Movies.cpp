#include "Movies.h"
#include <limits>

void Movies::add_movie() {
    std::string name_;
    std::string rating_;
    int times_watched_ {1};

    std::cout << "Enter Name of Movie: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name_);

    std::cout << "Enter Rating of Movie (G, PG, PG-13, R): ";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, rating_);
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (this->find_movie(name_) == nullptr) {
        this->movies.push_back(Movie {name_, rating_, times_watched_, num_movies + 1});
        this->num_movies++;
        std::cout << ">>>Movie Saved!" << std::endl;
    } else {
        std::cout << ">>>" << name_ << " Already Exists!\n" << std:: endl;
    }

    return;
}

void Movies::increment_movie() {
    std::cout << ">>>Enter Movie: ";

    std::string movie_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, movie_name);

    Movie* movie_ptr = find_movie(movie_name);

    if (movie_ptr != nullptr) {
        movie_ptr->set_times_watched(movie_ptr->get_times_watched() + 1);
        std::cout << ">>>Incremented Movie Times Watched!\n" << std::endl;
    } else {
        std::cout << ">>>Movie Not Found!\n" << std::endl;
    }

    return;
}

void Movies::display_movies() {
    if (this->num_movies == 0) {
        std::cout << ">>>Sorry, No Movies to Display!\n" << std::endl;
        return;
    }
    std::cout << "\n==============================" << std::endl;
    for (auto element: this->movies) {
        std::cout << "Movie #" << element.get_movie_number() << ": " << element.get_name() << " , " 
        << element.get_rating() << " , " << element.get_times_watched() << std::endl;
    }
    std::cout << "==============================\n" << std::endl;
}

Movie* Movies::find_movie(std::string name_) {
    for (auto &element: this->movies) {
        if (element.get_name() == name_) {
            return &element;
        }
    }
    return nullptr;
}