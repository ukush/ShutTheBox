#pragma once
#include <iostream>
#include <malloc.h>
#include <string>
#include <vector>

using namespace std;

class Box
{
private:
	
	//int* tiles = (int*)malloc(sizeof(int) * 9);	// perhaps use a constant for 9 here and you would be better off creating the memory in the constructor
	int* tiles;
	vector<string> states;



public:

	Box(); // empty constructor

	/* I know I had a virtual destructor in a class that was never being derived from, but I did that to demonstrate the virtual keyword.  
	   If you know a class is not going to have derived classes, don't bother with virtual as all virtual functions have a slight run-time time 
		 overhead as the system looks for derived version - a rather moot point in fairness though*/
	virtual ~Box();		

	void setTiles();	// very moot point now, but perhaps a better name would be initaliseTiles

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
			if (states[roll - 1] == "down")	// why not just use an array of bools for this?
			{
				return true;
			}
			else
				return false;
		}
	}

	bool allTilesDown();


};

