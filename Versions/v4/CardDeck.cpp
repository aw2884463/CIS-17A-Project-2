/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "CardDeck.h"

CardDeck::CardDeck() {
    stat = false;
    cards = new ValidCard[52];
    rankC = 1;
    for(int i = 0;i < 52;i++) { 
        
        cards[i].setUsed(stat);
        if(i < 13) {
            cards[i].setSuit('H');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 12) {  
                rankC = 1;
            }
        }
        else if(i < 26 && i > 12) {
            cards[i].setSuit('S');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 25) {  
                rankC = 1;
            }
        }
         else if(i < 39 && i > 25) {
            cards[i].setSuit('C');
            cards[i].setRank(rankC);
            rankC++;
            if(i == 38) {  
                rankC = 1;
            }
        }
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

void CardDeck::printDeck() {
    
    for(int i =0;i < 52;i++) {
        cards[i].printCard();
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
    
    srand(static_cast<unsigned int>(time(0)));
    nCards = 52;
    for(int i = 0 ;i < nTimes;i++) {
        for(int j = 0;j < nCards;j++) {
            val = rand() % nCards;
            val2 = rand() % nCards;
            change(cards[val],cards[val2]);
        }  
    }   
}

void CardDeck::rmCard(int index) {
    
    cards[index].setUsed(true);
}

void CardDeck::rpCard(int index) {
    
    cards[index].setUsed(false);
}

ValidCard CardDeck::getCard(int index) {
    
   return cards[index];
}

