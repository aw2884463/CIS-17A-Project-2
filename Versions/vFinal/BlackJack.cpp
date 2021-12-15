/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "BlackJack.h"

BlackJack::BlackJack() {
    
    pCount = 0;/// @param pCount Player Count
    sCount = 0;/// @param sCount Shuffle Count
    BJ = false;/// @param BJ Black Jack status
    deckIndex = 0;/// @param deckIndex what card to get from deck
    hitStand = 99;/// @param hitStand if the player wants to hit or stand
    winner,winnerTotal = -1;
    /// @param winner Stores winner index
    /// @param winnerTotal Stores winner hand value
    
}


void BlackJack::startGame() {
    cout << "Hello, Welcome to Austin's game of Black Jack!!!";
    cout << endl << "How many players will be playing(MAX = 11)?:";
    cin >> pCount;
    cout << "How many times would you like the deck shuffled(MAX = 20):";
    cin >> sCount;
    /// @see CardDeck::shuffle() Shuffles all the cards in the deck x amount of times
    deck.shuffle(sCount);
    pCount = pCount + 1;
    players = new PlayerDeck[pCount];
    /// @see dealInitial Deals the initial cards to all players
    dealInitial();
    /// @see check4bj Checks each players hand for BlackJack
    check4bj();
    if(BJ == false) {
        for(int i = 0;i < pCount;i++) {
            ///@see addTotal() Adds the value of the card to the players total
            addTotal(i); 
        }
        
        cout << endl << "---Totals---" << endl;
        for(int i = 0;i < pCount;i++) {
            /// @see printTotals() Prints total of player
            printTotals(i);
        }  
        /// @see ask4hit() Runs through all players ask to hit or stand
        ask4hit();
        /// @see lastChecks() Runs through all finishes the game also picks winner
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
        ///Sets all players bust status to false Line 69
        bustIndex.push_back(false);
        ///Gives all players 2 cards Line 71
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
        /// @see printHand() Prints cards in players hand
        printHand(i);
    }
    
}

void BlackJack::ask4hit() {
    
    ///Cycles through all players Line 95
    for(int i = pCount - 1;i > -1;i--) {
        hitStand = 99;///Resets hitStand Line 97
        ///Checks for dealer Line 98
        if(i == 0) {
            ///Makes sure the dealer hasn't bust and has less than 16 in value Line 100
            if(players[i].getTotal() < 16 && bustIndex.at(i) == false) {
                
                ///Forces dealer to hit if they have less than 16 Line 103
                while(players[i].getTotal() < 16) {
                    tempCard = deck.getCard(deckIndex);
                    deckIndex++;
                    players[i].addCard(tempCard);
                    addTotal(i);
                    cout << "Updated Total:" << endl;
                    printTotals(i);
                }
                ///Ends game if dealer goes over 21 Line 112
                if(players[i].getTotal() > 21) {
                    
                    cout << "Dealer has gone over 21 and busted all players win" << endl;
                    return 0;
                }
            }
        }
        else {
           
            ///Checks that player hasn't gone over 21 Line 122
            if(bustIndex.at(i) != true) {
                
                ///While the player hasn't decided stand run this Line 125
               while(hitStand != 2) {
                    cout << "Player " << i << " would you like to hit or stand" << endl;
                    cout << "Enter 1) to hit 2) to stand :";            
                    cin >> hitStand;
                    
                switch(hitStand) {
                    ///Runs if player wants to hit Line 132
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
                        ///Runs if player wants to stand Line 149
                    case 2:
                        cout << "You decided to stand" << endl;
                        break;
                        ///Runs if player entered and invalid number Line 153
                    default:
                        cout << "Invalid Input" << endl;
                        return 0;
                        break;
                    }
               }    
            }
        }      
   }
}

void BlackJack::lastChecks() {
    
    ///Adds all players that haven't bust to possible winner vector Line 167
    for(int i = 0;i < pCount;i++) {
        
        if(bustIndex.at(i) != true) {  
            posWinR.push_back(i);
        }
    }
    ///Cycles through all possible winners and finds person with highest hand Line 174
    for(int i = 0;i < posWinR.size();i++) {
        
        cout << posWinR.at(i) << endl; 
        ///Makes sure value isn't over 21 Line 178
        if(players[posWinR.at(i)].getTotal() > winnerTotal && players[posWinR.at(i)].getTotal() <= 21) {
            
           winnerTotal = players[posWinR.at(i)].getTotal();
           winner = posWinR.at(i); 
        }
        
    }
    ///Checks if winner is the dealer Line 186
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
        ///Loops through all cards and prints them Line 200
        for(int j = 0;j < players[index].deckSize();j++) {
            
            players[index].printCardP(j);
        }
        cout << endl;
}

void BlackJack::check4bj() {
    
    ///Loops through all players hand Line 211
    for(int i = 0;i < pCount;i++) {
            
        ///Stores first 2 cards in temp Variables Line 214
            tempCard = players[i].getCard(0);
            tempCard2 = players[i].getCard(1);
            
            ///Checks for 1 variation of blackjack Line 218
            if(tempCard.getRank() == 1 && tempCard2.getRank() == 11) {
                
                ///Checks for dealer Line 221
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
            ///Checks for another variation of black jack Line 237
            else if (tempCard.getRank() == 11 && tempCard2.getRank() == 1) {
                
                ///Checks for dealer
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
                
                ///Checks for dealer Line 258
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
        ///sets player total too 0 Line 280
        for(int j = 0;j < players[i].deckSize();j++) {
            
            tempCard = players[i].getCard(j);
            ///Stores the card in a temp variable to manipulate Line 284
            if(tempCard.getRank() < 11 && tempCard.getRank() > 1) {
                ///Adds the value of the card to the players total Line 286
                players[i].addTotal(tempCard.getRank());
            }
            ///Checks if card is an Ace Line 289
            else if (tempCard.getRank() == 1) {
                
                ///Checks if player asking is the dealer Line 292
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
                    
                    ///Ask the user what they want the ace to count as Line 317
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
                ///If card is a face card just add 10 Line 345
                players[i].addTotal(10);
            }
            
        }
}

void BlackJack::printTotals(int index) {
    
        
        tempTotal = players[index].getTotal();
        ///Stores the player at index hand value in tempvalue Line 356
        
        ///Checks if the player is the dealer Line 358
        if(index == 0) {
            
            
            cout << "Dealer   has " << tempTotal << endl;
        }
        else {
            
            cout << "Player " << index << " has " << tempTotal << endl;
        }
      
}