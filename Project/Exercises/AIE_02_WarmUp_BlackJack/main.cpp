
#include <iostream>
#include <vector>
// TODO:
// Write the function


bool OverTwentyOne(std::vector<char> hand){
	int handValue = 0;
	bool aceExits = false;

	for (auto& c : hand)
	{
		if (c == 'A') {
			aceExits = true;
			handValue += 11;
		}
		if (isdigit(c)) handValue += c - '0';
		
		if (c == 'J' || c == 'Q' || c == 'K') handValue += 10;
		
		if (aceExits&& handValue > 21) handValue -= 10;
	}
	return handValue > 21;
}

int main(int argc, char** argv)
{
	// Test your code
	std::cout << std::boolalpha;
	std::cout << OverTwentyOne({ '2', '8', 'j' }) << std::endl;  //false
	std::cout << OverTwentyOne({ 'A', 'J', 'K' }) << std::endl; //false
	std::cout << OverTwentyOne({ '5', '5', '3','9' }) << std::endl; //true
	std::cout << OverTwentyOne({'2', '6', '4', '4', '5'}) << std::endl;//false
	std::cout << OverTwentyOne({ 'J', 'Q', 'K' }) << std::endl;//true
	
}

