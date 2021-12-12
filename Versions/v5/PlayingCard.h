#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <iostream>
#include <string>

using namespace std;

class PlayingCard
{
private:
    string rankSeg;
    string ofSeg = " of ";
    string suitSeg;
    string cardString;
protected:
    int rank;
    char suit;
public:
    
    // Constructors
    PlayingCard();
    PlayingCard(int initRank, char initSuit);
    
    //Accessors
    int getRank();
    char getSuit();
    
    //Mutators
    void setRank(int initRank);
    void setSuit(char initSuit);
    
    //Methods
    void printCard();
    string cardToString();
    
    void operator=(const PlayingCard& card1);
    
};

#endif /* PLAYINGCARD_H */
