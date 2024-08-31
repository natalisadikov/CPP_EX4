#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>

// this class represents a complex number
using namespace std;
class Complex
{
private:
    double real_;  // real part of the complex number
    double image_; // image part of the complex number

public:
    // constractor for complex number
    Complex(double real_ = 0.0, double image_ = 0.0) : real_(real_), image_(image_) {}

    // getter(return the real part )
    double get_real() const { return real_; }

    // getter(return the image part )
    double get_image() const { return image_; }

    // operator > for complex number
    bool operator>(const Complex &other) const
    {
        // check if > by comparaison the real part and the image part
        if (real_ > other.get_real() || (real_ == other.get_real() && image_ > other.get_image()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // operator == for complex number
    bool operator==(const Complex &other) const
    {
        // check if > by check if the real part and the image part are equals of the two complex number
        if (real_ == other.real_ && image_ == other.image_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // operator << for complex number
    friend ostream &operator<<(ostream &os, const Complex &complex)
    {
        os << complex.complex_to_string();
        return os;
    }

    // help function for convert a complex number to a string
    string complex_to_string() const
    {
        ostringstream os;
        os << std::fixed << std::setprecision(2);
        os << "(" << real_ << " + " << image_ << "i)";
        return os.str();
    }
};
#endif
