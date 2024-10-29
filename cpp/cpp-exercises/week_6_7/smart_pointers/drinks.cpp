#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

#define TABLE_LENGTH 4

#define INVISIBLE_GUEST "Cannot handle orders from invisible guests"
#define EMPTY_DRINK "Cannot order empty drinks!" 
#define INVALID_SEAT "This seat does not exist!" 
#define SEAT_OCCUPIED "This seat is already occupied by someone else!" 

// TODO: Add additional classes (e.g. Student or Glass) that represent the needed objects.

struct Table
{
  // TODO: Add a smart pointer to an object that represents the students
  //       on their seats.
  std::array</* Your Pointer Type Here */, 2 * TABLE_LENGTH> students{};

  /**
   * Get the index opposite of the seat with the given index
   * 
   * @param index the given index
   * @return size_t the opposite index
   */
  static size_t getOppositeIndex(size_t index)
  {
    return (index + 2 * TABLE_LENGTH - 1 - 2 * (index % TABLE_LENGTH)) % (2 * TABLE_LENGTH);
  }

  /**
   * Check whether a given index is a valid index for a seat.
   * 
   * @param index the index to check
   * @return true when the index is valid
   */
  static bool checkSeat(size_t index)
  {
    if (index >= 2 * TABLE_LENGTH)
    {
      std::cout << INVALID_SEAT << std::endl;
      return false;
    }
    return true;
  }

  void sit(std::istream& stream)
  {
    int index;

    stream >> index;
    if (!Table::checkSeat(index))
      return;
    if (students.at(index) != nullptr)
    {
      std::cout << SEAT_OCCUPIED << std::endl;
      return;
    }
  
    // TODO: Implement the sit command
  }

  void leave(std::istream& stream)
  {
    int index;

    stream >> index;
    if (!Table::checkSeat(index))
      return;
  
    // TODO: Implement the leave command
  }

  void order(std::istream& stream)
  {
    int index;
    float liters;

    stream >> index;
    stream >> liters;

    if (!Table::checkSeat(index))
      return;
    if (students.at(index) == nullptr)
    {
      std::cout << INVISIBLE_GUEST << std::endl;
      return;
    }
    if (liters < 0)
    {
      std::cout << EMPTY_DRINK << std::endl;
      return;
    }

    // TODO: Implement the order command
  }

  void pass()
  {
    // TODO: implement the pass command
  }

  void orderFood(std::istream& stream)
  {
    int index;

    stream >> index;

    if (index > 2 * TABLE_LENGTH)
      std::cout << INVALID_SEAT;

    // TODO: implement the food command
  }

  void drink()
  {
    // TODO: implement the drink command
  }

  void eat()
  {
    // TODO: implement the eat command
  }

  /**
   * Print the table
   * 
   */
  void print()
  {
    // print the upper student row
    printSpaced(
      [this] (size_t index)
      {
        std::cout << (students[index] != nullptr ? "M" : " ");
      }
    );
    std::cout << std::endl;

    // print the upper drinks row
    printSpaced(
      [this] (size_t index)
      {
        // TODO: check if the student at index has a drink
        std::cout << "o";
      }
    );
    std::cout << std::endl;

    // print the Plates
    printSpaced(
      [this] (size_t index)
      {
        // TODO: fill in the placeholder comments for your implementation
        size_t reverseIndex = 2 * TABLE_LENGTH - 1 - index;
        std::cout << (((students[index] && /* students[index]->hasPlate() */)
          || (students[reverseIndex] && /* students[reverseIndex]->plate_) */) ? "O" : " ");
      }
    );
    std::cout << std::endl;

    // Print the lower drinks row
    printSpaced(
      [this] (size_t index)
      {
        // TODO: fill in the placeholder comment for your implementation
        size_t reverseIndex = 2 * TABLE_LENGTH - 1 - index;
        std::cout << (students[reverseIndex] != nullptr && /* students[reverseIndex]->hasDrink() */ ? "o" : " ");
      }
    );
    std::cout << std::endl;

    // print the lower students row
    printSpaced(
      [this] (size_t index)
      {
        std::cout << (students[ 2 * TABLE_LENGTH - 1 - index] != nullptr ? "W" : " ");
      }
    );
    std::cout << std::endl;
  }
private:
  static void printSpaced(std::function<void(size_t)> printCharacter)
  {
    for (int index = 0; index < 2 * TABLE_LENGTH - 1; index++)
    {
      if (index % 2)
        std::cout << " ";
      else
        printCharacter(index / 2);
    }
  }
};

bool handleInput(std::istream& stream, Table& table)
{
  std::string command;

  stream >> command;
  
  if (command == "quit")
    return true;
  else if (command == "sit")
    table.sit(stream);
  else if (command == "leave")
    table.leave(stream);
  else if (command == "order")
    table.order(stream);
  else if (command == "pass")
    table.pass();
  else if (command == "food")
    table.orderFood(stream);
  else if (command == "drink")
    table.drink();
  else if (command == "eat")
    table.eat();
  else
    std::cout << "Unkown Command!" << std::endl;

  return false;
}

int main()
{
  Table table{};

  std::string line;
  bool quit = false;

  while (!quit)
  {
    table.print();
    std::cout << "> ";

    if (!std::getline(std::cin, line))
      break;

    if (line.empty())
      continue;

    std::istringstream stream{line};

    quit = handleInput(stream, table);
  }

}
