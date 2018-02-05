#include "Card.h"

Card::Card()
{
	rank = 'z';
	suit = 'z';
}

int Card::GetValue() const
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

void Card::Display() const 
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
	if (rank == 'T')
		std::wcout << 10;
	else
		std::wcout << rank;
	if (suit == 'S') {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xB);
		std::wcout << L"\x2660";
	}
	else if (suit == 'C') {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA);
		std::wcout << L"\x2663";
	}
	else if (suit == 'H') {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC);
		std::wcout << L"\x2665";
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);
		std::wcout << L"\x2666";
	}
}

void Card::SetCard(char rank, char suit)
{
	this->rank = rank;
	this->suit = suit;
}

char Card::GetRank() const
{
	return rank;
}