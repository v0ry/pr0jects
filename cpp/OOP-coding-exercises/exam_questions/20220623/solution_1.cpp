// Urheber: Jakob Freiberger (Original-Abgabe von der Prüfung)
// Der übernommene Code befindet sich zwischen dem begin- und end-Kommentar. In diesem Fall wurde sogar die vom Studierenden geschriebene main-Funktion übernommen, mit welcher er seinen Code getestet hat.

//begin
class Shape
{
public:
    // constructors
    Shape() : id_(++COUNT_) {}
    Shape(const Shape& other) : Shape() {}
    
    // operators
    Shape& operator=(const Shape& other) = delete;
    double operator+(const Shape& rhs)
    {
        return area() + rhs.area();
    }

    // public methods
    virtual double area() const = 0;
    virtual void print() const 
    {
        cout << "Shape with ID " << getID() << " is " << area() << " units large." << endl;
    }
    size_t getID() const { return id_; }
    

private:
    // private variables
    size_t id_;
    
    // static variables
    static size_t COUNT_;
};

// initialize static member variable
size_t Shape::COUNT_ = 0;


class Rectangle : public Shape
{
public:
    // constructors
    Rectangle(double width, double length) : Shape(), width_(width), length_(length) {}
    Rectangle(const Rectangle& other) : Rectangle(other.width_, other.length_) {}
    
    Rectangle& operator=(const Rectangle& other) = delete;
    
    // public methods
    double area() const override 
    {
        return width_ * length_;
    }
    void print() const override
    {
        cout << "Rectangle with ID " << getID() << " is " << area() << " units large." << endl;
    }
    
private:
    // private variables
    double width_;
    double length_;
};


int main()
{
  Rectangle r1(4, 6);
  Rectangle r2(3, 2);
  
  r1.print();
  r2.print();

  cout << r1 + r2 << endl;
    
  const Shape* s1 = new Rectangle(r1);
  s1->print();
  
  delete s1;
  
  // looks good :)
  
  return 0;
}
//end
