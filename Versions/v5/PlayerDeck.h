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
        ValidCard startCard;
        bool stat;
        int DeckValue;
        vector<ValidCard> PlayerCards;
        int val,val2;
    protected:
    public:
        
        PlayerDeck();
        ValidCard getCard(int index);
        void addCard(ValidCard card);
        void setCard(ValidCard card,int index);
        int deckSize();
        void printCardP(int index);
        void addTotal(int value);
        void setTotal(int value);
        int  getTotal();
        
        
        
};

#endif /* PLAYERDECK_H */

