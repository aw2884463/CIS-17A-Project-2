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
    
    //Constructor
    CardDeck();
    //Destructor
    ~CardDeck();
    
    ///Shuffles the deck nTimes
    void shuffle(int nTimes);
    
    ///Removes the card at index in the deck
    void rmCard(int index);
    ///Replaces the card at index in the deck
    void rpCard(int index);
    ///Returns the card at index
    ValidCard getCard(int index);
    ///Prints all the card in the deck
    void printDeck();
    ///Sets all the cards in the deck as unused
    void resetDeck();
    
    
    
};


#endif /* CARDDECK_H */

