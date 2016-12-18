#ifndef GAMEBOARD_H_INCLUDED
#define GAMEBOARD_H_INCLUDED
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Gameboard
{
    private:
        int selectCard1;
        int selectCard2;
        vector<string> cardDB;
        vector<string*> playingCards;


    public:
        Gameboard(vector<string> &cardDB, vector<string*> &playingCards);
        //bool
        void checkCards(vector<string> &cardDB, vector<string*> &playingCards);
};


#endif // GAMEBOARD_H_INCLUDED
