#include "Box.h"


Box::Box()
{
	tiles=(int*) malloc(sizeof(int) * 9);
}

Box::~Box()
{
	free(tiles);
	
}

void Box::setTiles()
{
	for (int i = 0; i < 9; i++)	// you can see how a constant would be useful as opposed to 9 here
	{
		tiles[i] = i + 1;
	}

	// as you are using the same box instance for each round, you probably need to clear the states vector here else round you add 9 more "up"s
	for (int i = 0; i < 9; i++)
	{
		// set all states to up
		states.push_back("up");
	}
}


bool Box::allTilesDown()
{
	int down = 0;

	for (int i = 0; i < 9; i++)
	{
		if (states[i] == "down")
		{
			++down;
		}
	}
	
	/*if (down != 9)
	{
		return false;
	}
	else return true;*/
	return (down==9);
}




void Box::displayTiles()
{
	for (int i = 0; i < 9; i++)
	{
		cout << tiles[i] << "\t";
	}
	cout << endl;
	
	for (int i = 0; i < 9; i++)
	{
		cout << states[i] << "\t";
	}
	cout << "\n " << endl;
}
