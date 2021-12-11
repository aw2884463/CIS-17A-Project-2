/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "BlackJack.h"


void BlackJack::startGame() {
    cout << "Hello, Welcome to Austin's game of Black Jack!!!";
    cout << endl << "How many players will be playing?:";
    cin >> pCount;
    players = new PlayerDeck[pCount];
    for(int i = 0 ;i < pCount;i++) {
        
    }
    dealInitial();
    
}

void BlackJack::dealInitial() {
    
    
    for(int i = 0;i < pCount;i++) {
        for(int j = 0; j < 2;j++) {
            random = rand() % 52;
            
            while(hold == true) {
            tempCard = deck[random].getCard();
                if(tempCard->getUsed() == false) {

                }
                    
            }
            
            
        }
        
    }
    
}