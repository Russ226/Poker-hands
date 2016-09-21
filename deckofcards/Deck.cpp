#include "Deck.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>
using namespace std;
void printdeck(string deck[]);
void shuffle(string deck[]);
void createdeck(string deck[]);
void accdeck(string deck[],string pub[]);
Deck::Deck()
{

}
void Deck::createdeck(string deck[])
{
    string suit[4] = {"H","D","C","S"};
    string number[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int counter = 0;
    for(int i= 0; i<13; i++)
        for(int j=0; j<4; j++){
            deck[counter]= number[i]+suit[j];
            counter++;
        }
}
void Deck::shuffle(string deck[])
{
    srand(time(0));
    int counter = 0;
    string temp;
    int r1, r2;
    while(counter < 52)
    {
        //cycle#1
        r1=rand()%51;
        r2=rand()%51;
        temp = deck[r2];
        deck[r2] = deck[r1];
        deck[r1]= temp;
        //cycle#2
        r1=rand()%51;
        r2=rand()%51;
        temp = deck[r2];
        deck[r2] = deck[r1];
        deck[r1]= temp;
        //cycle#3
        r1=rand()%51;
        r2=rand()%51;
        temp = deck[r2];
        deck[r2] = deck[r1];
        deck[r1]= temp;
        counter++;
    }
}
void Deck::printdeck(string deck[])
{
    for(int i=0; i<56; i++)
        cout << deck[i] << " ";
}
//accesses private variable
void Deck::accdeck(string deck[],string pub[])
{
        for(int i=0;i<52;i++)
            pub[i]=deck[i];
}
