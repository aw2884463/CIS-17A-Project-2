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
        vector<ValidCard> PlayerCards;
        bool stat;
        int DeckValue;
        int val,val2;
    protected:
            
    public:
        
        PlayerDeck(int nCards);
        ValidCard getCardP(int index);
        void addCard(ValidCard card);
        void printCardP(int index);
        void addTotal(int value);
        void setTotal(int value);
        int  getTotal();
        int check4Ace();
        
        
        
};

#endif /* PLAYERDECK_H */

