#include "PlayingCard.h"


PlayingCard::PlayingCard()
{
    rank = 1;
    suit = 'S';
}

PlayingCard::PlayingCard(int initRank, char initSuit)
{
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
    return rank;
}

char PlayingCard::getSuit()
{
    return suit;
}

//Mutators
void PlayingCard::setRank(int initRank)
{
    if(initRank >= 1 || initRank <= 13) 
    {
        rank = initRank;
    }
}

void PlayingCard::setSuit(char initSuit)
{
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
    string rankSeg;
    string ofSeg = " of ";
    string suitSeg;
    string cardString;
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

