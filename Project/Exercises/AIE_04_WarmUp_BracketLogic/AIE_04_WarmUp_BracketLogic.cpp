#include <iostream>
#include <vector>
#include <stack>

//found on stack overflow - returns true of both are there

bool BracketPair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;	
	else if (opening == '<' && closing == '>')	return true;

	return false;
}

// TODO: create the bracketLogic method
bool bracketLogic(const std::string& string)
{
	std::stack<char> stack;
	int size = string.size();

	for (int i = 0; i < size; i++)
	{
		if (string[i] == '(' || string[i] == '{' || string[i] == '[' || string[i] == '<')	
			stack.push(string[i]);

		else if (string[i] == ')' || string[i] == ']' || string[i] == '}' || string[i] == '>')
		{
			if (stack.empty() || !BracketPair(stack.top(), string[i])) return false;			
			else stack.pop();			
		}
	}
	return stack.empty();
}

int main(int argc, char** argv)
{
	std::cout << std::boolalpha;
	std::cout << "Expected: true\t\t got: " << bracketLogic("[<>()]") << std::endl; //true
	std::cout << "Expected: false\t\t got: " << bracketLogic("[<(>)]") << std::endl;//false
	std::cout << "Expected: false\t\t got: " << bracketLogic("[(a*b+<7-c>+9]") << std::endl; //false 
	std::cout << "Expected: false\t\t got: " << bracketLogic("[{(h*i+3)-12]/4*x+2}") << std::endl; //false 
	std::cout << "Expected: true\t\t got: " << bracketLogic("[ab(c/d<e-f+(7*6)>)+2]") << std::endl; //true??
	return 0;
}
