// Urheber: Stefan Etzelstorfer (Original-Abgabe von der Prüfung)
// Der übernommene Code befindet sich zwischen dem begin- und end-Kommentar. In diesem Fall wurde sogar die vom Studierenden geschriebene main-Funktion übernommen, mit welcher er seinen Code getestet hat.

//begin
class Shape
{
  private:
    static int id_counter;
    size_t id_;
  public:
    Shape()
    {
      id_ = id_counter;
      id_counter++;
    }

    Shape(const Shape& shape)
    {
      this->id_ = id_counter;
    }
    virtual ~Shape() = default;
    Shape& operator =(const Shape& shape) = delete;
    
    virtual double area() const = 0;
    virtual void print() const
    {
      std::cout << "Shape with ID << " << id_ << "is " << area() <<"units large.\n";
    }
    
    size_t getID() const
    {
      return id_;
    }
    
    friend double operator+(const Shape& shape1, const Shape& shape2);
  
};


double operator+(const Shape& shape1, const Shape& shape2)
{
  return shape1.area() + shape2.area();
}


class Rectangle: public Shape
{
  private:
    double width_;
    double length_;
  public:
    Rectangle(double width, double length): Shape(), width_(width), length_(length)
    {}
    
    Rectangle(const Rectangle& rectangle): Shape(rectangle), width_(rectangle.width_), length_(rectangle.length_)
    {}
    
    Rectangle() = default;
    
    ~Rectangle() = default;
    
    Rectangle& operator = (const Rectangle& rectangle) = delete;
    
    virtual double area() const override
    {
      return (width_ * length_);
    }
    
    void print() const
    {
      std::cout << "Rectangle with ID " << getID() << " is " << area() <<" units large.\n";
    }

};

int Shape::id_counter = 1;

int main()
{
  Rectangle rec1(2.0,2.0);
  rec1.print();  

  Rectangle rec2(3.0,2.0);
  rec2.print();
  
  Rectangle rec3(2.0,3.0);
  rec3.print();
  
  // Summe zweier Rechtecke
  std::cout << "Summe von rec1 und rec2: "<< rec1 + rec2 << std::endl;
  
  // Test Polymorphie
  Shape* rec4 = new Rectangle(2.0, 4.0);
  rec4->print();
  
  // Test CopyConstructor
  Rectangle rec5(rec1);
  rec5.print();

  
  
  delete rec4;
  return 0;
}
//end
