//Song.cpp

#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Song {
    private: 
        string artist;
        string name;
        int mem;
    public:

        Song(string a,string n, int m);
        string getArtist() const;
        string getName() const;
        int getMem() const;
        void setArtist(string a);
        void setName(string n);
        void setMem(int m);
        bool operator >(Song const &s2);
        bool operator <(Song const &s2);
        bool operator ==(Song const &s2);
        bool operator !=(Song const &s2);
};
#endif
