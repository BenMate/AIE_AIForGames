#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


class Dictionary
{
public:
    Dictionary(const char* filename)
    {
        m_fileName = filename;
        std::string line;
        std::ifstream myFile;

        myFile.open(m_fileName);

        if (myFile.is_open())
        {
            // eof = end of file
            while (!myFile.eof())
            {
                std::getline(myFile, line);
                TheDictionary.push_back(line); //pushes each line onto the vector           
            }
        }
        else std::cout << "unable to open file" << std::endl;     

        myFile.close();
    };

    ~Dictionary()
    {
        //create function to remove all items in the vector
        TheDictionary.clear();
    }


    std::string toUpper(std::string str)
    {
        std::string upperStr;
        for (auto& c : str)
        {
            upperStr.push_back(std::toupper(c));
        }
        return upperStr;
    }

    bool Contains(const char* word)
    {
        //search the vector for the word 
        //doesnt work....
        //return (std::find(TheDictionary.begin(), TheDictionary.end(), word) != TheDictionary.end());

        return std::binary_search(TheDictionary.begin(), TheDictionary.end(), toUpper(word));
    }

protected:
private:
    std::string m_fileName;
    std::vector<std::string> TheDictionary;
};

int main(int argc, char** argv)
{
    {
        Dictionary dictionary("dictionary.txt");
        std::cout << std::boolalpha;
        std::cout << dictionary.Contains("hello") << std::endl;
        std::cout << dictionary.Contains("pilgrimaged") << std::endl;
        std::cout << dictionary.Contains("ejector") << std::endl;
        std::cout << dictionary.Contains("thisworddoesntexist") << std::endl;
        std::cout << dictionary.Contains("z") << std::endl;
    }
    return 0;
}
