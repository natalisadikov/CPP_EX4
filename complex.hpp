// 206396863
// natalisadikov2318@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>


using namespace std;
class Complex
{
private:
    double real_; 
    double image_; 

public:
   
    Complex(double real_ = 0.0, double image_ = 0.0) : real_(real_), image_(image_) {}

  
    double get_real() const { return real_; }

    double get_image() const { return image_; }

    bool operator>(const Complex &other) const
    {
        if (real_ > other.get_real() || (real_ == other.get_real() && image_ > other.get_image()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    bool operator==(const Complex &other) const
    {
    
        if (real_ == other.real_ && image_ == other.image_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

  
    friend ostream &operator<<(ostream &os, const Complex &complex)
    {
        os << complex.complex_to_string();
        return os;
    }

    string complex_to_string() const
    {
        ostringstream os;
        os << std::fixed << std::setprecision(2);
        os << "(" << real_ << " + " << image_ << "i)";
        return os.str();
    }
};
#endif
