#include <iostream>

using std::cout;
using std::endl;

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

// TODO: define a new data type for pets


void greet(Species species) // TODO: change the parameter; then change the function body accordingly
{
  if (species == Species::DOG)
  {
    cout << "[Dog] Woof woof" << endl;
  }
  else if (species == Species::PIG)
  {
    cout << "[Pig] Oink oink" << endl;
  }
  else if (species == Species::CAT)
  {
    cout << "[Cat] (silence)" << endl; // cats just ignore others...
  }
  else if (species == Species::BUNNY)
  {
    cout << "[Bunny] (silence)" << endl; // bunnies are not that talkative...
  }
  else if (species == Species::UNKNOWN)
  {
    cout << "Hmm, what kind of animal is that?" << endl;
  }
  else
  {
    // If we add new possible values to the species type, but forget to consider these values
    // in this function, we will get an error message (if the function is called with such a new value).
    cout << "ERROR: seems like we forgot to consider this species in this function" << endl;
  }
}

int main()
{
  // TODO: reduce the number of variables using the new data type
  Species first_pet_species{ Species::BUNNY };
  unsigned first_pet_age{ 3 };

  Species second_pet_species{ Species::DOG };
  unsigned second_pet_age{ 5 };
  
  Species third_pet_species{ Species::PIG };
  unsigned third_pet_age{ 0 };
  
  Species fourth_pet_species{ Species::CAT };
  unsigned fourth_pet_age{ 7 };
  
  Species fifth_pet_species{ Species::UNKNOWN };
  unsigned fifth_pet_age{ 8 };
  
  // TODO: update these function calls accordingly
  greet(first_pet_species);
  greet(second_pet_species);
  greet(third_pet_species);
  greet(fourth_pet_species);
  greet(fifth_pet_species);
  
  return 0;
}
