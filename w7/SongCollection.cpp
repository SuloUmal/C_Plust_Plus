#include "SongCollection.h"

  namespace sdds{

  
  SongCollection::SongCollection(string fname){
    std::ifstream file(fname);
		if (!file) {
			std::cout << "Can not open the file" << std::endl;
		}
		else {
			while (file) {
				Song song;
				std::string temp;
				std::getline(file, temp);
				if (file) {
					trim(song.title = temp.substr(0, 25));
					trim(song.artist = temp.substr(25, 25));
					trim(song.album = temp.substr(50, 25));
					try {
						song.release_year = std::stoi(temp.substr(75, 5));
					}
					catch (...) {
						song.release_year = 0;
					}
					song.length = std::stoi(temp.substr(80, 5));
					song.m_price = std::stod(temp.substr(85));

					songs.push_back(song);
				}
			}
		}
		file.close();
	}
  
    void SongCollection::display(std::ostream& out) const{
      for_each(songs.begin(), songs.end(), [&out](const Song& list) {
			out << list << std::endl;
		});

		auto sum = std::accumulate(songs.begin(), songs.end(), 0, [](const int& res, const Song& obj) {
			return res + obj.length;
		});

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');

		std::string str = "Total Listening Time: ";
		str += std::to_string(sum / 3600);
		str += ":";
		str += std::to_string((sum %= 3600) / 60);
		str += ":";
		str += std::to_string(sum % 60);
		out << "| " << std::setw(84) << str << " |" << std::endl;
	}

void SongCollection::sort(std::string record) {
		if (record == "title")
			std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {return a.title < b.title; });
		else if (record == "album")
			std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {return a.album < b.album; });
		else if (record == "length")
			std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {return a.length < b.length; });
	}

  void SongCollection::cleanAlbum() {
		for_each(songs.begin(), songs.end(), [](Song& song) {
			if (song.album == "[None]") {
				song.album = "";
			}
		});
	}

  bool SongCollection::inCollection(std::string search) const {
		auto res = std::find_if(songs.begin(), songs.end(), [&search](const Song& obj) {return obj.artist == search; });
		return res != songs.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string search) const {
		auto cnt = std::count_if(songs.begin(), songs.end(), [&search](const Song& obj) {	return obj.artist == search; });

		std::list<Song> song(cnt);

		std::copy_if(songs.begin(), songs.end(), song.begin(), [&search](const Song& obj) {return obj.artist == search; });

		return song;
	}


      string& SongCollection::trim(string& str){
      while (str.length() > 0 && str[0] == ' ')
        str.erase(0, 1);
      while (str.length() > 0 && str[str.length() - 1] == ' ')
        str.erase(str.length() - 1, 1);
	  return str;
      }

	  ostream& operator<<(ostream& out, const Song& obj) {
		  out << "| " << std::setw(20) << std::left << obj.title
			  << " | " << std::setw(15) << std::left << obj.artist
			  << " | " << std::setw(20) << std::left << obj.album
			  << " | " << std::setw(6) << std::right;
			  if (obj.release_year != 0)
			  out << obj.release_year;
			  else
			  out << "";
			  out << " | " << obj.length / 60 << ":";
		  if (obj.length % 60 < 10) {
			  out << "0";
		  }
		  out << obj.length % 60
			  << " | " << obj.m_price << " |";

		  return out;
	  }

}