#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction
{
  private:
    int nominator_;
    int denominator_;

    void reduceFraction();

  public:
    Fraction(int nominator = 0, int denominator = 1);
    Fraction(const Fraction& rhs);
    Fraction& operator=(const Fraction& rhs);
    ~Fraction() = default;

    int getNominator() const { return nominator_; }
    int getDenominator() const { return denominator_; }
    double value() const { return static_cast<double>(nominator_) / 
                            static_cast<double>(denominator_); }

    Fraction operator+(const Fraction& rhs) const;
    Fraction& operator+=(const Fraction& rhs);

    Fraction operator+(const int rhs) const;

    Fraction& operator++();
    Fraction operator++(int);

    Fraction operator-() const;
    Fraction operator~() const;

    Fraction& operator/=(const Fraction& rhs);

    explicit operator bool() const;
    bool operator!() const;

    bool operator==(const Fraction& rhs) const;
    bool operator!=(const Fraction& rhs) const;
    bool operator<(const Fraction& rhs) const;
    bool operator<=(const Fraction& rhs) const;
};

std::ostream& operator<<(std::ostream& out, const Fraction& rhs);

Fraction operator+(const int lhs, const Fraction& rhs);

#endif // FRACTION_HPP
