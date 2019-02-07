#include <iostream>

class complex
{
    friend const double& real(const complex& c);
    friend const double& imag(const complex& c);
    friend complex operator+(const complex& c1, const complex& c2);
    friend complex operator+(const complex& c, double d);
    friend complex operator*(const complex& c1, const complex& c2);
    friend complex operator*(const complex& c, double d);
    
    public:
        complex(double r=0, double i=0) : r(r), i(i) {}

    private:
        double r, i;
};

inline const double& real(const complex& c) {return c.r;}
inline const double& imag(const complex& c) {return c.i;}

inline complex operator+(const complex& c1, const complex& c2)
{
    return complex(c1.r + c2.r, c1.i + c2.i);
}

inline complex operator+(const complex& c, double d)
{
    return complex(c.r + d, c.i);
}

inline complex operator*(const complex& c1, const complex& c2)
{
    return complex(c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c1.i * c2.r);
}

inline complex operator*(const complex& c, double d)
{
    return complex(d * c.r, d * c.i);
}

std::ostream& operator<<(std::ostream& os, complex& c)
{
    return os << real(c) << " + " << imag(c) << "i";
}

int main(int argc, char** argv)
{
    complex z1(3.0, 2.0);
    complex z2(z1);
    complex z3 = z1 + z2;
    complex z4 = z1 + 6.0;
    complex z5 = 7.0 + z1;
    complex z6 = z1 * z2;
    complex z7 = 2 * z1;

    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "z3 = " << z3 << std::endl;
    std::cout << "z4 = " << z4 << std::endl;
    std::cout << "z5 = " << z5 << std::endl;
    std::cout << "z6 = " << z6 << std::endl;
    std::cout << "z7 = " << z7 << std::endl;
    return 0;
}