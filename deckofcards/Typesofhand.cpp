#include "Typesofhand.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <sstream>

using namespace std;
string pairs(string hand[]);
string highcard(string hand[]);
int housetwo(string hand[], string pair1);
string flushstraight(string hand[]);
void ranks(string hand[]);
Typesofhand::Typesofhand()
{

}
//checks highest card in hand
string Typesofhand::highcard(string hand[])
{
    string high="0";
    for(int i=0;i<5;i++){
        if(hand[i][0]=='A'){
            high=hand[i];
            break;
            return high;
        }
        else if(hand[i][0]=='K'){
            high=hand[i];

        }
        else if(hand[i][0]=='Q'&&high[0]!='K'){
            high=hand[i];

        }
        else if(hand[i][0]=='J'&&high[0]!='K'&&high[0]!='Q'){
            high=hand[i];

        }
        else if(hand[i].length()==3&&high[0]!='K'&&high[0]!='Q'&&high[0]!='J'){
            high=hand[i];

        }
        else if(hand[i][0]>hand[i+1][0]&&high[0]!='K'&&high[0]!='Q'&&high[0]!='J'&&high.length()<3)
            high=hand[i];

    }
        return high;
}
//checks for pairs
string Typesofhand::pairs(string hand[])
{
    int c = 1,d;
    string pairs="nothing",pair2;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(hand[i].substr(0,2)==hand[j].substr(0,2)&&i!=j){
                    c++;
                    pairs = hand[i].substr(0,2);
                    pair2 = hand[i].substr(0,2);
            }
            else if(hand[i][0]==hand[j][0]&&i!=j){
                    c++;
                    pairs =hand[i][0];
                    pair2 =hand[i][0];
            }
            else
                ;
        }
        if(c>1)
            break;
    }

    d=housetwo(hand,pair2); //calls a function to check if there is a full house or two pairs
    //cout << "d is " << d << endl;
    //cout << "c is " << c << endl;
    if(d<2&&c>1){
        return "pair";
    }
    else if(c==4)
        return "Four of a kind";
    else if((c>2&&c<4)||(d>2&&d<4))
            return "Fullhouse";
    else if(c==3)
        return "Three of a kind";
    else if(c==2&&d==2)
        return "Two pairs";
    else
        return "nothing";


}
// checks for full house and two pairs if there is one  pair already found
int Typesofhand::housetwo(string hand[], string pair1)
{
    int c = 1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((hand[i].substr(0,2)==hand[j].substr(0,2)&&i!=j)&&hand[j].substr(0,2)!=pair1){
                    c++;
            }
            else if((hand[i][0]==hand[j][0]&&i!=j)&&hand[j].substr(0,1)!=pair1){
                    c++;
            }
            else
                ;
        }
        if(c>1)
            break;
    }
    return c;

}
//checks for a straight, flush, or both
string Typesofhand::flushstraight(string hand[])
{
    //First part changes deck values for easier straight detection
    string temp, thand[5];
    int schecker=0,length,num1,num2,test; //num 1 and 2 are used for type casting; test is used to check for doubles
    int h=0,s=0,c=0,d=0, r=0;
    bool flush= false, straight=false,royal=false;
    for(int i = 0; i<5; i++){
        thand[i] = hand[i];
    }
    for(int i = 0; i<5; i++){
        if(thand[i][0] == 'J'){
            temp = thand[i][1];
            thand[i]="11";
            thand[i] += temp;
        }
        else if(thand[i][0] == 'Q'){
            temp = thand[i][1];
            thand[i]="12";
            thand[i] += temp;
        }
        else if(thand[i][0] == 'K'){
            temp = thand[i][1];
            thand[i]="13";
            thand[i] += temp;
        }
        else if(thand[i][0] == 'A'){
            temp = thand[i][1];
            thand[i]="14";
            thand[i] += temp;
        }
        else
            ;
    }
    //looks for straight
    for(int i = 0; i<5; i++){
        for(int j =i; j<5; j++){
            length=thand[i].size();
            istringstream (thand[i].substr(0,length-1))>>num1;
            istringstream (thand[j].substr(0,length-1))>>num2;
            istringstream (thand[i+1].substr(0,length-1))>>test;
            if((num1 == num2+1||num1 == num2-1)&&num1!=test)
                schecker++;

        }


    }
    if(schecker == 4)
            straight =true;



    //checks for flush
    for(int i= 0; i<5; i++){
        length=thand[i].size();
        if(thand[i][length-1]=='H')
            h++;
        else if(thand[i][length-1]=='S')
            s++;
        else if(thand[i][length-1]=='C')
            c++;
        else if(thand[i][length-1]=='D')
            d++;
        else
            ;
        if(s==5||h==5||d==5||c==5)
            flush = true;
    }

    if(flush&&straight){
        for(int i=0;i<5;i++){
            istringstream (thand[i].substr(0,length-1))>>num1;
            if(num1==10)
                r++;
            else if(num1==11)
                r++;
            else if(num1==12)
                r++;
            else if(num1==13)
                r++;
            else if(num1==14)
                r++;
            else
                ;

        }

        if(r==5)
            royal = true;
        if(royal)
            return "Royal Flush";
        else
            return "Straight Flush";
    }
    else if (flush)
        return "Flush";
    else if(straight)
        return "Straight";
    else
        return "nothing";


}
void Typesofhand::ranks(string hand[])
{
    string type;
    bool t=false;
    type = flushstraight(hand);
    if(type=="Royal Flush"){
        cout << "Royal Flush" << endl;
        t=true;
    }
    if(type=="Straight Flush"){
        cout << "Straight Flush" << endl;
        t=true;
    }
    type = pairs(hand);
    if(type=="Fullhouse"){
        cout << "Fullhouse" << endl;
        t=true;
    }
    type = flushstraight(hand);
    if(type=="Flush"){
        cout << "Flush" << endl;
        t=true;
    }
    if(type=="Straight"){
        cout << "Straight" << endl;
        t=true;
    }
    type = pairs(hand);
    if(type=="Three of a kind"){
        cout << "Three of a kind" << endl;
        t=true;
    }
    if(type=="Two pairs"){
        cout << "Two pairs" << endl;
        t=true;
    }
    if(type=="pair"){
        cout << "pair" << endl;
        t=true;
    }
    if(t==false){
        type = highcard(hand);
        cout << "High card: " << type << endl;
    }

}






