#include <iostream>
using std::cout;
using std::endl;


// class String:



// class SecretString:



int main()
{
  char text[30] = "OOP is awesome!";
  String str(text);
  SecretString secstr(text, '#');
  
  str.print();
  cout << " (print)" << endl;
  
  cout << str << endl;
  
  secstr.print();
  cout << " (print)" << endl;
  
  cout << secstr << endl << endl;
  
  
  cout << "--- Copies ---" << endl;
  String copy{str};
  cout << copy << " (<< copy)" << endl;
  copy.print();
  cout << " (print)" << endl;
  
  SecretString secret_copy{secstr};
  cout << secret_copy << " (<< secret_copy)" << endl;
  secret_copy.print();
  cout << " (print)" << endl << endl;
  
  cout << "--- Polymorphism ---" << endl;
  String &strref{secstr};
  strref.print();
  cout << endl;
  return 0;
}