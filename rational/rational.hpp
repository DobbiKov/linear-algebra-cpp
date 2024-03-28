#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <stdexcept>

using namespace std;

class Rat {
public:
    Rat(int nom, int denom);
    Rat(int num);

    int get_nom() const { return this->nom; }

    int get_denom() const { return this->denom; }
    void set_number(int nom, int denom);
    friend bool operator==(Rat rat, int num);
    friend bool operator==(Rat rat, double num);
    friend ostream& operator<<(ostream& out, const Rat& rat);
private: 
    int nom;
    int denom;
};

Rat operator*(Rat n1, Rat n2);
Rat operator*(int num, Rat n1);
Rat operator*(Rat n1, int num);

Rat operator/(Rat n1, Rat n2);
Rat operator/(Rat n1, int num);
Rat operator/(int num, Rat n1);

Rat operator+(Rat n1, Rat n2);
Rat operator-(Rat n1, Rat n2);

#endif