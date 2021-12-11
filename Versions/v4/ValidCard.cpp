/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "ValidCard.h"

ValidCard::ValidCard()
{
    ValidCard::setRank(1);
    ValidCard::setSuit('S');
    ValidCard::setUsed(false);
}


bool ValidCard::getUsed() {
    
    return used;
}

void ValidCard::setUsed(bool initUsed) {
    
    used = initUsed;
}

    bool ValidCard::operator<(const ValidCard& card1)
    { 
        return this->rank < card1.rank; 
    }
    bool ValidCard::operator>(const ValidCard& card1)
    {   
        return this->rank > card1.rank; 
    }
    bool ValidCard::operator==(const ValidCard& card1)
    {   
        return this->rank == card1.rank; 
    }