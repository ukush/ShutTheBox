#include <iostream>
#include <string>
#include "Player.h"
#include "Box.h"
#include "Dice.h"

using namespace std;

bool endRound(int score);

int main()
{

#ifdef _DEBUG
	//_CrtSetBreakAlloc(256);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	//seed random numbers
	srand(time(nullptr));

	
	string name;
	int numOfRounds;
	char roll;
	int score = 0;
	const int MAX_TURNS = 5; // max number of rolls per round per player
	int turn = 0;
	bool cannotShutAnyMore = false;


	cout << "Welcome to Shut the Box" << endl;
	cout << "To start the game, please enter your name: " << endl;
	cin >> name;
	cout << "Hi " << name << ", how many round would you like to play?" << endl;
	cin >> numOfRounds;

	// create object pointer
	Player* player1 = new Player(name);

	// print out player details
	//player1->displayPlayer();

	// play game for n rounds
	Box* box = new Box();
	box->setTiles();

	// instantiate dice object
	Dice* dice = new Dice();

	for (int i = 1; i <= numOfRounds; i++)
	{
		// I think you might also need to reset cannotShutAnyMore to false here too as well as turn?
		
		// reset the tiles for the next round
		box->setTiles();

		cout << "Round " << i << ":\n" << endl;
		do
		{
			// display tiles
			box->displayTiles();

			// prompt user to roll dice
			cout << "Enter any key and press Enter to roll the dice!" << endl;
			cin >> roll;

			// roll dice and display to console
			dice->rollDice();
			dice->displayDice();

			int d1 = dice->getDie1();
			int d2 = dice->getDie2();

			// get the sum of the roll
			roll = d1 + d2;

			int option;

			// this section could perhaps do with breaking down into smaller methods, but again, perhaps a moot point.
			if (roll < 10 && (d1 != d2))
			{
				if ((!box->hasTileBeenShut(d1) && !box->hasTileBeenShut(d2) && !box->hasTileBeenShut(roll))) // if all tiles are up
				{
					score += roll; // the score is incremented by the sum of dice regardless of which option they choose

					//give user the option to choose which tiles to shut
					cout << "You have the choice to shut the following tiles: " << endl;
					cout << "Option 1: Tiles " << d1 << " and " << d2 << endl;
					cout << "Option 2: Tile " << roll << endl;
					cout << "Please select below: " << endl;
					cin >> option;

					if (option == 1)
					{
						box->shutTile(d1);
						box->shutTile(d2);
					}
					else
						box->shutTile(roll);
				}
				else if ((box->hasTileBeenShut(d1) || box->hasTileBeenShut(d2)) && !box->hasTileBeenShut(roll)) // can only use the sum
				{
					score += roll;
					cout << "You can only shut tile " << roll << endl;
					box->shutTile(roll);
				}
				else if ((!box->hasTileBeenShut(d1) && !box->hasTileBeenShut(d2)) && box->hasTileBeenShut(roll)) // use can only do both
				{
					box->shutTile(d1);
					box->shutTile(d2);
					score += roll;
				}
				else // all are shut
				{
					cannotShutAnyMore = endRound(score);
				}
			}
			else if ((roll < 10) && (d1 == d2))
			{

				 if (box->hasTileBeenShut(d1) && !box->hasTileBeenShut(roll))
				{
					// can only use sum
					 cout << "You can only shut tile " << roll << endl;
					 box->shutTile(roll);
				}
				else
				{
					// cannot use a single die by itself
					 cannotShutAnyMore = endRound(score);
				}
			}
			else if (roll >= 10 && (d1 != d2))// if the roll is more than 10
			{
				// check both (not roll)
				if (!box->hasTileBeenShut(d1) && !box->hasTileBeenShut(d2)) // only shut if both are up
				{
					box->shutTile(d1);
					box->shutTile(d2);
				}
				else // cant use sum
				{
					// end the round
					cannotShutAnyMore = endRound(score);
				}
			}
			else if (roll >= 10 && (d1 == d2))
			{
				// use d1
				if (!box->hasTileBeenShut(d1))
				{
					cout << "You can only shut tile " << d1 << endl;
					box->shutTile(d1);
				}
				else
				{
					// end the round
					cannotShutAnyMore = endRound(score);

				}
			}

			turn++;

		} while ((!box->allTilesDown()) || (turn > MAX_TURNS) || (cannotShutAnyMore));	// not entirely sure this condition is correct for the while loop, but I guess if it works, it works

			cout << "Round : " << i << " Complete" << endl;
			
			// add score to player
			player1->AddScore(score);
			player1->displayPlayer();

	} 
			// release memory
			delete dice;
			delete player1;
			delete[] box; // calls the deconstructor which releases array memory

	return 0;
}


bool endRound(int score)
{
	cout << "You cannot shut any more tiles. The round is over" << endl;
	cout << "Your score for this round is: " << score << endl;
	
	return true;
}



