
#include <iostream>
#include <stdexcept>

#include "../utilities/utilities.hpp"
#include "rational.hpp"

using namespace std;

Rat::Rat(int nom, int denom) {
  this->set_number(nom, denom);
}

Rat::Rat(int num) {
  this->set_number(num, 1);
}

void Rat::set_number(int nom, int denom) {
  if (denom == 0) {
    throw invalid_argument("The denominator can't be 0");
  }
  int _pgcd = pgcd(nom, denom);
  if(nom == denom){ //if nom and denom are equals this number is 1
    _pgcd = nom;
  }

  if(nom == 0){ //if nom is 0 then denom has to be equal to 1
    _pgcd = denom;
  }


  this->nom = nom / _pgcd;
  this->denom = denom / _pgcd;

  if (this->nom < 0 && this->denom < 0) {
    this->nom = -this->nom;
    this->denom = -this->denom;
  }
  if (this->nom >= 0 && this->denom < 0) {
    this->nom = -this->nom;
    this->denom = -this->denom;
  }
}

// operator overloadings:

bool operator==(Rat rat1, Rat rat2) {
  return (rat1.get_nom() == rat2.get_nom() &&
          rat1.get_denom() == rat2.get_denom());
}

bool operator!=(Rat rat1, Rat rat2) { return !(rat1 == rat2); }

bool operator==(Rat rat, int num) {
  if (rat.get_denom() == 1)
    return rat.get_nom() == num;
  return false;
}

bool operator==(Rat rat, double num) {
  return (double)(rat.get_nom() / rat.get_denom()) == num;
}

bool operator==(int num, Rat rat) { return rat == num; }
bool operator==(double num, Rat rat) { return rat == num; }

bool operator!=(Rat rat, int num) { return !(rat == num); }
bool operator!=(int num, Rat rat) { return !(num == rat); }
bool operator!=(double num, Rat rat) { return !(num == rat); }
bool operator!=(Rat rat, double num) { return !(rat == num); }

bool operator>(Rat n1, Rat n2) {
  int nom1 = n1.get_nom() * n2.get_denom();
  int nom2 = n2.get_nom() * n1.get_denom();
  return nom1 > nom2;
}

bool operator>(Rat n1, double num) { return n1 > Rat(num); }

bool operator>(double num, Rat n1) { return Rat(num) > n1; }

bool operator>=(Rat n1, Rat n2) { return n1 > n2 || n1 == n2; }
bool operator>=(Rat n1, double num) { return n1 >= Rat(num); }
bool operator>=(double num, Rat n1) { return Rat(num) >= n1; }

bool operator<(Rat n1, Rat n2) { return !(n1 >= n2); }
bool operator<(Rat n1, double num) { return n1 < Rat(num); }
bool operator<(double num, Rat n1) { return Rat(num) < n1; }

bool operator<=(Rat n1, Rat n2) { return n1 < n2 || n1 == n2; }
bool operator<=(Rat n1, double num) { return n1 <= Rat(num); }
bool operator<=(double num, Rat n1) { return Rat(num) <= n1; }

Rat operator*(Rat n1, Rat n2) {
  int nom = n1.get_nom() * n2.get_nom();
  int denom = n1.get_denom() * n2.get_denom();
  Rat r_new = Rat(nom, denom);
  return r_new;
}

Rat operator*(Rat n1, int num) {
  Rat n2 = Rat(num);
  return n1 * n2;
}

Rat operator*(int num, Rat n1) {
  Rat n2 = Rat(num);
  return n1 * n2;
}

Rat operator/(int num, Rat n1) {
  Rat n2 = Rat(num);
  return n2 / n1;
}
Rat operator/(Rat n1, int num) {
  Rat n2 = Rat(num);
  return n1 / n2;
}

Rat operator/(Rat n1, Rat n2) {
  Rat rev_2 = Rat(n2.get_denom(), n2.get_nom());
  return n1 * rev_2;
}

Rat operator+(Rat n1, Rat n2) {
  int nom1 = n1.get_nom() * n2.get_denom();
  int nom2 = n2.get_nom() * n1.get_denom();
  return Rat(nom1 + nom2, n1.get_denom() * n2.get_denom());
}
Rat operator+(Rat n1, int num) {
  Rat n2 = Rat(num);
  return n1 + n2;
}
Rat operator+(int num, Rat n1) {
  Rat n2 = Rat(num);
  return n1 + n2;
}

Rat operator-(Rat n1) { return Rat(-n1.get_nom(), n1.get_denom()); }

Rat operator-(Rat n1, Rat n2) {
  Rat new_r = -n2;
  return n1 + new_r;
}

Rat operator-(Rat n1, int num) { return n1 + (-num); }

Rat operator-(int num, Rat n1) { return num + (-n1); }

ostream &operator<<(ostream &out, const Rat &rat) {
  if (rat.get_denom() == 1) {
    out << rat.get_nom();
    return out;
  }
  out << rat.get_nom() << "/" << rat.get_denom();
  return out;
}
