#include "gameboard.h"
#include "Card.h"
#include "Random.h"

Gameboard::Gameboard(vector<string> &cardDB, vector<string*> &playingCards)
{
    ifstream inf;
    inf.open("card.txt");

    string phrase;

    while (getline (inf, phrase))
    {
         cardDB.push_back(phrase);
    }
    inf.close();


    Random r(1, cardDB.size(), 2);

    for (int i = 0; i < (2*cardDB.size()); ++i)
    {
       playingCards.push_back(&cardDB[r.get()-1]);

    }
}
    //bool
    void Gameboard::checkCards(vector<string> &cardDB, vector<string*> &playingCards)
    {
        int selectCard1, selectCard2;
        int attempts=0;

        while(attempts<playingCards.size())
        {
            cout<<"Select two different cards between 1 and "<<playingCards.size()<<"."<<endl;
            cin>>selectCard1;
            cin>>selectCard2;

            if(*playingCards[selectCard1-1] == *playingCards[selectCard2-1])
            {
                //cout<<"if"<<endl;
                cout<<"The pairs match."<<endl;
                cout<<"Both phrases say \""<<*playingCards[selectCard1-1]<<"\"."<<endl;
                //return true;
            }

            else
            {
                //cout<<"else"<<endl;
                cout<<"The phrases don't match, try again."<<endl;
                cout<<"The first card says \""<<*playingCards[selectCard1-1]<<"\"."<<endl;
                //return false;
            }
        attempts++;

        }


    }

