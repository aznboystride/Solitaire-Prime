#include "Deck.h"

Deck::Deck()
{
	RefreshDeck();
	cardsLeft = 52;
}

void Deck::RefreshDeck()
{
	byte rnk = '\x31';
	for (int i = 0; i < sizeof(card); i++)
	{
		if (i + 1 <= 13) {
			if(rnk <= '\x39')
				card[i].SetCard(rnk++, 'S');
			else
			{
				if (i + 1 == 10) {
					card[i].SetCard('T', 'S');
				}
				else if (i + 1 == 11) {
					card[i].SetCard('J', 'S');
				} else if (i + 1 == 12) {
					card[i].SetCard('Q', 'S');
				}
				else {
					card[i].SetCard('K', 'S');
				}
			}
		}
		else if (i + 1 <= 26) {
			if (rnk <= '\x39')
				card[i].SetCard(rnk++, 'H');
			else
			{
				if (i + 1 == 10) {
					card[i].SetCard('T', 'H');
				}
				else if (i + 1 == 11) {
					card[i].SetCard('J', 'H');
				}
				else if (i + 1 == 12) {
					card[i].SetCard('Q', 'H');
				}
				else {
					card[i].SetCard('K', 'H');
				}
			}
		}
		else if (i + 1 <= 39) {
			if (rnk <= '\x39')
				card[i].SetCard(rnk++, 'D');
			else
			{
				if (i + 1 == 10) {
					card[i].SetCard('T', 'D');
				}
				else if (i + 1 == 11) {
					card[i].SetCard('J', 'D');
				}
				else if (i + 1 == 12) {
					card[i].SetCard('Q', 'D');
				}
				else {
					card[i].SetCard('K', 'H');
				}
			}
		}
		else {
			if (rnk <= '\x39')
				card[i].SetCard(rnk++, 'D');
			else
			{
				if (i + 1 == 10) {
					card[i].SetCard('T', 'C');
				}
				else if (i + 1 == 11) {
					card[i].SetCard('J', 'C');
				}
				else if (i + 1 == 12) {
					card[i].SetCard('Q', 'C');
				}
				else {
					card[i].SetCard('K', 'C');
				}
			}
		}
		if ((i + 1) % 13 == 0)
			rnk = '\x31';
	}
}

Card Deck::Deal()
{
	cardsLeft--;
	return card[0];
}

int Deck::CardsLeft()
{
	return cardsLeft;
}

void Deck::ShowDeck()
{
	int index = 0;
	cout << "* * * * * * * * * * CURRENT DECK  * * * * * * * * * *"<< endl;
	for(int row = 0; row < 4; row++) {
	cout << "------------------------------------------------------" << endl;
		if(index < 13)
			while (index < 13)
			{
				card[index].Display();
				if (index != 12)
					cout << ", ";
				else
					cout << endl;
				index++;
			}
		else if (index < 26)
			while (index < 26)
			{
				card[index].Display();
				if (index != 25)
					cout << ", ";
				else
					cout << endl;
				index++;
			}
		else if (index < 39)
			while (index < 39)
			{
				card[index].Display();
				if (index != 38)
					cout << ", ";
				else
					cout << endl;
				index++;
			}
		else if (index < 52)
			while (index < 52)
			{
				card[index].Display();
				if (index != 51)
					cout << ", ";
				else
					cout << endl;
				index++;
			}
	}
}

void Deck::Shuffle()
{
	int first, second;
	Card temp;

	for (int i = 0; i < 10; i++)
	{
		first = rand() % 52;
		second = rand() % 52;
		temp = card[first];
		card[first] = card[second];
		card[second] = temp;
	}
}