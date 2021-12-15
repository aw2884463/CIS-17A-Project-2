/* 
 * File:   PlayerCard.h
 * Author: Austin
 *
 * Created on December 7, 2021, 10:21 AM
 */

#ifndef VALIDCARD_H
#define VALIDCARD_H

#include "PlayingCard.h"

class ValidCard: public PlayingCard
{
    private:
        bool used; ///< Determines if the card is in play already  
    public:
        ///Constructors
        ValidCard();
        
        ///Accessors
        bool getUsed();
        
        ///Mutators
        void setUsed(bool initUsed);

        ///Operator Overloads
        bool operator<(const ValidCard& card1);
        ///Operator Overloads
        bool operator>(const ValidCard& card1);
        ///Operator Overloads
        bool operator==(const ValidCard& card1);
};



#endif /* VALIDCARD_H */