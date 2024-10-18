#include <iostream>

#include "Pet.hpp"

using std::cout;
using std::endl;

// constructors -------------------------------------------------------------------------------------------------------
Pet::Pet() : species_{Species::UNKNOWN}, age_{0}, id_{cumulative_number_of_pets_}
{
  cumulative_number_of_pets_++;
  current_number_of_pets_++;
}

Pet::Pet(Species species) : species_{species}, age_{0}, id_{cumulative_number_of_pets_}
{
  cumulative_number_of_pets_++;
  current_number_of_pets_++;
}

Pet::Pet(Species species, unsigned age) : species_{species}, age_{age}, id_{cumulative_number_of_pets_}
{
  cumulative_number_of_pets_++;
  current_number_of_pets_++;
}

Pet::Pet(Pet& other) : species_{other.species_}, age_{other.age_}, id_{cumulative_number_of_pets_}
{
  cumulative_number_of_pets_++;
  current_number_of_pets_++;
}

// other member functions ---------------------------------------------------------------------------------------------
void Pet::greet()
{
  if (species_ == Species::DOG)
  {
    cout << "[Dog] Woof woof" << endl;
  }
  else if (species_ == Species::PIG)
  {
    cout << "[Pig] Oink oink" << endl;
  }
  else if (species_ == Species::CAT)
  {
    cout << "[Cat] (silence)" << endl; // cats just ignore others...
  }
  else if (species_ == Species::BUNNY)
  {
    cout << "[Bunny] (silence)" << endl; // bunnies are not that talkative...
  }
  else if (species_ == Species::UNKNOWN)
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

void Pet::happy_birthday()
{
  cout << "Happy birthday to me :D I am now " << ++age_ << " years old." << endl;
}