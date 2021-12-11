/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "PlayerDeck.h"

PlayerDeck::PlayerDeck(int nCards) {
    
    DeckValue = 0;
    stat = false;
    for(int i = 0;i < nCards;i++) { 
        PlayerCards.push_back(startCard);
    }
}

void PlayerDeck::addCard(ValidCard card) {
    
        PlayerCards.push_back(card);
}

void PlayerDeck::addTotal(int value) {
    
        DeckValue += value;
}

void PlayerDeck::setTotal(int value) {
    
        DeckValue = value;
}

ValidCard PlayerDeck::getCardP(int index) {
    
        return PlayerCards.at(index);
}

void PlayerDeck::printCardP(int index) {
        
    ValidCard temp;
        temp = PlayerCards.at(index);
        temp.printCard();
}

int PlayerDeck::getTotal() {
    
    return DeckValue;
}