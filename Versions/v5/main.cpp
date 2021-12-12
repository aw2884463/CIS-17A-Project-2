/*
 * Author:Austin Wroblos
 * Course:CIS-17A
 * Date:12/3/2021
 * Time:2:04PM
 */
#include "CardDeck.h"
#include "PlayerDeck.h"
#include "BlackJack.h"

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
    
    BlackJack blackJack;

    blackJack.startGame();
    
    
}
