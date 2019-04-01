//Song.cpp
#include <iostream>
#include "Song.h"
using namespace std;
Song::Song(string a,string n, int m) {
    artist=a;
    name=n;
    mem=m;
}

//Returns the artist of the song
//i/p: none o/p string containing artist
string Song::getArtist() const{ return artist;}

//Returns the name of the song
//i/p: none o/p string containing name
string Song::getName() const{return name;}

//Returns the memory of the song
//i/p: none o/p int containing size
int Song::getMem() const{ return mem;}

//sets the artist to the input string
void Song::setArtist(string a) {artist=a;}

//sets the name to the input string
void Song::setName(string n) {name=n;}

//sets song size to the input integer
void Song::setMem(int m) {mem=m;}

bool Song::operator >(Song const &s2) { /*
    string song_string1=this->artist+this->name+to_string(this->mem);
    string song_string2=s2.artist+s2.name+to_string(s2.mem);
    return song_string1>song_string2;*/
    return (this->artist>s2.artist) || ((this->artist==s2.artist) && (this->name>s2.name)) ||
        ((this->artist==s2.artist) && (this->name==s2.name) && (this->mem>s2.mem));
}
bool Song::operator <(Song const &s2) {/*
    string song_string1=this->artist+this->name+to_string(this->mem);
    string song_string2=s2.artist+s2.name+to_string(s2.mem);
    return song_string1<song_string2;*/
    return (this->artist<s2.artist) || ((this->artist==s2.artist) && (this->name<s2.name)) ||
        ((this->artist==s2.artist) && (this->name==s2.name) && (this->mem<s2.mem));
}
bool Song::operator ==(Song const &s2) { 
    string song_string1=this->artist+this->name+to_string(this->mem);
    string song_string2=s2.artist+s2.name+to_string(s2.mem);
    return song_string1==song_string2;
    
}
bool Song::operator !=(Song const &s2) {
    string song_string1=this->artist+this->name+to_string(this->mem);
    string song_string2=s2.artist+s2.name+to_string(s2.mem);
    return song_string1!=song_string2;
}
