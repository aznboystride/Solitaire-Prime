#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card {
private:
	char suit, rank;

public:
	Card();
	void Display();
	void SetCard(char, char);
	int GetValue();
};

#endif