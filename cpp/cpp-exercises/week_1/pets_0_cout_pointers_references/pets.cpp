// if you use cout (encouraged), you will need these three lines:
#include <iostream>
using std::cout;
using std::endl;

// if you want to use printf, you will need this line:
#include <cstdio>
// you can try cout as well as printf in order to compare these two solutions

// TODO: write the missing functions here


int main()
{
  char first_pet_species[] = "bunny";
  unsigned first_pet_age = 3;
  char second_pet_species[] = "dog";
  unsigned second_pet_age = 14;
  
  printPetInfo(first_pet_species, first_pet_age); // "That's a 3-year-old bunny.\n"
  printPetInfo(second_pet_species, second_pet_age); // "That's a 14-year-old dog.\n"
  
  happyBirthdayWithPointer(&first_pet_age);
  happyBirthdayWithReference(second_pet_age);
  
  printPetInfo(first_pet_species, first_pet_age); // "That's a 4-year-old bunny.\n"
  printPetInfo(second_pet_species, second_pet_age); // "That's a 15-year-old dog.\n"
  
  return 0;
}
