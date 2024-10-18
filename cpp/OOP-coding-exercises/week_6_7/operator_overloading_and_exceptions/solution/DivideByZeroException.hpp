#ifndef DIVIDE_BY_ZERO_EXCEPTION_HPP
#define DIVIDE_BY_ZERO_EXCEPTION_HPP

#include <stdexcept>

class DivideByZeroException : public std::exception
{
  private:
    const char* message_;

  public:
    DivideByZeroException(const char* message) : message_(message) {}
    DivideByZeroException(const DivideByZeroException&) = default;
    DivideByZeroException& operator=(const DivideByZeroException&) = delete;
    ~DivideByZeroException() = default;

    const char* what() const noexcept override { return message_; }
};

#endif // DIVIDE_BY_ZERO_EXCEPTION_HPP
