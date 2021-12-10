/*
 * Author:Austin Wroblos
 * Course:CIS-17A
 * Date:12/3/2021
 * Time:2:04PM
 */


#include "PlayingCard.h"    // Playing card class
#include "PlayerHand.h"
#include "Deck.h"

#include <cstdlib>          // Standard library
#include <ctime>            // Time Library
#include <iostream>         // Input Output
#include <iomanip>          // Input/Output manipulation
#include <string>           // Getline
#include <fstream>          // Input output file stream
#include <array>            // Array library
#include <vector>           // Vector Library
#include <cctype>           // Upper and Lowercase manipulation

using namespace std;


void startGame();

int main() {
    
    CardDeck deck;
    PlayerHand testCard;
    PlayerHand testCard2;
    bool test;
    
    testCard.setRank(4);
    testCard.setSuit('H');
    testCard2.setRank(3);
    testCard2.setSuit('H');
    testCard.printCard();
    cout << endl;
    testCard2.printCard();
    cout << endl;
    test = testCard > testCard2;
    cout << test << endl;
    
    deck.printDeck();
    return 0;
}


void startGame() {
    

}
