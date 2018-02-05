#include "Card.h"
#include "Deck.h"
#include <stdlib.h>

char SPACES [] = "                                         ";

void PrintMenu();

void Play(Deck&);

bool IsPrime(int&);

void ClearScreen();

int main() 
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 20;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consola"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	Deck deck;
	int ch;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xB);
	wcout << "\n\n\n" << SPACES << "Welcome to Solitaire Prime" << endl;
	wcout << endl << endl << endl << endl << endl << endl << endl << endl;
	wcout << SPACES;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA);
	system("PAUSE");
	system("CLS");
	cout << endl;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 16;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consola"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	while (1)
	{
		PrintMenu();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
		wcout << SPACES <<"choice: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x9);
		cin >> ch;
		wcout << endl << endl;
		ClearScreen();
		wcout << endl << endl;

		switch (ch)
		{
		case 1:
			deck.RefreshDeck();
			break;
		case 2:
			deck.ShowDeck();
			break;
		case 3:
			deck.Shuffle();
			break;
		case 4:
			Play(deck);
			deck.RefreshDeck();
			break;
		default:
			return 0;
		}
	}
	system("Pause");
	return 0;
}

void PrintMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	wcout << SPACES << "1) New Deck" << endl;
	wcout << SPACES << "2) Display Deck" << endl;
	wcout << SPACES << "3) Shuffle Deck" << endl;
	wcout << SPACES << "4) Play Solitaire Prime" << endl;
	wcout << SPACES << "5) Exit" << endl << endl << endl;
}

void Play(Deck& deck)
{
	int sum = 0, hands = 0;
	Card card;
	wcout << SPACES;
	while (deck.CardsLeft() > 0) 
	{
		card = deck.Deal();
		sum += card.GetValue();
		card.Display();
		wcout << "(" << sum << "), ";
		if (IsPrime(sum))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
			wcout << "Prime: " << sum << endl << SPACES;
			sum = 0;
			hands++;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | 2 | 4));
	if (sum != 0)
	{
		wcout << endl << SPACES << "You Lose" << endl;
	}
	else {
		wcout << "You Won in " << hands << " hands" << endl;
	}
	wcout << endl;
}

bool IsPrime(int& n)
{
	int i = 2;
	int max = sqrt(n);
	if (n == 1)
		return false;
	while (i <= max)
	{
		if (n % i++ == 0)
			return false;
	}
	return true;
}

void ClearScreen()
{
	system("CLS");
}