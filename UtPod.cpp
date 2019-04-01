//UtPod.cpp
#include "UtPod.h"
#include <cstdlib>
#include <ctime>
using namespace std;
UtPod::UtPod() {
    time_t timer;
    podMemSize=MAX_MEMORY;
    songs=NULL;
    srand(time(&timer));
}
UtPod::UtPod(int size) {
    time_t timer;
    podMemSize=size;
    songs=NULL;
    srand(time(&timer));

}
UtPod::~UtPod() {
    clearMemory();
}

int UtPod::getTotalMemory() {
    int used=0;
    SongNode * p=(SongNode *)songs;
    while(p!=NULL) {
        used+=p->s.getMem();
        p=p->next;
    }
    return used;
}

int UtPod::getRemainingMemory() {
    return podMemSize-getTotalMemory();
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory()>=s.getMem()) {
       SongNode * temp = new SongNode(*temp);
        temp->s=s;
        if(songs==NULL) {
            songs=temp;
        }
        else {
            SongNode* p = songs;
            while(p->next!=NULL) {
                p=p->next;
            }
            p->next=temp;
        }
        return 0;
    }
    return -1;
}

int UtPod::removeSong(Song const &s) {
    SongNode *p=songs;
    SongNode *prev=NULL; 
    while( p!=NULL && (p->s)!=s) {
        prev=p;
        p=p->next;
    }
    if(p==NULL) {return -1;}
    
    if(prev==NULL) {//first value
        songs=songs->next;
        delete p;
    }
    else {//somewhere in middle/end
        prev->next=p->next;
        delete p;
    }
    return 0;


}

void UtPod::showSongList() {
    SongNode*p=songs;
    while(p!=NULL) {
        cout << p->s.getArtist() << ", " << p->s.getName() << ", " << p->s.getMem() << "MB" << endl;
        p=p->next;
    }
    cout << endl;
}
void UtPod::clearMemory() {
    SongNode* prev=NULL;
    while(songs!=NULL){
        prev=songs;
        songs=songs->next;
        delete prev;
    }
}

void UtPod::sortSongList() {
    //insertion sort
    SongNode * head = songs;
    SongNode * index;
    while(head!=NULL) {
        index=head->next;
        SongNode *min = head;
        while(index!=NULL) {
            if(index->s < min->s) {
                min=index;
            }
            index=index->next;
        }
        Song temp = head->s;
        head->s=min->s;
        min->s=temp;
        head=head->next;
    }

    
}

void UtPod::swap(int i,int j) {
    SongNode * lp1=songs;
    SongNode * lp2=songs;
    for(int k=0;k<i;k++) {
        lp1=lp1->next;
    }
    for(int k=0;k<j;k++) {
        lp2=lp2->next;
    }
    Song temp=lp2->s;
    lp2->s=lp1->s;
    lp1->s=temp;
}

void UtPod::shuffle() {
    int length=listLen();
    for(int i=0;i<length;i++) {
        swap(i,rand()%length);
    }
}