#include <iostream>

using std::cout;
using std::endl;

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

struct Pet
{
  // TODO: make the member variables only accessible inside the class
  Species species_;
  unsigned age_;

  void greet()
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
};

// TODO: move this function into the `Pet` class and change it accordingly
//       (and change the text according to the task description)
void happy_birthday(Pet& pet)
{
  cout << "Happy birthday! This pet is " << ++pet.age_ << " years old now." << endl;
}

int main()
{
  Pet bunny{ Species::BUNNY,   3 };
  Pet dog{   Species::DOG,     5 };
  Pet pig{   Species::PIG,     0 };
  Pet cat{   Species::CAT,     7 };
  Pet sheep{ Species::UNKNOWN, 8 };

  bunny.greet();
  dog.greet();
  pig.greet();
  cat.greet();
  sheep.greet();

  // TODO: adapt the following lines accordingly
  cout << "\n" << "Our pets celebrate their birthdays." << endl;
  happy_birthday(bunny); // 4th birthday
  happy_birthday(dog);
  happy_birthday(pig);
  happy_birthday(cat);
  happy_birthday(sheep);

  cout << "\n" << "Happy b-day once again!" << endl;
  happy_birthday(bunny); // 5th birthday
  happy_birthday(dog);
  happy_birthday(pig);
  happy_birthday(cat);
  happy_birthday(sheep);

  return 0;
}
