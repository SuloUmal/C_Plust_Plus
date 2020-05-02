#ifndef SDDS_SONGCOLLECTION__H
#define SDDS_SONGCOLLECTION__H
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>  
#include <fstream>
#include <list>
using namespace std;
namespace sdds{
  struct Song{
    string artist;
    string title;
    string album;
    double m_price;
    int release_year;
    int length;
  };
  class SongCollection{
    vector<sdds::Song> songs;
    public:
    SongCollection(string fname);
    void display(ostream& out) const;
    string& trim(string& str);
    void sort(string record);
    void cleanAlbum();
    bool inCollection(string search) const;
	std::list<Song> getSongsForArtist(string search) const;
  };
  std::ostream& operator<<(std::ostream& out, const Song& obj);
}
#endif