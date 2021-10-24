#include "Dice.h"
#include <iostream>

using namespace std;

Dice::Dice()
{
	die1 = 0;
	die2 = 0;
}

Dice::~Dice()
{
}


void Dice::displayDice()
{
	cout << "\nYou rolled: " << die1 << " and " << die2 << "\n" << endl;
	
}

int Dice::getDie1()
{
	return die1;
}

int Dice::getDie2()
{
	return die2;;
}


