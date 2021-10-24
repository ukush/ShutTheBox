#pragma once
#include <iostream>
#include <malloc.h>
#include <string>
#include <vector>

using namespace std;

class Box
{
private:
	
	int* tiles = (int*)malloc(sizeof(int) * 9);
	vector<string> states;



public:

	Box(); // empty constructor

	virtual ~Box();

	void setTiles();

	void displayTiles();

	void shutTile(int roll) // inline due to high frequency of calls
	{
		// a user can shut a tile when:
		// The sum of the roll is equal to a tile number (between 0-9) that has not already been shut

		// first check if a tile has been shut#
		if (hasTileBeenShut(roll))
		{
			cout << "That tile has already been shut" << endl;
		}
		else
		{
			// shut the tile by changing the state from "up" to "down"
			states[roll - 1] = "down";
		}
	}

	bool hasTileBeenShut(int roll) // inline due to high frequency of calls
	{
		{
			if (states[roll - 1] == "down")
			{
				return true;
			}
			else
				return false;
		}
	}

	bool allTilesDown();


};

