#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

#define TABLE_LENGTH 4
#define DRINK_DECREASE 0.1

#define INVISIBLE_GUEST "Cannot handle orders from invisible guests"
#define EMPTY_DRINK "Cannot order empty drinks!" 
#define INVALID_SEAT "This seat does not exist!" 
#define SEAT_OCCUPIED "This seat is already occupied by someone else!" 

struct Student;

class Glass
{
  float liters_;

  public:
    Glass(float liters) : liters_{liters} {}

    void sip()
    {
      liters_ -= DRINK_DECREASE;
    }

    bool isEmpty() const
    {
      return liters_ < 0;
    }
};

class Plate
{
  float foodLeft_;

  public:
    Plate() : foodLeft_(1) {}

    void takeBite()
    {
      foodLeft_ *= 0.5f;
    }

    bool isFinished() const
    {
      return foodLeft_ < 0.1;
    }
};

struct Student
{
  std::unique_ptr<Glass> glass_;
  std::shared_ptr<Plate> plate_;

  bool hasDrink() const
  {
    return glass_ != nullptr;
  }

  void drink()
  {
    if (glass_ == nullptr)
      return;

    glass_->sip();
    if (glass_->isEmpty())
      glass_ = nullptr;
  }

  void eat()
  {
    if (plate_ != nullptr)
      plate_->takeBite();
  }

  void discardPlateIfFinished()
  {
    if (plate_ != nullptr && plate_->isFinished())
      plate_ = nullptr;
  }
};

struct Table
{
  std::array<std::unique_ptr<Student>, 2 * TABLE_LENGTH> students{};

  static size_t getOppositeIndex(size_t index)
  {
    return (index + 2 * TABLE_LENGTH - 1 - 2 * (index % TABLE_LENGTH)) % (2 * TABLE_LENGTH);
  }

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

    students.at(index) = std::make_unique<Student>();

    // set food pointer for opposite student
    size_t oppositeIndex = getOppositeIndex(index);
    if (students.at(oppositeIndex))
      students.at(index)->plate_ = students.at(oppositeIndex)->plate_;
  }

  void leave(std::istream& stream)
  {
    int index;

    stream >> index;
    if (!Table::checkSeat(index))
      return;
    students.at(index) = nullptr;
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

    students.at(index)->glass_ = std::make_unique<Glass>(liters);
  }

  void pass()
  {
    std::vector<std::reference_wrapper<Student>> reducedStudents{};

    for (auto& student : students)
    {
      if (student != nullptr)
        reducedStudents.push_back(*student);
    }

    if (reducedStudents.size() <= 1)
      //nothing to pass
      return;

    // rotate drinks clockwise
    // Here, std::move() is used to transfer the unique pointer into another unique pointer,
    // since copying is not possible (only one owner allowed). You do not have to know
    // std::move() in the exam. However, if you are curious, read up on move construction in C++.
    // (e.g., in chapter 4 (section "Move Semantics") of Josh Lospinoso (2019) "C++ Crash Course")
    auto previousDrink = std::move(reducedStudents.at(reducedStudents.size() - 1).get().glass_);
    for (auto student : reducedStudents)
    {
      auto currentDrink = std::move(student.get().glass_);
      student.get().glass_ = std::move(previousDrink);
      previousDrink = std::move(currentDrink);
    }
  }

  void orderFood(std::istream& stream)
  {
    int index;

    stream >> index;

    if (index > 2 * TABLE_LENGTH)
      std::cout << INVALID_SEAT;

    // create a new shared plate
    std::shared_ptr<Plate> plate = std::make_shared<Plate>();
    // give the plate to the students
    if (students.at(index))
      students.at(index)->plate_ = plate;
    
    size_t oppositeIndex = getOppositeIndex(index);
    if (students.at(oppositeIndex))
      students.at(oppositeIndex)->plate_ = plate;
  }

  void drink()
  {
    for (auto& student : students)
    {
      if (student != nullptr)
        student->drink();
    }
  }

  void eat()
  {
    for (auto& student : students)
    {
      if (student != nullptr)
        student->eat();
    }

    for (auto& student : students)
    {
      if (student != nullptr)
        student->discardPlateIfFinished();
    }    
  }

  void print()
  {
    printSpaced(
      [this] (size_t index)
      {
        std::cout << (students[index] != nullptr ? "M" : " ");
      }
    );
    std::cout << std::endl;

    printSpaced(
      [this] (size_t index)
      {
        std::cout << (students[index] != nullptr && students[index]->hasDrink() ? "o" : " ");
      }
    );
    std::cout << std::endl;

    printSpaced(
      [this] (size_t index)
      {
        size_t reverseIndex = 2 * TABLE_LENGTH - 1 - index;
        std::cout << (((students[index] && students[index]->plate_)
          || (students[reverseIndex] && students[reverseIndex]->plate_)) ? "O" : " ");
      }
    );
    std::cout << std::endl;

    printSpaced(
      [this] (size_t index)
      {
        size_t reverseIndex = 2 * TABLE_LENGTH - 1 - index;
        std::cout << (students[reverseIndex] != nullptr && students[reverseIndex]->hasDrink() ? "o" : " ");
      }
    );
    std::cout << std::endl;

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
