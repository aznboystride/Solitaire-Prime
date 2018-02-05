#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <Windows.h>

class Card {
private:
	char rank;
	char suit;

public:
	Card();
	void Display() const;
	void SetCard(char, char);
	int GetValue() const;
	char GetRank() const;
};

#endif