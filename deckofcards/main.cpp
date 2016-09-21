#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "Deck.h"
#include "Typesofhand.h"
using namespace std;
void drawcard(string deck[], string card[]);
//10C
int main()
{
    string deck[52],pdeck[52],hand[5];
    Deck de;
    Typesofhand ty;

    de.createdeck(deck);
    de.shuffle(deck);           //creates and accesses deck
    de.printdeck(deck);
    de.accdeck(deck,pdeck);

    drawcard(pdeck,hand);
    cout << endl;
    for(int i=0; i<5;i++)
        cout << hand[i] << " ";
    cout << endl;
    ty.ranks(hand);


    return 0;
}
void drawcard(string deck[], string card[])
{

    for(int i=0; i<5; i++)
        card[i]=deck[i];
}
