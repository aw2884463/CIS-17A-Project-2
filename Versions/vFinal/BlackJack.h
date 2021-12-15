/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   blackjack.h
 * Author: Austin
 *
 * Created on December 11, 2021, 1:01 AM
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "PlayerDeck.h"
#include "CardDeck.h"

class BlackJack {
    
private:
    
    int pCount,sCount;//Player Count and Shuffle Count
    int deckIndex;//Determines where in the deck to pull a card from
    ValidCard tempCard,tempCard2;//Two temp cards to hold value for manipulation
    int tempTotal;//Holds the total that gets output to console
    CardDeck deck;//The deck for the game
    PlayerDeck* players;//Dynamic array of players
    vector<bool> bustIndex;//Determines what players went over 21
    vector<int> posWinR;//Vector of possible winners
    int winner,winnerTotal;//Holds the index of winning player and the card value;
    bool BJ,endTurn;//Determines if someone got blackjack and if the turn is over
    int aceDet;//Determines if ace is worth 11 or 1
    int hitStand;//Determines if the player wanted to hit or stand
    
public:
    
    //Constructor
    BlackJack();
    
    //Starts Game
    void startGame();
    
    //Mutator
    void addTotal(int i);
    //Mutator
    void ask4hit();
    //Mutator
    void dealInitial();
    
    //Accessor
    void printTotals(int index);
    //Accessor
    void printHand(int index);
    //Accessor
    void lastChecks();
    //Accessor
    void check4bj();
    //Accessor
    void check4bust();
    
};

#endif /* BLACKJACK_H */

