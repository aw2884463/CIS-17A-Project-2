/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "PlayerHand.h"

PlayerHand::PlayerHand()
{
    PlayerHand::setRank(1);
    PlayerHand::setSuit('S');
    used = false;
}


bool PlayerHand::getUsed() {
    
    return used;
}

void PlayerHand::setUsed(char initUsed) {
    
    used = initUsed;
}

    bool PlayerHand::operator<(const PlayerHand& card1)
    { 
        cout << this->rank << endl << card1.rank << endl;
        return this->rank < card1.rank; 
    }
    bool PlayerHand::operator>(const PlayerHand& card1)
    {   
        cout << this->rank << endl << card1.rank << endl;
        return this->rank > card1.rank; 
    }
    bool PlayerHand::operator==(const PlayerHand& card1)
    {   
        cout << this->rank << endl << card1.rank << endl;
        return this->rank == card1.rank; 
    }