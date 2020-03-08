#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction {

protected:
  int num;
  int den;

  int gcd(int n1, int n2) {

    if (n2 == 0) {
      return n1;
    } else {
      return gcd(n2, n1 % n2);
    }
  }

  void reduce() {

    int n = this->num;
    int d = this->den;
    int divisor = this->gcd(n, d);
    this->num = n / divisor;
    this->den = d / divisor;
  }

public:
  Fraction(int n, int d) {
    this->num = n;
    this->den = d;
    if (d == 0) {
      throw logic_error("Error, zero denominator!");
    }
    this->reduce();
  }

  Fraction operator+(Fraction f) {
    int n = this->num * f.den + f.num * this->den;
    int d = this->den * f.den;
    return Fraction(n, d);
  }

  Fraction operator*(Fraction f) {
    int n = this->num * f.num;
    int d = this->den * f.den;
    return Fraction(n, d);
  }

  // ostream veittur aðgangur að protected eiginleikum klasans
  friend ostream& operator<<(std::ostream& os, Fraction f);
};

ostream& operator<<(ostream& os, Fraction f) {

  os << f.num << "/" << f.den;
  return os;
};

class MixedFraction : public Fraction {
protected:
  int heil; // Heiltoluhluti blendnu tolunar

  void brot2blend(){
    this->reduce();
    if (this->num > this->den) {
      int n = this->num;
      int d = this->den;
      int h = this->heil;
      this->num = n % d;
      this->heil = h + ((n-this->num)/d);
    }
  }

public:
  MixedFraction( int num, int den) : Fraction(num, den) {
    this->heil = 0;
    if (den == 0) {
      throw logic_error("Error, zero denominator!");
    }
    this->brot2blend();
  }

  // Hér þarf að bæta við öðrum smið
  MixedFraction(int heil, int num, int den) : Fraction(num, den) {
    this->heil = heil;
    this->brot2blend();
  }
  friend ostream& operator<<(std::ostream& os, MixedFraction f);
};

ostream& operator<<(ostream& os, MixedFraction f) {
  if (f.num == 0){
    os << f.heil;
  } else if (f.heil == 0 && f.num != 0){
    os << f.num << "/" << f.den;
  } else {
    os << f.heil << " " << f.num << "/" << f.den;
  }
  return os;
};

int main() {
  cout << "Buum til og birtum brotid 4/3 sem Fraction: ";
  cout << Fraction(4, 3) << endl;

  cout << "Margfoldum saman Fraction-in 1/2 og 2/3: ";
  cout << Fraction(1, 2) * Fraction(2, 3) << endl;

  cout << "Buum til og birtum brotid 1/4 sem MixedFraction: ";
  cout << MixedFraction(1, 4) << endl;

  cout << "Buum til og birtum brotid 4/1 sem MixedFraction: ";
  cout << MixedFraction(4, 1) << endl;

  cout << "Buum til og birtum brotid 0/2 sem MixedFraction: ";
  cout << MixedFraction(0, 2) << endl;

  cout << "Buum til og birtum brotid 7/6 sem MixedFraction: ";
  cout << MixedFraction(7, 6) << endl;

  cout << "Buum til og birtum brotid 1 1/3 sem MixedFraction: ";
  cout << MixedFraction(1, 1, 3) << endl;

  return 0;
}
