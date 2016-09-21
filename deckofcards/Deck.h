#ifndef DECK_H
#define DECK_H
#include <string>
using namespace std;
class Deck
{
    public:
        Deck();
        void printdeck(string deck[]);
        void shuffle(string deck[]);
        void createdeck(string deck[]);
        void accdeck(string deck[],string pub[]);
    protected:
    private:
        string deck[52];
};

#endif // DECK_H
