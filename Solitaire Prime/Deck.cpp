#include "Deck.h"

Deck::Deck()
{
	RefreshDeck();
}

void Deck::RefreshDeck()
{
	top = 0;
	const char suits[] = {'S', 'D', 'H', 'C'};
	char num, index = 0;
	for (char s : suits)
	{
		for (byte i = 0; i < 13; i++)
		{
			switch (i)
			{
				case 9:
					num = 'T';
					break;
				case 10:
					num = 'J';
					break;
				case 11:
					num = 'Q';
					break;
				case 12:
					num = 'K';
					break;
				default:
					num = i + '\x31';
			}
			card[index++].SetCard(num, s);
		}
	}
}

Card Deck::Deal()
{
	return card[top++];
}

int Deck::CardsLeft() const
{
	return 52-top;
}

void Deck::ShowDeck() const
{
	const char spaces[] = "                             ";
	int lower = 0, upper = 13;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
	for (int j = 0; j < 4; j++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
		wcout << spaces << "+--------------------------------------------------------------------+" << endl;
		wcout << spaces;
		wcout << "|";
		for (int i = lower; i < upper; i++)
		{
			wcout << " ";
			if (i == upper - 1) 
			{
				card[i].Display();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
				if (card[i].GetRank() != 'T')
					wcout << " |";
				else
					wcout << "|";
				wcout << endl;
			}
			else 
			{
				card[i].Display();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
				if (card[i].GetRank() != 'T')
					wcout << " |";
				else
					wcout << "|";
			}
		}
		lower = upper;
		upper += 13;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
	wcout << spaces;
	wcout << "+--------------------------------------------------------------------+" << endl << endl;
}

void Deck::Shuffle()
{
	int left, right;
	Card temp;

	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		left = rand() % 52;
		right = rand() % 52;
		temp = card[left];
		card[left] = card[right];
		card[right] = temp;
	}
	ShowDeck();
}