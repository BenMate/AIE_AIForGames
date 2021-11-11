#include <iostream>
#include <iostream>
#include <initializer_list>


#include <algorithm>

// TODO:
// write the GetTotalCarsFromParts method

//NOT STEALING YOUR WORK OR ANYTHING :)
int GetTotalCarsFromParts(int wheels, int bodies, int figures)
{
    return std::min({ wheels / 4, bodies, figures / 2 });
}

/*
int GetTotalCarsFromParts(int wheels, int carParts, int people)
{
    if (wheels < 4) return 0;
    if (carParts < 1) return 0;
    if (people < 2) return 0;

    float completeWheels = wheels / 4;       
    float pairOfPeople = people / 2;     
    int CompleteCars = 0;

    //doesnt work
    for (int i = 0; i < carParts; i++)
    {
      completeWheels--;
      pairOfPeople--;
      carParts--;
  
      if (completeWheels == 0) break;
      if (pairOfPeople == 0) break;
      if (carParts == 0) break;
  
      CompleteCars++;
    }
    return CompleteCars;
}
*/

int main(int argc, char** argv)
{
    std::cout << GetTotalCarsFromParts(2, 48, 76) << std::endl;
    std::cout << GetTotalCarsFromParts(43, 15, 87) << std::endl;
    std::cout << GetTotalCarsFromParts(88, 37, 17) << std::endl;

    return 0;
}
