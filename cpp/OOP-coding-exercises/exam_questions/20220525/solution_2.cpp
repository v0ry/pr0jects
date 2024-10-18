#include <iostream>
using std::cout;
using std::endl;

// Urheber: Tobias Teichmann (Original-Abgabe von der Prüfung)
// Der übernommene Code befindet sich zwischen dem begin- und end-Kommentar.
// Die hier gezeigten Klassen nutzen einen char*, um auf den String zuzugreifen.
// Man beachte, dass sich die Klassen dabei um die Verwaltung des Speichers
// kümmern müssen (siehe Konstruktoren und Destruktor der Basisklasse).
// Der Urheber dieser Abgabe fühlt sich offensichtlich sicher im Umgang mit
// Pointern und dynamischer Speicherverwaltung. Für alle, die sich nicht selbst
// um den Speicher am Heap kümmern möchten, sei die Nutzung von STL-Containern,
// wie etwa std::vector, empfohlen :)
// Anzumerken ist auch, dass diese Abgabe eine für die Korrigierer unerwartete
// Lösung für das Polymorphie-Requirement enthielt. Wir empfehlen allen, dafür
// das Schlüsselwort virtual zu verwenden. Diese Lösung zeigt aber schön, dass
// man auch auf andere Weise dafür sorgen kann, dass sich eine Basisklassen-
// referenz so wie die (richtige) Subklasse verhält.

// begin
class String {
    public:
        String(const char* str) {
            char chr;
            size_t len = 0;
            do {
                chr = str[len++];
                if (len >= length_) {
                    length_ += 16;
                    char* temp = (char*)realloc(string_, length_);
                    if (temp == nullptr) {
                        free(string_);
                        exit(1);
                    }
                    string_ = temp;
                }
                string_[len-1] = chr;
            } while(chr != '\0');
            length_ = len;
            char* temp = (char*)realloc(string_, length_);
            if (temp == nullptr) {
                free(string_);
                exit(1);
            }
            string_ = temp;
        }
        String(String& str) {
            length_ = str.getLength();
            string_ = (char*)realloc(nullptr, length_);
            for (size_t i = 0; i < length_; i++) {
                string_[i] = str.getString()[i];
            }
        }
        ~String(){
            free(string_);
        }
        void print() {
            for (size_t i = 0; i < length_; i++) {
                if (is_secret_) {
                    std::cout << symbol_;
                } else {
                    std::cout << string_[i];
                }
            }
        }
        char* getString(){
            return string_;
        }
        size_t getLength() {
            return length_;
        }
    protected:
        char* string_ = nullptr;
        size_t length_ = 0;
        char symbol_ = '\0';
        bool is_secret_ = false;
};

class SecretString: public String {
    public:
        SecretString(const char* str, char symbol) : String(str) {
            symbol_ = symbol;
            is_secret_ = true;
        };
        SecretString(SecretString& str) : String(str) {
            symbol_ = str.getSymbol();
            is_secret_ = true;
        }
        char getSymbol() {
            return symbol_;
        }
};

std::ostream& operator<<(std::ostream& os, String& str) {
    for (size_t i = 0; i < str.getLength(); i++) {
        os << str.getString()[i];
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, SecretString& str) {
    for (size_t i = 0; i < str.getLength(); i++) {
        os << str.getSymbol();
    }
    return os;
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
