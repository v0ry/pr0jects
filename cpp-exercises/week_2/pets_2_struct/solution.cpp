#include <iostream>

using std::cout;
using std::endl;

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

struct Pet
{
  Species species_;
  unsigned age_;
};

void greet(Pet pet)
{
  if (pet.species_ == Species::DOG)
  {
    cout << "[Dog] Woof woof" << endl;
  }
  else if (pet.species_ == Species::PIG)
  {
    cout << "[Pig] Oink oink" << endl;
  }
  else if (pet.species_ == Species::CAT)
  {
    cout << "[Cat] (silence)" << endl; // cats just ignore others...
  }
  else if (pet.species_ == Species::BUNNY)
  {
    cout << "[Bunny] (silence)" << endl; // bunnies are not that talkative...
  }
  else if (pet.species_ == Species::UNKNOWN)
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
  // the Pet variables are also renamed in this solution to make the code easier to read (e. g., `bunny` is often better than `first_pet`)
  Pet bunny{ Species::BUNNY,   3 };
  Pet dog{   Species::DOG,     5 };
  Pet pig{   Species::PIG,     0 };
  Pet cat{   Species::CAT,     7 };
  Pet sheep{ Species::UNKNOWN, 8 };
  
  greet(bunny);
  greet(dog);
  greet(pig);
  greet(cat);
  greet(sheep);
  
  return 0;
}
