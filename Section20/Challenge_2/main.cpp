// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // Display current song
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // Display Playlist
    std::cout << "\n-----------------Playlist-----------------" << std::endl;
    std::cout << "Song                  Artist                   Rating  " << std::endl;
    for (const Song& e: playlist) {
        std::cout << e << std::endl;
    }

    // Display Current Song
    std::cout <<  current_song << std::endl;
}

void add_song(std::list<Song> &playlist, std::list<Song>::iterator& current_song) {
    std::string name, artist;
    int rating;

    std::cout << "\nEnter Song Name: ";
    std::getline(std::cin, name);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Enter Artist Name: ";
    std::getline(std::cin, artist);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Enter Rating: ";
    std::cin >> rating;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    playlist.insert(current_song, Song(name, artist, rating));
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator temp;
    std::list<Song>::iterator current_song = playlist.begin();
    
    std::cout << "To be implemented" << std::endl;
    
    char input;
    do {
        display_menu();
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        switch (input)
        {
        case 'F':
            play_current_song(*(playlist.begin()));
            break;
        case 'N': ;
            current_song++;
            if (current_song == playlist.end()) {
                std::cout << "This is the last song!" << std::endl;
                current_song--;
            }
            play_current_song(*(current_song));
            break;
        case 'P':
            if (current_song != playlist.begin())
                current_song--;
            else
                std::cout << "This is the first song!" << std::endl;
            play_current_song(*(current_song));
            break;
        case 'A':
            add_song(playlist, current_song);
            break;
        case 'L':
            display_playlist(playlist, *current_song);
            break;
        case 'Q':
            break;
        default:
            std::cout << "Invalid Input!" << std::endl;
            break;
        }

    } while(std::toupper(input) != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}