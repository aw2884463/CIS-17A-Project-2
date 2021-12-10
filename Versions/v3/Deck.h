/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Deck.h
 * Author: Austin
 *
 * Created on December 7, 2021, 1:28 PM
 */

#ifndef DECK_H
#define DECK_H

#include "PlayerHand.h"

class CardDeck: public PlayerHand {
    
private:
    
    PlayerHand* cards;
    bool stat;
    int rankC;
public:
    
    CardDeck();
    void shuffleDeck(int nTimes);
    
    
    int rmCard();
    void rpCard(int index);
    void printDeck();
    
    
    
};


#endif /* DECK_H */

