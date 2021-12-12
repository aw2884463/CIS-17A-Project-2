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
    
    int pCount,sCount;
    int deckIndex;
    ValidCard tempCard,tempCard2;
    int tempTotal;
    CardDeck deck;
    PlayerDeck* players;
    vector<bool> bustIndex;
    bool BJ,endTurn;
    int aceDet,hitStand;
    
public:
    
    BlackJack();
    
    void startGame();
    void addTotal(int i);
    void printTotals(int index);
    void printHand(int index);
    void dealInitial();
    void check4bj();
    void check4bust();
    int ask4hit();
    
};

#endif /* BLACKJACK_H */

