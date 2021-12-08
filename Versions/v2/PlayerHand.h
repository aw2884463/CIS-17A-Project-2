
/* 
 * File:   PlayerCard.h
 * Author: Austin
 *
 * Created on December 7, 2021, 10:21 AM
 */

#ifndef PLAYERHAND_H
#define PLAYERHAND_H

#include "PlayingCard.h"

class PlayerHand: public PlayingCard
{
    private:
        bool used;
        PlayerHand* cards[26];
    public:
        //Constructors
        PlayerHand();
        PlayerHand(int initRank, char initSuit);
        
        //Accessors
        bool getUsed();
        
        //Mutators
        void setUsed(char initUsed);
        
        //Methods
        
        
        //Operator Overloads
    bool operator<(const PlayerHand& card1);
    bool operator>(const PlayerHand& card1);
    bool operator==(const PlayerHand& card1);
};



#endif /* PLAYERHAND_H */