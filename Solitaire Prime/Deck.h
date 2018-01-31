#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <cstdlib>
#include <Windows.h>

using namespace std;

class Deck {
private:
	Card card[52];
	int cardsLeft;
public:
	Deck();
	Card Deal();
	int CardsLeft();
	void ShowDeck();
	void Shuffle();
	void RefreshDeck();
};

#endif