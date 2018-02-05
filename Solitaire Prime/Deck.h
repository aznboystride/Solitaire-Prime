#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <Windows.h>
#include <ctime>

using namespace std;

class Deck {
private:
	Card card[52];
	int top;
public:
	Deck();
	Card Deal();
	int CardsLeft() const;
	void ShowDeck() const;
	void Shuffle();
	void RefreshDeck();
};

#endif