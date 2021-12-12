/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "BlackJack.h"

BlackJack::BlackJack() {
    
    pCount = 0;
    sCount = 0;
    BJ = false;
    deckIndex = 0;
    hitStand = 99;
    
}


void BlackJack::startGame() {
    cout << "Hello, Welcome to Austin's game of Black Jack!!!";
    cout << endl << "How many players will be playing(MAX = 11)?:";
    cin >> pCount;
    cout << "How many times would you like the deck shuffled(MAX = 20):";
    cin >> sCount;
    deck.shuffle(sCount);
    pCount = pCount + 1;
    players = new PlayerDeck[pCount];
    dealInitial();
    check4bj();
    if(BJ == false) {
        for(int i = 0;i < pCount;i++) {
            addTotal(i); 
        }
        
        cout << endl << "---Totals---" << endl;
        for(int i = 0;i < pCount;i++) {
            printTotals(i);
        }
        //while(hitStand == 99) {
            
            ask4hit();
        //}
    }
}

void BlackJack::dealInitial() {
    
    for(int i = 0;i < pCount;i++) {
        
        if(i == 0)  {
            
            cout << "Dealer has these cards." << endl;
        }
        else {
        cout << "Player " << i << " has these cards." << endl;
        }
        bustIndex.push_back(false);
        for(int j = 0; j < 2;j++) {
            
            tempCard = deck.getCard(deckIndex);
            
            if(tempCard.getUsed() == false) {
                deck.rmCard(deckIndex);
                players[i].setCard(tempCard,j);
                deckIndex++;
            }
            else {
                
                cout << "Card unavailable";
            }
            
        }
        printHand(i);
    }
    
}

int BlackJack::ask4hit() {
    
    for(int i = pCount - 1;i > -1;i--) {
        hitStand = 99;
        if(i == 0) {
            if(players[i].getTotal() < 16 && bustIndex.at(i) == false) {
             
                while(players[i].getTotal() < 16) {
                    tempCard = deck.getCard(deckIndex);
                    players[i].addCard(tempCard);
                    addTotal(i);
                    cout << "Updated Total:" << endl;
                    printTotals(i);
                }
            }
        }
        else {
           
            if(bustIndex.at(i) != true) {

               while(hitStand != 2) {
                    cout << "Player " << i << " would you like to hit or stand" << endl;
                    cout << "Enter 1) to hit 2) to stand :";            
                    cin >> hitStand;
                switch(hitStand) {
                    case 1: 
                        cout << "You decided to hit you now have" << endl;
                        tempCard = deck.getCard(deckIndex);
                        players[i].addCard(tempCard);
                        printHand(i);
                        addTotal(i);
                        cout << "Updated Total:" << endl;
                        printTotals(i);
                        break;
                    case 2:
                        cout << "You decided to stand" << endl;
                        break;
                    default:
                        cout << "Invalid Input" << endl;
                        return 0;
                        break;
                    }
               }    
            }
        }      
   }
    
    return 2;
}

void BlackJack::printHand(int index) {
    
        for(int j = 0;j < players[index].deckSize();j++) {
            
            players[index].printCardP(j);
        }
        cout << endl;
}

void BlackJack::check4bj() {
    

    for(int i = 0;i < pCount;i++) {
            
            tempCard = players[i].getCard(0);
            tempCard2 = players[i].getCard(1);
            
            if(tempCard.getRank() == 1 && tempCard2.getRank() == 12) {
                
                if(i == 0) {
                    
                    cout << endl << "Dealer Won the game with blackjack!!!" << endl;
                    BJ = true;
                    return;
                }
                else {
                    
                    cout << endl << "Player " << i; 
                    cout <<   " won the game with blackjack!!!" << endl;
                    BJ = true;
                    return;
                }
                
            }
            else if (tempCard.getRank() == 12 && tempCard2.getRank() == 1) {
                
                if(i == 0) {
                    
                    cout << endl << "Dealer Won the game with blackjack!!!" << endl;
                    BJ = true;
                    return;
                }
                else {
                    
                    cout << endl << "Player " << i; 
                    cout <<   " won the game with blackjack!!!" << endl;
                    BJ = true;
                    return;
                }
                
            }
            else {
                
                if(i == 0) {
                    
                    cout << endl << "No blackjacks were found in the dealers hand" << endl;
                }
                else {
                    
                    cout << endl << "No blackjacks were found in player ";
                    cout << i << "'s hand" << endl;
                }
                
                
            }
    }
    
    
    cout << endl;
}

void BlackJack::addTotal(int i) {
    
        players[i].setTotal(0);
        for(int j = 0;j < players[i].deckSize();j++) {
            
            tempCard = players[i].getCard(j);
            if(tempCard.getRank() < 12 && tempCard.getRank() > 1) {
                
                players[i].addTotal(tempCard.getRank());
            }
            else if (tempCard.getRank() == 1) {
                
                if(i == 0) {
                    
                    switch(rand() % 2) {
                        
                        case 1:
                            
                            players[i].addTotal(1);
                            
                            break;
                            
                        case 0:
                            
                            players[i].addTotal(11);
                            break;
                            
                        default:
                            
                            cout << "Bugged" << endl;
                            break;
                    }
                    
                }
                else {
                    
                    cout << endl << "Player " << i << " do you want your ace";
                    cout << endl << "to count as 11 or 1" << endl;
                    cout << "Enter 1) for 11 and 2) for 1 :";
                    cin >> aceDet;
                    
                    switch(aceDet) {
                        
                        case 1: 
                             
                            players[i].addTotal(11);
                            break;
                            
                        case 2:
                            
                            players[i].addTotal(1);
                            break;
                            
                        default:
                            
                            cout << "Bugged" << endl;
                            break;
                    }
                    
                    
                }
            }
            else {
                
                players[i].addTotal(10);
            }
            
        }
}

void BlackJack::printTotals(int index) {
    
        
        tempTotal = players[index].getTotal();
        
        if(index == 0) {
            
            cout << "Dealer   has " << tempTotal << endl;
        }
        else {
            
            cout << "Player " << index << " has " << tempTotal << endl;
        }
      
}