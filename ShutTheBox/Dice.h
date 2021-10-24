#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Dice
{
private:
	int die1;
	int die2;


public:
	Dice();
	virtual ~Dice();
	
	void rollDice() // inline method for increased performance
	{
		// Rolling the dice means assign each die a value at random.
		// The values can be between 1-6

		const int MAX_RANGE = 6;
		const int MIN_RANGE = 1;

		// randomly generate number between 1 and 6

		die1 = (rand() % MAX_RANGE) + MIN_RANGE;
		die2 = (rand() % MAX_RANGE) + MIN_RANGE;
	}
	
	void displayDice();

	int getDie1();
	int getDie2();

};

