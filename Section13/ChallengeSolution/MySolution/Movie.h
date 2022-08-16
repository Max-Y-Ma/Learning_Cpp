#pragma once
#include <string>
#include <iostream>

class Movie {
    private:
        std::string name;
        std::string rating;
        int times_watched;
        int movie_number;
    public:
        // Constructor
        Movie(std::string name_, std::string rating_, int times_watched_, int movie_number_)
            : name{name_}, rating{rating_}, times_watched{times_watched_}, movie_number{movie_number_} {}
        // Helper Functions
        const std::string get_name() {return name;}
        const std::string get_rating() {return rating;}
        const int get_times_watched() {return times_watched;}
        const int get_movie_number() {return movie_number;}
        void set_name(std::string name_) {this->name = name_;}
        void set_rating(std::string rating_) {this->rating = rating_;}
        void set_times_watched(int times_watched_) {this->times_watched = times_watched_;}
        void set_movie_number(int movie_number_) {this->movie_number = movie_number_;}
};