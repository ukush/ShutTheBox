#include "Box.h"


Box::Box()
{

}

Box::~Box()
{
	free(tiles);
	
}

void Box::setTiles()
{
	for (int i = 0; i < 9; i++)
	{
		tiles[i] = i + 1;
	}

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
	
	if (down != 9)
	{
		return false;
	}
	else return true;
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
