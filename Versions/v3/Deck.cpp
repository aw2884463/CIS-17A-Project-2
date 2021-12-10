/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Deck.h"

CardDeck::CardDeck() {
    stat = false;
    cards = new PlayerHand[52];
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
        }  
    }  
}

void CardDeck::printDeck() {
    
    
    for(int i =0;i < 52;i++) {
        cards[i].printCard();
    }
    
    
}


