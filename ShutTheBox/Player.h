#pragma once	// put this at the top of your header files
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	string name;
	int score;


public:
	Player(string name);
	virtual ~Player();
	void displayPlayer ();
	void AddScore(int score);

};

