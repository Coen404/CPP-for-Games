#include <iostream>
#include <string>
#include <limits>

int main()
{
	std::string name;
	int age;

	std::cout << "What is your name?" << std::endl;
	std::cin >> name;

	std::cout << "What is your age?" << std::endl;
	std::cin >> age;

	while (std::cin.fail())
	{
		std::cout << "ERROR: PLEASE INPUT A NUMBER." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> age;
	}

	std::cout << "Hello, " << name;
	std::cout << ". You are " << age << " years old." << std::endl;
}