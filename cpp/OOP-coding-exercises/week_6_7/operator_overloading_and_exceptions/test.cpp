#include <iostream>
#include <sstream>
#include <cassert>
#include "Fraction.hpp"
#include "DivideByZeroException.hpp"

/**
  * If you have not implemented all functionality yet, you can simply
  * deselect the testcases by setting the corresponding define to 0.
  * Then your programm will compile and you can test the other testcases.
  */
#define CONSTRUCTORS 1
#define CONSTRUCTOR_NULL_DIVISION_EXCEPTION 1
#define REDUCE_FRACTION 1
#define COPY_ASSIGNMENT 1
#define OUT_OPERATOR 1
#define PLUS_OPERATORS 1
#define PLUS_OPERATORS_WITH_INT 1
#define INCREMENT_OPERATORS 1
#define NEGATION_INVERSION_DIVISION 1
#define BOOL_OPERATOR 1
#define BOOL_OPERATOR_COMPILATION_FAILER 0 // if this is set to 1, compilation
  // has to fail, otherwise the bool-operator is not declared 'explicit'
#define COMPARE_OPERATORS 1

void constructors();
void constructorDivideByZeroException();
void reduceFraction();
void copyAssignment();
void outOperator();
void plusOperators();
void plusOperatorsWithInt();
void incrementOperators();
void negationInversionDivision();
void boolOperators();
void compareOperators();

//------------------------------------------------------------------------------
int main(void)
{
  std::cout << "Starting testcases!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

  constructors();
  constructorDivideByZeroException();
  reduceFraction();
  copyAssignment();
  outOperator();
  plusOperators();
  plusOperatorsWithInt();
  incrementOperators();
  negationInversionDivision();
  boolOperators();
  compareOperators();

  std::cout << "Great! Passing all selected testcases!" << std::endl;

  return 0;
}

