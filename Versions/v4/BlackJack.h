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
    
    int pCount;
    int deckIndex;
    ValidCard tempCard;
    CardDeck deck;
    PlayerDeck* players;
    int random;
    bool hold;
public:
    
    void startGame();
    void dealInitial();
};

#endif /* BLACKJACK_H */

