#include <iostream>
using std::cout;
using std::endl;

// Urheber: Dominik Milacher (Original-Abgabe von der Prüfung)
// Der übernommene Code befindet sich zwischen dem begin- und end-Kommentar.
// Die hier gezeigten Klassen nutzen einen std::vector, um die Zeichen des
// Strings zu speichern. Das ist auch die empfohlene Vorgangsweise, denn damit
// spart man sich im Vergleich zu char* einiges an Arbeit im Zusammenhang mit
// der Verwaltung des Speichers für die einzelnen Zeichen. (Noch einfacher wäre
// es mit std::string aber diese Klasse war laut Angabe in diesem Beispiel
// verboten.)

// begin
#include <vector>

class String {
protected:
    std::vector<char> string_;
    
public:
    String(char* string)
    {
        for (std::size_t index = 0; string[index]; ++index)
        {
            string_.push_back(string[index]);
        }
    }
    
    String(const String& other)
        : string_{other.string_}
    {
    }
    
    virtual ~String() = default;
    
    virtual void print() const
    {
        for (auto character : string_)
        {
            std::cout << character;
        }
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    for (auto character : string.string_)
    {
        stream << character;
    }
    
    return stream;
}

class SecretString: public String {
    char symbol_;
    
public:
    SecretString(char* string, char symbol)
        : String{string}, symbol_{symbol}
    {
    }
    
    SecretString(const SecretString& other)
        : String{other}, symbol_{other.symbol_}
    {
    }
    
    virtual void print() const override
    {
        for (auto character : string_)
        {
            std::cout << symbol_;
        }
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const SecretString& string);
};

std::ostream& operator<<(std::ostream& stream, const SecretString& string)
{
    for (auto character : string.string_)
    {
        stream << string.symbol_;
    }
    
    return stream;
}
//end

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
