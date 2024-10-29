#include <iostream>

using std::cout;
using std::endl;

enum class Species {DOG, PIG, CAT, BUNNY, UNKNOWN};

struct Pet
{
  private:
    Species species_;
    unsigned age_;

  public:
    Pet() : species_{Species::UNKNOWN}, age_{0} {}

    Pet(Species species) : species_{species}, age_{0} {}

    Pet(Species species, unsigned age)
      : species_{species}, age_{age}
      {}
    
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

    void happy_birthday()
    {
      cout << "Happy birthday to me :D I am now " << ++age_ << " years old." << endl;
    }
};

int main()
{
  // TODO: Replace "TODO" in the following line with the number of pets created so far.
  //       To this end, use the class method getNumberOfPets.
  cout << "At the start of our program we have " << "TODO" << " pets." << endl;

  Pet bunny{ Species::BUNNY,   3 };
  bunny.greet();
 
  Pet dog{   Species::DOG,     5 };
  dog.greet();

  Pet pig{   Species::PIG,     0 };
  pig.greet();

  Pet cat{   Species::CAT,     7 };
  cat.greet();

  Pet sheep{ Species::UNKNOWN, 8 };
  sheep.greet();

  Pet baby; // equivalent to `Pet baby{};`
  baby.greet();
  
  Pet puppy{ Species::DOG };
  puppy.greet();

  // TODO: Replace "TODO" in the following line with the number of pets created so far.
  //       To this end, use the class method getNumberOfPets.
  cout << "At the end of our program we have " << "TODO" << " pets." << endl;
  
  return 0;
}
