#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <iostream>
#include <string>

using namespace std;

class PlayingCard
{
private:
    string rankSeg; // in text
    string ofSeg = " of ";
    string suitSeg; // in text
    string cardString;// value in a single string
protected:
    int rank;// Holds the rank of the card
    char suit;// Holds the suit of the card
public:
    
    //Constructors
    PlayingCard();
    //Constructors
    PlayingCard(int initRank, char initSuit);
    
    //Accessors
    int getRank();
    //Accessors
    char getSuit();
    
    //Mutators
    void setRank(int initRank);
    //Mutators
    void setSuit(char initSuit);
    
    //Methods
    void printCard();
    //Methods
    string cardToString();
    
    //OverLoad operator
    void operator=(const PlayingCard& card1);    
};

#endif /* PLAYINGCARD_H */
