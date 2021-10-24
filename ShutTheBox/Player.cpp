#include "Player.h"

Player::Player(string name) : name(name)
{
	score = 0;
}

Player:: ~Player(){}

void Player::displayPlayer ()
{
	cout << "\nPlayer Stats: " << endl;
	cout << "------------" << endl;
	cout << name << endl;
	cout << "Score: " << score << "\n" << endl;
}

void Player::AddScore(int score)
{
	this->score = score + score;
}
