

#include "PlayerDeck.h"


//Constructor that gives the player his first 2 cards
PlayerDeck::PlayerDeck() {
    
    DeckValue = 0;
    for(int i = 0;i < 2;i++) { 
        PlayerCards.push_back(startCard);
    }
}

//Adds a card to the players deck
void PlayerDeck::addCard(ValidCard card) {
    
        PlayerCards.push_back(card);
}

//Sets a cards values at index
void PlayerDeck::setCard(ValidCard card,int index) {
    
    PlayerCards.at(index) = card;
      
    
}

//Returns the card at index
ValidCard PlayerDeck::getCard(int index) {
    
        return PlayerCards.at(index);
}

//Adds value to the total value of the desk
void PlayerDeck::addTotal(int value) {
    
        DeckValue += value;
}

//Sets the DeckValue as value
void PlayerDeck::setTotal(int value) {
    
        DeckValue = value;
}

//Prints the card at index
void PlayerDeck::printCardP(int index) {
        
        startCard = PlayerCards.at(index);
        startCard.printCard();
}

//Returns the total of the players deck
int PlayerDeck::getTotal() {
    
    return DeckValue;
}

//Returns the size of the deck
int PlayerDeck::deckSize() {
    
    return PlayerCards.size();
}