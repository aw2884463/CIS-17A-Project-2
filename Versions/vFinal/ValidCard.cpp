/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "ValidCard.h"

ValidCard::ValidCard()
{
    //Constructor-Initializes all the  card attributes Line 10
    ValidCard::setRank(1);
    ValidCard::setSuit('S');
    ValidCard::setUsed(false);
}


bool ValidCard::getUsed() {
    ///Returns the status of the card Line 18
    
    return used;
}

void ValidCard::setUsed(bool initUsed) {
    // This method sets cards usable status Line 24
    //initUsed Determines if card used status is set to true or false
    used = initUsed;
}

    bool ValidCard::operator<(const ValidCard& card1)
    { 
        ///Checks if this card is less than the second card Line 31
        return this->rank < card1.rank; 
    }
    bool ValidCard::operator>(const ValidCard& card1)
    {   
        ///Checks if this card is greater than the second card Line 36
        return this->rank > card1.rank; 
    }
    bool ValidCard::operator==(const ValidCard& card1)
    {   
        ///Checks if this card is equal in rank of the second card Line 41
        return this->rank == card1.rank; 
    }