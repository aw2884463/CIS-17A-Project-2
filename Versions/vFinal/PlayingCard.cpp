#include "PlayingCard.h"


PlayingCard::PlayingCard()
{
    //Constructor that sets the initial card value with no overloading
    rank = 1;
    suit = 'S';
}

PlayingCard::PlayingCard(int initRank, char initSuit)
{
    //Constructor that sets the initial card value through 2 parameters Line 13
    //initRank Sets the rank of the card
    //initSuit Sets the suit of the card
    if(initRank >= 1 || initRank <= 13)
    {   
        rank = initRank;
        switch(initSuit)
        {
            case ('H'):
            case ('h'):
                suit = 'H';
                break;
            case ('D'):
            case ('d'):
                suit = 'D';
                break;
            case ('C'):
            case ('c'):
                suit = 'C';
                break;
            case ('S'):
            case ('s'):
                suit = 'S';
                break;
            default:
                break;
        }
    }
}

//Accessors
int PlayingCard::getRank()
{
    //Returns the rank of the card
    return rank;
}
//Accessors
char PlayingCard::getSuit()
{
    //Returns the suit of the card
    return suit;
}

//Mutators
void PlayingCard::setRank(int initRank)
{
    //Sets the ranks of the card
    //initRank Determines what rank to set the card
    if(initRank >= 1 || initRank <= 13) 
    {
        rank = initRank;
    }
}
//Mutators
void PlayingCard::setSuit(char initSuit)
{
    //Sets the suit of the card
    //initSuit Determines what suit to set the card
   switch(initSuit)
    {
        case ('H'):
            suit = 'H';
            break;
        case ('D') :
            suit = 'D';
            break;
        case ('C'):
            suit = 'C';
            break;
        case ('S'):
            suit = 'S';
            break;
        default:
            break;
    }
}

//Methods
void PlayingCard::printCard()
{
    //Prints the card in readable text Line 93
    switch(rank)
    {
        case (1):
            cout << "Ace  ";
            break;
        case (2):
            cout << "Two  ";
            break;
        case (3):
            cout << "Three";
            break;
        case (4):
            cout << "Four ";
            break;
        case (5):
            cout << "Five ";
            break;
        case (6):
            cout << "Six  ";
            break;
        case (7):
            cout << "Seven";
            break;
        case (8):
            cout << "Eight";
            break;
        case (9):
            cout << "Nine ";
            break;
        case (10):
            cout << "Ten  ";
            break;
        case (11):
            cout << "Jack ";
            break;
        case (12):
            cout << "Queen";
            break;
        case (13):
            cout << "King ";
            break;
        default:
            break;
    }
    cout << " of ";
    switch(suit)
    {
        case ('H'):
            cout << "Hearts  ";
            break;
        case ('D'):
            cout << "Diamonds";
            break;
        case ('C'):
            cout << "Clubs   ";
            break;
        case ('S'):
            cout << "Spades  ";
            break;
        default:
            break;
    }
    cout << endl;
}

string PlayingCard::cardToString()
{
    //Uses rank and suit to convert card into a single string
    switch(rank)
    {
        case (1):
            rankSeg = "Ace  ";
            break;
        case (2):
            rankSeg = "Two  ";
            break;
        case (3):
            rankSeg = "Three";
            break;
        case (4):
            rankSeg = "Four ";
            break;
        case (5):
            rankSeg = "Five ";
            break;
        case (6):
            rankSeg = "Six  ";
            break;
        case (7):
            rankSeg = "Seven";
            break;
        case (8):
            rankSeg = "Eight";
            break;
        case (9):
            rankSeg = "Nine ";
            break;
        case (10):
            rankSeg = "Ten  ";
            break;
        case (11):
            rankSeg = "Jack ";
            break;
        case (12):
            rankSeg = "Queen";
            break;
        case (13):
            rankSeg = "King ";
            break;
        default:
            break;
    }
    switch(suit)
    {
        case ('H'):
            suitSeg = "Hearts  ";
            break;
        case ('D'):
            suitSeg = "Diamonds";
            break;
        case ('C'):
            suitSeg = "Clubs   ";
            break;
        case ('S'):
            suitSeg = "Spades  ";
            break;
        default:
            break;
    }
    cardString = (rankSeg + ofSeg + suitSeg);
    return cardString;
}

    void PlayingCard::operator=(const PlayingCard& card1)
    {   
        //Sets this card equal to the second card
        this->rank = card1.rank;
        this->suit = card1.suit;
    }