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

#ifndef CARDDECK_H
#define CARDDECK_H

#include "ValidCard.h"
#include "swap.h"
#include "ctime"


class CardDeck: public ValidCard {
    
private:
    
    int rankC;
    int val,val2;
protected: 
    ValidCard* cards;
    bool stat;
    int nCards;
    int nTimes;
public:
    
    CardDeck();
    void shuffle(int nTimes);
    
    
    void rmCard(int index);
    void rpCard(int index);
    ValidCard getCard(int index);
    void printDeck();
    void resetDeck();
    
    
    
};


#endif /* CARDDECK_H */

