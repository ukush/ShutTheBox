#include <iostream>
#include <string>

using namespace std;

#pragma once
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

