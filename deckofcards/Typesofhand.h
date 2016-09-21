#ifndef TYPESOFHAND_H
#define TYPESOFHAND_H
#include <string>
#include "Deck.h"
using namespace std;

class Typesofhand
{
    public:
        Typesofhand();
        string highcard(string hand[]);
        string pairs(string hand[]);
        string flushstraight(string hand[]);
        void ranks(string hand []);
    protected:
    private:
        int housetwo(string hand[], string pair1);
};

#endif // TYPESOFHAND_H