//------------------------------------------------------------------------------
void constructors()
{
#if CONSTRUCTORS == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a;
  Fraction b(5);
  Fraction c(1, 10);
  Fraction d(0, 100);

  std::cout << a.getNominator() << " / " << a.getDenominator() << std::endl;
  std::cout << b.getNominator() << " / " << b.getDenominator() << std::endl;
  std::cout << c.getNominator() << " / " << c.getDenominator() << std::endl;

  assert(a.getNominator() == 0 && a.getDenominator() == 1 &&
    "Default constructor not correct!\n");
  assert(b.getNominator() == 5 && b.getDenominator() == 1 &&
    "Constructor with one paramter not correct!\n");
  assert(c.getNominator() == 1 && c.getDenominator() == 10 &&
    "Constructor with two parameters not correct!\n");
  assert(d.getNominator() == 0 && d.getDenominator() == 1 &&
    "Constructor with two parameters when value 0 not correct!\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void constructorDivideByZeroException()
{
#if CONSTRUCTOR_NULL_DIVISION_EXCEPTION == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  try
  {
    Fraction a(2, 0);

    std::cout << a.getNominator() << " / " << a.getDenominator() << std::endl;

    assert(false && "No DivideByZeroException thrown!\n");
  }
  catch (DivideByZeroException& ex)
  {
    std::cout << "Error: " << ex.what();

    assert(std::string(ex.what()) == "0 in the denominator invalid!\n"
      && "DivideByZeroException not correct!\n");
  }

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void reduceFraction()
{
#if REDUCE_FRACTION == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(2, 6);
  Fraction b(65, -26);
  Fraction c(-123, 126);
  Fraction d(-12, -144);

  std::cout << a.getNominator() << " / " << a.getDenominator() << std::endl;
  std::cout << b.getNominator() << " / " << b.getDenominator() << std::endl;
  std::cout << c.getNominator() << " / " << c.getDenominator() << std::endl;
  std::cout << d.getNominator() << " / " << d.getDenominator() << std::endl;

  assert(a.getNominator() == 1 && a.getDenominator() == 3 &&
    "Reducing fraction not correct!\n");
  assert(b.getNominator() == -5 && b.getDenominator() == 2 &&
    "Reducing fraction not correct!\n");
  assert(c.getNominator() == -41 && c.getDenominator() == 42 &&
    "Reducing fraction not correct!\n");
  assert(d.getNominator() == 1 && d.getDenominator() == 12 &&
    "Reducing fraction not correct!\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void copyAssignment()
{
#if COPY_ASSIGNMENT == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(13, -169);
  Fraction b(a);
  Fraction c(20);
  Fraction d;

  a = c = d;

  std::cout << a.getNominator() << " / " << a.getDenominator() << std::endl;
  std::cout << b.getNominator() << " / " << b.getDenominator() << std::endl;
  std::cout << c.getNominator() << " / " << c.getDenominator() << std::endl;
  std::cout << d.getNominator() << " / " << d.getDenominator() << std::endl;

  assert(a.getNominator() == 0 && a.getDenominator() == 1 &&
    "Copy-Assignment-Operator not extendable!\n");
  assert(b.getNominator() == -1 && b.getDenominator() == 13 &&
    "Copy-Constructor not working!\n");
  assert(c.getNominator() == 0 && c.getDenominator() == 1 &&
    "Copy-Assignment-Operator not working!\n");
  assert(a.getNominator() == 0 && a.getDenominator() == 1 &&
    "Default Constructor not working!\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void outOperator()
{
#if OUT_OPERATOR == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(3, 4);
  Fraction b(-222, 17);
  Fraction c(-86, -56);

  std::stringstream ss;
  ss << a << b << c;

  std::string output = ss.str();
  std::cout << output;

  assert(output == "3 / 4\n-222 / 17\n43 / 28\n" &&
    "Output operator wrong!\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void plusOperators()
{
#if PLUS_OPERATORS == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(-99, 33); // -3
  Fraction b(-68, -23);// 68 / 23
  Fraction c(42, 19);  // 42 / 19
  Fraction d;
  Fraction e;
  Fraction f(1, 4);

  d = a + b;
  e = c += b;
  f += f;

  std::cout << a << b << c << d << e << f;

  assert(a.getNominator() == -3 && a.getDenominator() == 1 &&
    "Reducing fraction not correct!\n");
  assert(b.getNominator() == 68 && b.getDenominator() == 23 &&
    "Making denominator positive not working!\n");
  assert(c.getNominator() == 2258 && c.getDenominator() == 437 &&
    "+= Operator not working!\n");
  assert(d.getNominator() == -1 && d.getDenominator() == 23 &&
    "+ Operator not working!\n");
  assert(e.getNominator() == 2258 && e.getDenominator() == 437 &&
    "+= Operator not working!\n");
  assert(f.getNominator() == 1 && f.getDenominator() == 2 &&
    "+= Operator does no reduce fraction!\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void plusOperatorsWithInt()
{
#if PLUS_OPERATORS_WITH_INT == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(20, 30);
  Fraction b(-40, 50);

  a = a + 14;
  b = -5 + b;

  std::cout << a << b;

  assert(a.getNominator() == 44 && a.getDenominator() == 3 &&
    "+ Operator with leading fraction not working\n");
  assert(b.getNominator() == -29 && b.getDenominator() == 5 &&
    "+ Operator with leading int not working\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void incrementOperators()
{
#if INCREMENT_OPERATORS == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(-11, 66);

  Fraction b = ++a;
  Fraction c = a++;

  std::cout << a << b << c;

  assert(a.getNominator() == 11 && a.getDenominator() == 6 &&
    "Increment operator(s) not working!\n");
  assert(b.getNominator() == 5 && b.getDenominator() == 6 &&
    "Increment operator(s) not working!\n");
  assert(c.getNominator() == 5 && c.getDenominator() == 6 &&
    "Increment operator(s) not working!\n");

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void negationInversionDivision()
{
#if NEGATION_INVERSION_DIVISION == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(17, 19);
  Fraction b(18, 20);

  Fraction c = -a;
  Fraction d = ~b;
  Fraction e;

  std::cout << a << b << c << d;

  assert(a.getNominator() == 17 && a.getDenominator() == 19 &&
    "Reducing fraction not correct!\n");
  assert(b.getNominator() == 9 && b.getDenominator() == 10 &&
    "Reducing fraction not correct!\n");
  assert(c.getNominator() == -17 && c.getDenominator() == 19 &&
    "Reducing fraction not correct!\n");
  assert(d.getNominator() == 10 && d.getDenominator() == 9 &&
    "Reducing fraction not correct!\n");
  assert(e.getNominator() == 0 && e.getDenominator() == 1 &&
    "Reducing fraction not correct!\n");

  try
  {
    e = ~Fraction(0);
    assert(false && "No DivideByZeroException thrown!\n");
  }
  catch (DivideByZeroException& ex)
  {
    std::cout << "Error: " << ex.what();

    assert(std::string(ex.what()) == "0 in the denominator invalid!\n"
      && "DivideByZeroException not correct!\n");
  }

  try
  {
    b /= b; // Are we smarter than the compiler? What happens if you compile with g++ instead of clang++?
    std::cout << b;

    assert(b.getNominator() == 1 && b.getDenominator() == 1
      && "Division not delivering right result!\n");

    c = a /= e;
    assert(false && "No DivideByZeroException thrown!\n");
  }
  catch (DivideByZeroException& ex)
  {
    std::cout << "Error: " << ex.what();

    assert(std::string(ex.what()) == "Dividing by 0 not valid!\n"
      && "DivideByZeroException not correct!\n");
  }

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void boolOperators()
{
#if BOOL_OPERATOR == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a;
  Fraction b(2);

  std::cout << a << b;

  if (a)
  {
    assert(false && "Fraction with value 0 should not be true!\n");
  }
  if (!b)
  {
    assert(false && "!Fraction with value inequal to zero should be true!\n");
  }

  #if BOOL_OPERATOR_COMPILATION_FAILER == 1
  int c = a;
  #endif

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}

//------------------------------------------------------------------------------
void compareOperators()
{
#if COMPARE_OPERATORS == 1

  std::cout << "Testcase: " << __func__ << std::endl << std::endl;

  Fraction a(5769, 243);
  Fraction b(1283, 54); // b > a
  Fraction c(6410, 270); // a == c
  Fraction d(-641, 27);

  std::cout << a << b << c << d;

  if (a == b || a == d || b == a || b == c || b == d || c == b || c == d || 
      d == a || d == b || d == c)
    assert(false && "Inequival fractions are assumed as equal in ==!\n");
  if (!(a == a && a == c && b == b && c == a && c == c && d == d))
    assert(false && "Equal fractions are assumed as inequival in ==!\n");

  if (!(a != b && a != d && b != a && b != c && b != d && c != b && c != d &&
      d != a && d != b && d != c))
    assert(false && "Inequival fractions are assumed as equal in !=!\n");
  if (a != a || a != c || b != b || c != a || c != c || d != d)
    assert(false && "Equal fractions are assumed as inequival in !=!\n");

  if (!(a < b && c < b && d < a && d < b && d < c))
    assert(false && "<-operator not working correctly!\n");
  if (a < a || a < c || a < d || b < a || b < b || b < c || b < d || c < a || 
      c < c || c < d || d < d)
    assert(false && "<-operator not working correctly!\n");

  if (!(a <= a && a <= b && a <= c && b <= b && c <= a && c <= b && c <= c && d <= a && 
      d <= b && d <= c && d <= d))
    assert(false && "<=-operator not working correctly!\n");
  if (a <= d || b <= a || b <= c || b <= d || c <= d)
    assert(false && "<=-operator not working correctly!\n"); 

  std::cout << "\nTestcase passed!\n\n";
  std::cout << "-----------------------------------------------\n" << std::endl;

#endif
}
