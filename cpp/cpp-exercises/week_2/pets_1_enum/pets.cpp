#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

// TODO write your enum class here


// TODO change the greet function, such that it uses the enum class
void greet(char* species)
{
  if (strcmp(species, "dog") == 0)
  {
    cout << "[Dog] Woof woof" << endl;
  }
  else if (strcmp(species, "pig") == 0)
  {
    cout << "[Pig] Oink oink" << endl;
  }
  else if (strcmp(species, "cat") == 0)
  {
    cout << "[Cat] (silence)" << endl; // cats just ignore others...
  }
  else if (strcmp(species, "bunny") == 0)
  {
    cout << "[Bunny] (silence)" << endl; // bunnies are not that talkative...
  }
  else
  {
    cout << "Hmm, what kind of animal is that?" << endl;
  }
}

// TODO: change the main function, such that it uses the enum class
int main()
{
  char first_pet_species[]{ "bunny" };
  char second_pet_species[]{ "dog" };
  char third_pet_species[]{ "pig" };
  char fourth_pet_species[]{ "cat" };
  char fifth_pet_species[]{ "sheep" }; // a sheep shall be an unknown species in this example
  
  greet(first_pet_species);
  greet(second_pet_species);
  greet(third_pet_species);
  greet(fourth_pet_species);
  greet(fifth_pet_species);
  
  return 0;
}
