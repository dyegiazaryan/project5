
#include<vector>
#include<string>
#include"Random.h"
#include"card.h"
#include"gameboard.h"

using namespace std;

int main()
{
    int selectCard1, selectCard2;

    vector<string> cardDB;
    vector<string*> playingCards;

    Gameboard gb(cardDB, playingCards);
    //cout<<cardDB.size()<<endl;
    //cout<<playingCards.size()<<endl;

    gb.checkCards(cardDB, playingCards);

    /*int attempts;
    do
    {
        gb.checkCards(cardDB, playingCards);
        attempts++;

    } while((attempts < playingCards.size()));*/
//    } while((gb.checkCards(cardDB, playingCards) == false) || (attempts < playingCards.size()));

return 0;
}
