/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "BlackJack.h"

BlackJack::BlackJack() {
    
    pCount = 0;//pCount Player Count
    sCount = 0;//sCount Shuffle Count
    BJ = false;//BJ Black Jack status
    deckIndex = 0;//deckIndex what card to get from deck
    hitStand = 99;//hitStand if the player wants to hit or stand
    winner,winnerTotal = -1;
    //winner Stores winner index
    //winnerTotal Stores winner hand value
    
}

BlackJack::~BlackJack() {
   // Deallocate the memory that was previously reserved
   delete[] players;
}


void BlackJack::startGame() {
    cout << "Hello, Welcome to Austin's game of Black Jack!!!";
    cout << endl << "How many players will be playing(MAX = 11)?:";
    cin >> pCount;
    cout << "How many times would you like the deck shuffled(MAX = 20):";
    cin >> sCount;
    //CardDeck::shuffle() Shuffles all the cards in the deck x amount of times
    deck.shuffle(sCount);
    pCount = pCount + 1;
    players = new PlayerDeck[pCount];
    //dealInitial Deals the initial cards to all players
    dealInitial();
    //check4bj Checks each players hand for BlackJack
    check4bj();
    if(BJ == false) {
        for(int i = 0;i < pCount;i++) {
            //addTotal() Adds the value of the card to the players total
            addTotal(i); 
        }
        
        cout << endl << "---Totals---" << endl;
        for(int i = 0;i < pCount;i++) {
            //printTotals() Prints total of player
            printTotals(i);
        }  
        //ask4hit() Runs through all players ask to hit or stand
        ask4hit();
        //lastChecks() Runs through all finishes the game also picks winner
        lastChecks();
        
    }
}

void BlackJack::dealInitial() {
    
    //Loops through all players
    for(int i = 0;i < pCount;i++) {
        
        //Checks for dealer
        if(i == 0)  {
            
            cout << "Dealer has these cards." << endl;
        }
        else {
        cout << "Player " << i << " has these cards." << endl;
        }
        //Sets all players bust status to false
        bustIndex.push_back(false);
        //Gives all players 2 cards Line 71
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
        //printHand() Prints cards in players hand
        printHand(i);
    }
    
}

void BlackJack::ask4hit() {
    
    //Cycles through all players
    for(int i = pCount - 1;i > -1;i--) {
        hitStand = 99;///Resets hitStand
        //Checks for dealer
        if(i == 0) {
            //Makes sure the dealer hasn't bust and has less than 16 in value
            if(players[i].getTotal() < 16 && bustIndex.at(i) == false) {
                
                //Forces dealer to hit if they have less than 16
                while(players[i].getTotal() < 16) {
                    tempCard = deck.getCard(deckIndex);
                    deckIndex++;
                    players[i].addCard(tempCard);
                    addTotal(i);
                    cout << "Updated Total:" << endl;
                    printTotals(i);
                }
                //Ends game if dealer goes over 21
                if(players[i].getTotal() > 21) {
                    
                    cout << "Dealer has gone over 21 and busted all players win" << endl;
                    return;
                }
            }
        }
        else {
           
            //Checks that player hasn't gone over 21
            if(bustIndex.at(i) != true) {
                
                //While the player hasn't decided stand run this
               while(hitStand != 2) {
                    cout << "Player " << i << " would you like to hit or stand" << endl;
                    cout << "Enter 1) to hit 2) to stand :";            
                    cin >> hitStand;
                    
                switch(hitStand) {
                    //Runs if player wants to hit
                    case 1: 
                        cout << "You decided to hit you now have" << endl;
                        tempCard = deck.getCard(deckIndex);
                        deckIndex++;
                        players[i].addCard(tempCard);
                        printHand(i);
                        addTotal(i);
                        cout << "Updated Total:" << endl;
                        printTotals(i);
                        if(players[i].getTotal() > 21) {

                            cout << "Player " << i << " has gone over 21 and busted" << endl << endl;
                            bustIndex.at(i) = true;
                            hitStand = 2;
                        }
                        break;
                        //Runs if player wants to stand
                    case 2:
                        cout << "You decided to stand" << endl;
                        break;
                        //Runs if player entered and invalid number
                    default:
                        cout << "Invalid Input" << endl;
                        return;
                        break;
                    }
               }    
            }
        }      
   }
}

void BlackJack::lastChecks() {
    
    //Adds all players that haven't bust to possible winner vector
    for(int i = 0;i < pCount;i++) {
        
        if(bustIndex.at(i) != true) {  
            posWinR.push_back(i);
        }
    }
    //Cycles through all possible winners and finds person with highest hand
    for(int i = 0;i < posWinR.size();i++) {
        
        cout << posWinR.at(i) << endl; 
        //Makes sure value isn't over 21
        if(players[posWinR.at(i)].getTotal() > winnerTotal && players[posWinR.at(i)].getTotal() <= 21) {
            
           winnerTotal = players[posWinR.at(i)].getTotal();
           winner = posWinR.at(i); 
        }
        
    }
    //Checks if winner is the dealer
    if(winner == 0) {
        
        cout << "The dealer has won the game with " << winnerTotal << "!!!" << endl;
        printHand(winner);
    }
    else {
        
        cout << "Player " << winner << " has won the game with " << winnerTotal << "!!!" << endl;
        printHand(winner);
    }
    
}

void BlackJack::printHand(int index) {
        //Loops through all cards and prints them
        for(int j = 0;j < players[index].deckSize();j++) {
            
            players[index].printCardP(j);
        }
        cout << endl;
}

void BlackJack::check4bj() {
    
    //Loops through all players hand
    for(int i = 0;i < pCount;i++) {
            
        //Stores first 2 cards in temp Variables
            tempCard = players[i].getCard(0);
            tempCard2 = players[i].getCard(1);
            
            //Checks for 1 variation of blackjack
            if(tempCard.getRank() == 1 && tempCard2.getRank() == 11) {
                
                //Checks for dealer
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
            //Checks for another variation of black jack
            else if (tempCard.getRank() == 11 && tempCard2.getRank() == 1) {
                
                //Checks for dealer
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
                
                //Checks for dealer
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
        //sets player total too 0
        for(int j = 0;j < players[i].deckSize();j++) {
            
            tempCard = players[i].getCard(j);
            //Stores the card in a temp variable to manipulate
            if(tempCard.getRank() < 11 && tempCard.getRank() > 1) {
                //Adds the value of the card to the players total
                players[i].addTotal(tempCard.getRank());
            }
            //Checks if card is an Ace
            else if (tempCard.getRank() == 1) {
                
                //Checks if player asking is the dealer
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
                    
                    //Ask the user what they want the ace to count as
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
                //If card is a face card just add 10
                players[i].addTotal(10);
            }
            
        }
}

void BlackJack::printTotals(int index) {
    
        
        tempTotal = players[index].getTotal();
        //Stores the player at index hand value in tempvalue
        
        //Checks if the player is the dealer
        if(index == 0) {
            
            
            cout << "Dealer   has " << tempTotal << endl;
        }
        else {
            
            cout << "Player " << index << " has " << tempTotal << endl;
        }
      
}