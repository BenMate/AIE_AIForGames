#include <iostream>


bool validateEmail(std::string email) 
{
    bool hasSymbal = false;
    bool hasDot = false;

    int size = email.size();

    for (int i = 0; i < size; i++)
    {
        if (email[i] == '@')
        {
           
            if (i == 0)         
                return false;

            else if (hasSymbal) 
                return false;

            else if (hasDot)    
                return false;

            hasSymbal = true; 
        }

        if (email[i] == '.')
        {            
            if (!hasSymbal)   
                return false;
         
            else if (email[i + 1] == '.')
                return false;

            hasDot = true;
        }
    }
    return (hasSymbal && hasDot);
}


int main(int argc, char** argv)
{
    std::cout << validateEmail("@gmail.com") << std::endl;       //false
    std::cout << validateEmail("hello.gmail@com") << std::endl;  //false
    std::cout << validateEmail("gmail") << std::endl;            //false
    std::cout << validateEmail("hello@gmail") << std::endl;      //false
    std::cout << validateEmail("hello @gmail") << std::endl;      //false
    std::cout << validateEmail("test@domain..com") << std::endl; //false  (double dot after @) - not aloud
    std::cout << validateEmail("test@sub.domain.com") << std::endl; //true - sub domain aloud
    std::cout << validateEmail("hello@edabit.com") << std::endl; // true
    return 0;
}

