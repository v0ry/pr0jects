#include <iostream>

using std::cout;
using std::endl;

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

void greet(Species species)
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
  else // this was not requested in the task description, but it helps detect errors
  {
    // If we add new possible values to the species type, but forget to consider these values
    // in this function, we will get an error message (if the function is called with such a new value).
    cout << "ERROR: seems like we forgot to consider this species in this function" << endl;
  }
}

int main()
{
  Species first_pet_species{ Species::BUNNY };
  Species second_pet_species{ Species::DOG };
  Species third_pet_species{ Species::PIG };
  Species fourth_pet_species{ Species::CAT };
  Species fifth_pet_species{ Species::UNKNOWN };

  greet(first_pet_species);
  greet(second_pet_species);
  greet(third_pet_species);
  greet(fourth_pet_species);
  greet(fifth_pet_species);

  return 0;
}
