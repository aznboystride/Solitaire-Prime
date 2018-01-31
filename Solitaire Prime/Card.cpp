#include "Card.h"

Card::Card()
{
	rank = 'z';
	suit = 'z';
}

int Card::GetValue()
{
	switch (rank) {
	case 'A':
		return 1;
	case 'J':
		return 10;
	case 'Q':
		return 10;
	case 'K':
		return 10;
	case 'T':
		return 10;
	default:
		return rank - '0';
	}
}

void Card::Display()
{
	if (rank == 'T')
		std::cout << 10;
	else
		std::cout << rank;
	std::cout << suit;
}

void Card::SetCard(char rank, char suit)
{
	this->rank = rank;
	this->suit = suit;
}