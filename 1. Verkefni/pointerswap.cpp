#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int temp ;
    temp = *a ; // Temp verður gildið sem a bendir á
   *a = *b ;    // Gildið sem a bendir á verður nú gildið sem b bendir á
   *b = temp ;  // Gildið sem b bendir á verður nú gildið sem a bendir á
    return;
}

int main() {
    int a = 2;
    int b = 3;
    int* pointsToA = &a;
    int* pointsToB = &b;
    cout << "*pointsToA = " << *pointsToA << endl;
    cout << "*pointsToB = " << *pointsToB << endl;
    cout << "Skiptum á gildum" << endl;
    swap(pointsToA, pointsToB);
    cout << "*pointsToA = " << *pointsToA << endl;
    cout << "*pointsToB = " << *pointsToB << endl;
    return 0;
}
