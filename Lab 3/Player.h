#pragma once
#include <iostream>

class Player
{
public:
	Player() {};
	~Player() {};
	void jump() { std::cout << "Player Jumped." << std::endl; };
	void shoot() { std::cout << "Player shot." << std::endl; };
	void crouch() { std::cout << "Player crouched." << std::endl; };
	void shield() { std::cout << "Player shielded." << std::endl; };
	void melee() { std::cout << "Player melee." << std::endl; };
	void undojump() { std::cout << "Undo Jump." << std::endl; };
	void undoshoot() { std::cout << "Under shot." << std::endl; };
	void undocrouch() { std::cout << "Undo crouch." << std::endl; };
	void undoshield() { std::cout << "Undo shield." << std::endl; };
	void undomelee() { std::cout << "Undo melee." << std::endl; };
};