#include <iostream>
#include <string>
#include <vector>




std::string stringBuilder(std::string s) {
    
    

    return 0;
}

int main(int argc, char** argv)
{
    std::cout << stringBuilder("3[a]2[bc]") << std::endl; // aaabcbc
    std::cout << stringBuilder("3[a2[c]]") << std::endl; // accaccacc
    std::cout << stringBuilder("2[abc]3[cd]ef") << std::endl; // abcabccdcdcef
    return 0;
}