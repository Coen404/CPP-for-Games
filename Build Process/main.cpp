#include "Config.hpp"
#include "Game.hpp"

#include <iostream>

int main()
{
	std::cout << "JumpHeight: " << JumpHeight << std::endl;
	std::cout << "JumpDuration: " << JumpDuration << std::endl;
	std::cout << "WalkSpeed: " << WalkSpeed << std::endl;

	Update();

	return 0;
}