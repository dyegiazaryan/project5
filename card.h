#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Card
{
private:
    string phrase;
    bool cardMatch;

public:
    Card(string ph, bool cm);
    string getPhrase();
    bool match();

};

#endif // CARD_H_INCLUDED
