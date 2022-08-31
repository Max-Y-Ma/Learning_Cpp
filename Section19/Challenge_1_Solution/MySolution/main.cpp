// Section 19
/*
Section 19 
Challenge 1 

Formatting output
===========================================================
I have provided you with the starter source code for this challenge.
In this challenge you are to display the provided data in a nicely formatted table.
Your table does not have to match mine, but practice with the format manipulators
so you become comfortable with them.

There are 3 structures provided. Yes, these could also be classes with public data, 
but it's common to use structures when we simply want to model only data and not 
operations as we would with classes.

The structures work together to create a Tours structure that will contain
information about Tours to South America.
The Tours include Countries, Cities within those countries along with population and cost data for 
each city tour.
I know, population? Huh? I just wanted a big number so that you can format it, OK :)

Please watch the Challenge video for the expected output. It won't look right if I put it in this
editor because of the font style.

In the provided source code I'm giving you some code that displays the data from the structures 
and the vectors within the structures. This code uses tabs to format the data and it looks pretty ugly.

Have fun!! Create functions if you like, use constants, whatever you think makes sense!
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // Unformatted display so you can see how to access the vector elements
    std::cout << tours.title << std::endl;
    std::cout << std::setfill('-') << std::setw(65) << ' ' << std::setfill(' ') << std::endl;
    std::cout << "Country" << std::setw(23) << "City" << std::setw(15) << "Population" << std::setw(15) << "Price" << std::endl;
    std::cout << std::setfill('-') << std::setw(65) << ' ' << std::setfill(' ') << std::endl;
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << country.name << std::endl;
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(30) << city.name 
                      << std::scientific << std::setw(15) << city.population 
                      << std::setw(10) << std::resetiosflags(std::ios::scientific) <<  std::setprecision(2) << std::fixed << "$" << city.cost 
                      << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}