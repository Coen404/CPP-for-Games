#include <fstream>
#include <iostream>

struct highscore
{
	char name[4];
	uint32_t score;
};

int main()
{
	// Write ascii files.
	{
		std::ofstream highscores("highscores.txt");
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open highscores.txt for writing!" << std::endl;
			return 1;
		}

		highscores << "Coen " << 2014 << std::endl;
		highscores << "Mikey " << 1923 << std::endl;
		highscores << "Jozua " << 1 << std::endl;
		highscores << "Rushil " << 67 << std::endl;

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not write to highscores.txt!" << std::endl;
			return 1;
		}

		highscores.close();
		// File will close when it goes out of scope.
	}

	{
		std::ofstream highscores("highscores.txt", std::ios::app);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open highscores.txt for appending!" << std::endl;
			return 1;
		}

		highscores << "Henk " << 42 << std::endl;

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not write to highscores.txt!" << std::endl;
			return 1;
		}

		highscores.close();
	}
	{
		std::ifstream highscores("highscores.txt");
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open highscores.txt for reading!" << std::endl;
			return 1;
		}

		std::string name;
		int score;
		while (highscores >> name >> score)
		{
			std::cout << name << " has score " << score << std::endl;
		}

		if (highscores.bad())
		{
			std::cerr << "ERROR: Reading the file." << std::endl;
			return 1;
		}

		highscores.close();
		// File will be closed when it goes out of scope.
	}

	// Writing binary files
	{
		std::ofstream highscores("highscores.bin", std::ios::binary);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open highscores.bin." << std::endl;
			return 1;
		}

		highscore scores[] = {
			{"Con", 2014},
			{"Mik", 1923},
			{"Joz", 1},
			{"Rus", 67},
			{"Hnk", 42 }
		};
		auto numScores = std::size(scores);

		highscores.write(reinterpret_cast<const char*>(&numScores), sizeof(numScores));
		highscores.write(reinterpret_cast<const char*>(scores), numScores * sizeof(highscore));

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not write to highscores.bin!" << std::endl;
			return 1;
		}

		highscores.close();
	}

	std::cout << std::endl;

	{
		std::ifstream highscores("highscores.bin", std::ios::binary);
		if (!highscores)
		{
			std::cerr << "ERROR: Could not open highscores.bin." << std::endl;
			return 1;
		}

		size_t numEntries;
		highscores.read(reinterpret_cast<char*>(&numEntries), sizeof (numEntries));

		highscore* scores = new highscore[numEntries];

		highscores.read(reinterpret_cast<char*>(scores), numEntries * sizeof(highscore));

		if (highscores.bad())
		{
			std::cerr << "ERROR: Could not read from highscores.bin!" << std::endl;
			return 1;
		}

		for (int i = 0; i <numEntries; ++i)
		{
			std::cout << scores[i].name << " " << scores[i].score << std::endl;
		}

		delete[] scores;

		highscores.close(); // return any system resources!
	}
	return 0;
}