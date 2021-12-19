/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PlayerDeck.h
 * Author: Austin
 *
 * Created on December 9, 2021, 7:38 PM
 */

#ifndef PLAYERDECK_H
#define PLAYERDECK_H

#include "ValidCard.h"
#include "vector"

class PlayerDeck: public ValidCard {
    
    private:
        ValidCard startCard;///Starts card value
        int DeckValue;///Value of players hand
        vector<ValidCard> PlayerCards;//vector that holds all cards
        int val,val2;//temp variables for rand function
    protected:
    public:
        
        ///Constructor
        PlayerDeck();
        void printCardP(int index);
        ///Mutators
        void addTotal(int value);
        ///Mutators
        void addCard(ValidCard card);
        ///Mutators
        void setCard(ValidCard card,int index);
        ///Mutators
        void setTotal(int value);
        //Accessors
        int deckSize();
        ///Accessors
        ValidCard getCard(int index);
        ///Accessors
        int  getTotal();
        
        
        
};

#endif /* PLAYERDECK_H */

