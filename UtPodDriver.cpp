/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "fstream"
#include "Song.h"
#include "UtPod.h"
#include <string>

using namespace std;


//Main Tester
//Reads file with format: command [arg] [arg] [arg]
//descriptions in switch statement
int main(int argc, char* argv[]) {
    string fname = argv[1];
    int podSize=512;
    if(argc>2) {
        podSize=atoi(argv[2]);
    }
    ifstream inFile;
    inFile.open(fname);
    string title,artist;
    char command;
    int mem;
    UtPod t(podSize);
    //get first command
    inFile >> command;
    while(inFile) {
        switch (command)
        {
            case 'a': {   //add song  "a title artist size"
                inFile >> title;
                inFile >> artist;
                inFile >> mem;
                Song s(title,artist,mem);
                int result = t.addSong(s);
                if(result==-1) {
                    cout<<"failed to add song: " << title <<" "<< artist<<" "<<mem<<endl;
                }
                break;
            }
            case 'd': {   //delete song  "d title artist size"
                inFile >> title;
                inFile >> artist;
                inFile >> mem;
                Song s(title,artist,mem);
                int result = t.removeSong(s);
                if(result==-1) {
                    cout<<"failed to remove song: " << title <<" "<< artist<<" "<<mem<<endl;
                }
                break;
            }
            case 'p':   //print list
                t.showSongList();
                break;
            case 'r':   //shuffle
                t.shuffle();
                break;
            case 's':   //sort
                t.sortSongList();
                break;
            case 'c':   //clear mem
                t.clearMemory();
                break;
            case 'm': //show mem
                cout << "Used: "<<t.getTotalMemory() <<endl;
                cout << "Free: "<<t.getRemainingMemory()<<endl;
                break;
            case 'e': { //echo  "e test test 123"
                string out;
                char first;
                inFile>>first;
                std::getline(inFile, out);
                cout << first << out <<endl;
            }

            default:
                break;
        }
        inFile >>command;
    }

}