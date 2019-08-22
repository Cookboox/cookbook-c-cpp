#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
#include <string>


class Song
{
	friend std::ostream& operator<<(std::ostream& os, Song const& song)
	{
		os  << std::setw(20) << std::left << song.author 
			<< std::setw(20) << std::left << song.song_name
			<< std::setw(20) << std::left << song.rating << "\n";
		return os;
	}
private:
	std::string author;
	std::string song_name;
	int rating;
public:
	Song(std::string author = "unknown artist", std::string song_name = "uknown name", int rating = 0) : author{ author }, song_name{ song_name }, rating{ rating } {}
	~Song() = default;
	bool operator<(Song const& other) { return this->rating < other.rating; }
	bool operator==(Song const& other) { return this->author == other.author && this->song_name == other.song_name; }
};

void display_menu()
{
	std::cout << std::setw(15) << std::left << "\n------------------------------------------------------------------------------------------------------\n";
	std::cout << std::setw(15) << std::left << "[a]dd ";
	//std::cout << std::setw(15) << std::left << "[f]irst ";
	std::cout << std::setw(15) << std::left << "[s]how all ";
	std::cout << std::setw(15) << std::left << "[n]ext ";
	std::cout << std::setw(15) << std::left << "[p]revious ";
	//std::cout << std::setw(15) << std::left << "[d]elete";
	std::cout << std::setw(15) << std::left << "[q]uit";
	std::cout << std::setw(15) << std::left << "\n------------------------------------------------------------------------------------------------------\n";
}

void display_playlist(std::list<Song> &playlist)
{	
	std::cout << "_________________________________________________________\n";
	std::cout << std::setw(20) << std::left << "AUTHOR" << std::setw(20) << std::left << "SONG NAME" << std::setw(20) << std::left << "RATING" << "\n";
	for (auto i : playlist)
		std::cout << i;
}

void play_current(Song &s)
{
	std::cout << "currently playing >>>  " << s;
}


int main()
{
	std::list<Song> playlist{
		Song{"ka-spel", "hotel x", 10},
		Song{"vir unis", "perimeter", 8},
		Song{"pink floyd", "wish u were here", 6},
		Song{"beatles", "imagine", 8},
		Song{"marillion", "fugazi", 7},
		Song{"be-zet", "blue illusion", 6},
	};

	char choice;
	auto current_song = playlist.begin();

	do
	{	
		display_playlist(playlist);
		display_menu();
		play_current(*current_song);

		std::cout << "\nWHAT DO U WANT TO DO NEXT?\n";
		std::cin >> choice;

		switch (choice)
		{
		case 's':
			display_playlist(playlist);
			break;
		case 'n':
			current_song++;
			if (current_song == playlist.end())
				current_song = playlist.begin(); //reset the iterator to the first one 
			//play_current(*current_song);
			break;
		case 'p':
			if (current_song == playlist.begin())
				current_song = playlist.end(); //reset the iterator to the last one
			current_song--;
			break;
		case 'a':
		{
			std::string author{};
			std::string song_name{};
			int rating;

			//this is here to clear all from buffere otherwise the first cin is skipped..
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //i have no idea what this does but without it it causes problems

			std::cout << "what is the author? ";
			std::getline(std::cin, author);
			std::cout << "what is the song name? ";
			std::getline(std::cin, song_name);
			std::cout << "what is the rating? ";
			std::cin >> rating;
			playlist.emplace(current_song, Song{ author, song_name, rating });
			std::cout << "song added\n";
			break;
		}
		case 'q':
			choice = 'q';
			break;
		default:
			std::cout << "INVALID INPUT\n";
			std::cout << "press [q]uit to exit the app. any other key to contiunue\n";
			char c;
			std::cin >> c;

			if (c == 'q') 
				choice = 'q';
			break;
		}
	} 
	while (choice!= 'q' );
	return 0;
}