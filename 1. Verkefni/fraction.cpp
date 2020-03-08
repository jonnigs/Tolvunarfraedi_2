#include <iostream>

using namespace std;

class Fraction {

   private:
    int num;
    int den;

   public:
    Fraction(int n, int d) {
        this->num = n;
        if (d==0) {
            cerr << "Villa, deilt med null";
        } else {
            this->den = d;
        }
    }

    void display() { cout << num << "/" << den << endl; }

    Fraction plus(Fraction f) {
        int numfinal = (num * f.den)+(f.num * den);
        int denfinal = den * f.den;
        return Fraction(numfinal, denfinal);
    }

    void reduce() {
        int a = num;
        int b = den;
        int leif = den % num;
        while (leif != 0){
          b = a;
          a = leif;
          leif = b % a;
        }
        num = num/a;
        den = den/a;
    }
};

int main() {
    cout << "Leggjum saman brotin 1/2 og 1/3 og birtum nidurstoduna:" << endl;
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a.plus(b);
    c.display();
    cout << endl;

    cout << "Buum til og birtum brotid 4/6:" << endl;
    Fraction d(4, 6);
    d.display();
    cout << "Styttum brotid 4/6 og birtum thad aftur:" << endl;
    d.reduce();
    d.display();
    cout << endl;

    cout << "Buum til brot med 0 i nefnara:" << endl;
    Fraction e(2, 0);
    return 0;
}
