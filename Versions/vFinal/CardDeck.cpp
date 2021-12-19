/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "CardDeck.h"

CardDeck::CardDeck() {
    stat = false;
    cards = new ValidCard[52];
    rankC = 1;
    
    //Loops through all cards in the deck
    for(int i = 0;i < 52;i++) { 
        //Sets card value to not used
        cards[i].setUsed(stat);
        //Suit of hearts
        if(i < 13) {
            cards[i].setSuit('H');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 12) {  
                rankC = 1;
            }
        }
        //Suit of spades
        else if(i < 26 && i > 12) {
            cards[i].setSuit('S');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 25) {  
                rankC = 1;
            }
        }
        //Suit of clubs
         else if(i < 39 && i > 25) {
            cards[i].setSuit('C');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 38) {  
                rankC = 1;
            }
        }
        //Suit of diamonds
         else {
            cards[i].setSuit('D');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 51) {  
                rankC = 1;
            }
        }  
    }  
}

CardDeck::~CardDeck()
{
    resetDeck();
    delete[] cards;
}

void CardDeck::printDeck() {
    //Loops through all cards
    for(int i =0;i < 52;i++) {
        //Runs the method to print the card value
        cards[i].printCard();
        //Sets if the card has been used or not
        stat = cards[i].getUsed();
        switch(stat)
        {
            case 0:
                cout << "Is in the deck" << endl;
                break;
            case 1:
                cout << "Is not in the deck" << endl;
                break;
        }
    }
    
    
}

void CardDeck::shuffle(int nTimes) {
    //Random function
    //nTimes How many times the card will be shuffled
    srand(static_cast<unsigned int>(time(0)));
    nCards = 52;
    //Shuffles the cards nTimes
    for(int i = 0 ;i < nTimes;i++) {
        for(int j = 0;j < nCards;j++) {
            val = rand() % nCards;
            val2 = rand() % nCards;
            change(cards[val],cards[val2]);
        }  
    }   
}


void CardDeck::rmCard(int index) {
    //Sets a cards as used
    //index Index what card to set as used
    cards[index].setUsed(true);
}

void CardDeck::rpCard(int index) {
    
    //Sets a cards as used
    //index Index what card to set as used
    cards[index].setUsed(false);
}

ValidCard CardDeck::getCard(int index) {
    //Gets a cards at index
    //index Index what card to set as used
   return cards[index];
}

void CardDeck::resetDeck() {
    //Resets all the cars in the deck
    for(int i = 0;i < 52;i++) {
        ///Runs replace card method
        rpCard(i);
    }
}

