#include <iostream>
#include <vector>

char CupSwap(std::vector<std::string>const& cups)
{
    char ballPos = 'B'; //ball always starts at b

    for (int i = 0; i < cups.size(); i++)
    {
        //swap the position of ball
       
        if (cups[i] == "AB") 
        {
            if (ballPos == 'A') ballPos = 'B';
            else if (ballPos == 'B') ballPos = 'A';
        }

        if (cups[i] == "BA")
        {
            if (ballPos == 'A') ballPos = 'B';
            else if (ballPos == 'B') ballPos = 'A';
        }

        if (cups[i] == "CA")
        {
            if (ballPos == 'C') ballPos = 'A';
            else if (ballPos == 'A') ballPos = 'C';
        }

        if (cups[i] == "AC")
        {
            if (ballPos == 'C') ballPos = 'A';
            else if (ballPos == 'A') ballPos = 'C';
        }

        if (cups[i] == "BC")
        {
            if (ballPos == 'C') ballPos = 'B';
            else if (ballPos == 'B') ballPos = 'C';
        }

        if (cups[i] == "CB")
        {
            if (ballPos == 'C') ballPos = 'B';
            else if (ballPos == 'B') ballPos = 'C';
        }     
    }
    //returns new value of ball
    return ballPos;
}

int main(int argc, char** argv)
{
    std::cout << CupSwap({ "AB", "CA", "AB" }) << std::endl;  // C
    std::cout << CupSwap({ "AB", "CA" }) << std::endl; // C
    std::cout << CupSwap({ "AC", "CA", "CA", "AC" }) << std::endl; // B
    std::cout << CupSwap({ "BA", "AC", "CA", "BC" }) << std::endl; // A

    std::cout << CupSwap({ "BA", "AB"}) << std::endl; // B
    std::cout << CupSwap({ "DA", "BW" }) << std::endl;//should stay B

    return 0;
}
