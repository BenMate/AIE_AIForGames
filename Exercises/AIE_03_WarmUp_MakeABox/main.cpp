
#include <iostream>
#include <string>
// TODO: create the makeBox method

void MakeBox(int num) {

	int wallSize = num - 2;
	int spaceSize = num;

	//calculated spacing
	if (spaceSize > 4) {
		spaceSize += 2;
	}

	//prints top
	for (int column = 0; column < num; column++)
	{
		std::cout << '*';
		std::wcout << " ";
	}

	std::cout << std::endl;

	for (int row = 0; row < wallSize; row++)
	{
		//prints left wall
		std::cout << '*';

		//prints space
		for (int column = 0; column < spaceSize; column++)
		{
			std::cout << " ";
		}

		//right wall
		std::cout << '*';

		std::cout << std::endl;
	}

	//prints bottom
	if (num > 1) {
		for (int column = 0; column < num; column++)
		{
			std::cout << '*';
			std::wcout << " ";
		}
	}

	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	// TODO: 
	// read command line args, extract dimensions
	// prompt if no commandline argumenst are specified


	std::string boxSize = "";
	if (argc >= 2)
	{
		boxSize = argv[1];
	}
	else {
		std::cout << "Enter a box size: ";
		std::cin >> boxSize;
	}

	int boxDimension = std::stoi(boxSize);
	MakeBox(boxDimension);

	MakeBox(5);
	MakeBox(3);
	MakeBox(2);
	MakeBox(1);

	return 0;
}
