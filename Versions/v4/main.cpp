/*
 * Author:Austin Wroblos
 * Course:CIS-17A
 * Date:12/3/2021
 * Time:2:04PM
 */
#include "CardDeck.h"
#include "PlayerDeck.h"

#include <cstdlib>          // Standard library
#include <ctime>            // Time Library
#include <iostream>         // Input Output
#include <iomanip>          // Input/Output manipulation
#include <string>           // Getline
#include <fstream>          // Input output file stream
#include <array>            // Array library

using namespace std;


void startGame();

int main() {
    
    startGame();
   
    return 0;
}


void startGame() {
    
    cout << "Welcome to Austins Game of War" << endl;
    CardDeck deck;
    ValidCard testCard;
    ValidCard swap;
    ValidCard testCard2;
    PlayerDeck player(2);
    bool test;
    
    testCard.setRank(4);
    testCard.setSuit('S');
    testCard2.setRank(3);
    testCard2.setSuit('H');
    deck.printDeck();
    cout << "Before Shuffle!!!\n\n";
    deck.shuffle(5);
    deck.printDeck();
    cout << "Player Card" << endl;
    player.addCard(testCard);
    player.addTotal(20);
    int total = player.getTotal();
    cout << total << endl;
    player.printCardP(2);
    
}
