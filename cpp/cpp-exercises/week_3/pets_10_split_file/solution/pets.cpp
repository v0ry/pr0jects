#include <iostream>

#include "Pet.hpp"

using std::cout;
using std::endl;

int main()
{
  Pet bunny{ Species::BUNNY,   3 };
  bunny.greet();
 
  Pet dog{   Species::DOG,     5 };
  dog.greet();

  {
    Pet pig{   Species::PIG,     0 };
    pig.greet();
    cout << "We currently have " << Pet::getCurrentNumberOfPets() << " pets." << endl;
    cout << "We have seen " << Pet::getCumulativeNumberOfPets() << " pets so far." << endl;
    cout << "... about to call destructor of pet with ID " << pig.getId() << " ..." << endl;
  } // destructor of pig is called because our pig's lifetime ends here :(

  Pet cat{   Species::CAT,     7 };
  cat.greet();

  Pet sheep{ Species::UNKNOWN, 8 };
  sheep.greet();

  Pet dolly{ sheep };
  dolly.greet();

  cout << "We currently have " << Pet::getCurrentNumberOfPets() << " pets." << endl;
  cout << "We have seen " << Pet::getCumulativeNumberOfPets() << " pets so far." << endl;
  cout << "Last pet has the ID " << dolly.getId() << "." << endl;

  if (cat.getSpecies() == Species::CAT)
  {
    cout << "The cat with ID " << cat.getId() << " is " << cat.getAge() << " years old.\n";
  }
  cat.greet();
  cat.happy_birthday();
  
  return 0;
}
