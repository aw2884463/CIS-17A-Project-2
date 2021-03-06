#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <iostream>
#include <string>

using namespace std;

class PlayingCard
{
private:
    int rank;
    char suit;
public:
    
    //Operator Overloads
    bool operator<(const PlayingCard& card1, const PlayingCard& card2)
    { 
        return card1.rank < card2.rank; 
    }
    bool operator>(const PlayingCard& card1, const PlayingCard& card2)
    { 
        return card1.rank > card2.rank; 
    }
    bool operator==(const PlayingCard& card1, const PlayingCard& card2)
    { 
        return card1.rank == card2.rank; 
    } 
    
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
};

#endif /* PLAYINGCARD_H */
