#pragma once
#include "Movie.h"
#include <vector>

class Movies {
    private:
        std::vector<Movie> movies;
        int num_movies;
    public:
        void add_movie();
        void increment_movie();
        void display_movies();
        Movie* find_movie(std::string name_);
};