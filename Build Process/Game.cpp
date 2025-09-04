#include "Config.hpp"
#include "Game.hpp"

#include <iostream>

// Function Definition.
void Update()
{

	JumpHeight = 10.0f;
	WalkSpeed = 2.0f;

	std::cout << "\nUpdate Function Called!\n" << std::endl;

	std::cout << "JumpHeight: " << JumpHeight << std::endl;
	std::cout << "JumpDuration: " << JumpDuration << std::endl;
	std::cout << "WalkSpeed: " << WalkSpeed << std::endl;

}