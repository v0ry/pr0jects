#include <stdio.h>

typedef struct
{
  double real_;
  double imag_;
} Complex;

void printComplex(Complex a)
{
  if (a.imag_ >= 0)
    printf("%.2lf + %.2lfi", a.real_, a.imag_);
  else
    printf("%.2lf - %.2lfi", a.real_, -a.imag_);
}

Complex add(Complex a, Complex b)
{
  Complex result = {a.real_ + b.real_, a.imag_ + b.imag_};
  return result;
}

void addTo(Complex* a, Complex b)
{
  a->real_ += b.real_;
  a->imag_ += b.imag_;
}

Complex multiply(Complex a, Complex b)
{
  Complex result = {a.real_ * b.real_ - a.imag_ * b.imag_, a.real_ * b.imag_ +  a.imag_ * b.real_};
  return result;
}

void conjugateComplex(Complex* a)
{
  a->imag_ = -a->imag_;
}

int main(void)
{
  double a_real, a_imag, b_real, b_imag;

  printf("Real of a: ");
  scanf("%lf", &a_real);
  printf("Imag of a: ");
  scanf("%lf", &a_imag);

  printf("Real of b: ");
  scanf("%lf", &b_real);
  printf("Imag of b: ");
  scanf("%lf", &b_imag);

  // TODO ...

  Complex a = {a_real, a_imag};
  Complex b = {b_real, b_imag};

  Complex c = add(a, b);
  printf("c = a + b = ");
  printComplex(c);
  printf("\n");

  addTo(&c, a);
  printf("c += a = ");
  printComplex(c);
  printf("\n");

  conjugateComplex(&b);
  addTo(&c, b);
  printf("c += ~b = ");
  printComplex(c);
  printf("\n");

  Complex c_safe = c;
  conjugateComplex(&c);
  c = multiply(c_safe, c);
  printf("c = c * ~c = ");
  printComplex(c);
  printf("\n");

  return 0;
}
