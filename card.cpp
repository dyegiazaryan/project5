#include "Card.h"
#include "Random.h"

Card::Card(string ph, bool cm)
    :phrase(ph), cardMatch(cm)
{
}

string Card::getPhrase()
{
    return phrase;
}

bool Card::match()
{
    return cardMatch;
}

