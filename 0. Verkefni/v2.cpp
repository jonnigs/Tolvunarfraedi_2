#include<iostream>
#include <vector>

using namespace std;

int main (){

  vector<int> v;
  int input;

  while(cin >> input){  // Thar sem ad input er skilgreint sem int, tha keyrir
    v.push_back(input); // lykkjan thar til að eitthvad annad en int er slegid
  }                     // inn i comand line

  int sum = 0;
  int lengd = v.size();

  while (!v.empty()){   // Lykkja sem leggur saman ur vigrinum
    sum += v.back();
    v.pop_back();
  }
  // Sma float vesen i utskrifun a medaltali
  cout << "Summa talnanna er " << sum << endl;
  cout << "Medaltal talnanna er " << ((float)sum)/((float)lengd) << endl;
  return 0;
}
