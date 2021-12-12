/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "PlayerDeck.h"

PlayerDeck::PlayerDeck() {
    
    DeckValue = 0;
    stat = false;
    for(int i = 0;i < 2;i++) { 
        PlayerCards.push_back(startCard);
    }
}

void PlayerDeck::addCard(ValidCard card) {
    
        PlayerCards.push_back(card);
}

void PlayerDeck::setCard(ValidCard card,int index) {
    
    PlayerCards.at(index) = card;
      
    
}

ValidCard PlayerDeck::getCard(int index) {
    
        return PlayerCards.at(index);
}

void PlayerDeck::addTotal(int value) {
    
        DeckValue += value;
}

void PlayerDeck::setTotal(int value) {
    
        DeckValue = value;
}

void PlayerDeck::printCardP(int index) {
        
        startCard = PlayerCards.at(index);
        startCard.printCard();
}

int PlayerDeck::getTotal() {
    
    return DeckValue;
}

int PlayerDeck::deckSize() {
    
    return PlayerCards.size();
}