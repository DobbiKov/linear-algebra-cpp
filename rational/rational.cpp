
#include <iostream>
#include <stdexcept>

#include "rational.hpp"
#include "../utilities/utilities.hpp"

using namespace std;

Rat::Rat(int nom, int denom) {
    if (denom == 0) {
      throw invalid_argument("The denominator can't be 0");
    }
    int _pgcd = pgcd(nom, denom);
    this->nom = nom / _pgcd;
    this->denom = denom / _pgcd;
}

Rat::Rat(int num) {
    this->nom = num;
    this->denom = 1;
}

void Rat::set_number(int nom, int denom){
    if (denom == 0) {
      throw invalid_argument("The denominator can't be 0");
    }

    int _pgcd = pgcd(nom, denom);
    this->nom = nom / _pgcd;
    this->denom = denom / _pgcd;
}

// operator overloadings: 

bool operator==(Rat rat, int num){
    if(rat.get_denom() == 1)
        return rat.get_nom() == num;
    return false;
    
}

bool operator==(Rat rat, double num){
    return (rat.get_nom() / rat.get_denom()) == num;
}

Rat operator*(Rat n1, Rat n2){
    int nom = n1.get_nom() * n2.get_nom();
    int denom = n1.get_denom() * n2.get_denom();
    Rat r_new = Rat(nom, denom);
    return r_new;
}

Rat operator*(Rat n1, int num){
    Rat n2 = Rat(num);
    return n1 * n2;
}

Rat operator*(int num, Rat n1){
    Rat n2 = Rat(num);
    return n1 * n2;
}

Rat operator/(int num, Rat n1){
    Rat n2 = Rat(num);
    return n2 / n1;
}
Rat operator/(Rat n1, int num){
    Rat n2 = Rat(num);
    return n1 / n2;
}

Rat operator/(Rat n1, Rat n2){
    Rat rev_2 = Rat(n2.get_denom(), n2.get_nom());
    return n1 * rev_2;
}

Rat operator+(Rat n1, Rat n2){
    
}
// Rat operator-(Rat n1, Rat n2);

ostream& operator<<(ostream& out, const Rat& rat){
    if(rat.get_denom() == 1){
        out << rat.get_nom();
        return out;
    }
    out << rat.get_nom() << "/" << rat.get_denom();
    return out;
}