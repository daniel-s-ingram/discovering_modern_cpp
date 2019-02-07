#include <iostream>

class complex
{
    friend const double& real(const complex& c);
    friend const double& imag(const complex& c);
    
    public:
        complex(double r=0, double i=0) : r(r), i(i) {}

    private:
        double r, i;
};

inline const double& real(const complex& c) {return c.r;}
inline const double& imag(const complex& c) {return c.i;}

std::ostream& operator<<(std::ostream& os, complex& c)
{
    return os << real(c) << " + " << imag(c) << "i";
}

int main(int argc, char** argv)
{
    complex z(3.0, 2.0);
    std::cout << z << std::endl;
    return 0;
}