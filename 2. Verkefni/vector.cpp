#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void reikna(vector<double> v){
  int lengd = v.size();
  sort(v.begin(), v.end());

  // If seting fyrir miðgildid
  if (lengd % 2 == 0){
    double mid1 = v.at((lengd-2)/2); // Ef miðgildið er ekki í talnasafninu þá
    double mid2 = v.at(lengd/2);     // er meðaltal tekið af miðjutölunum tveim
    cout << "Midgildi talnana er " << (mid1 + mid2)/2 << endl;
  } else {
    cout << "Midgildi talnana er " << v.at((lengd - 1) / 2) << endl;
  }

  // For lykkja fyrir summu og medaltal
  double summa = 0;
  for(int i = 0; i<lengd; i++){
    summa += v.at(i);
  }
  double medaltal = summa/lengd;

  // For lykkja fyrir dreifni
  double dreifni = 0;
  for(int i = 0; i < lengd; i++){
    dreifni += ((v.at(i)-medaltal)*(v.at(i)-medaltal))/lengd;
  }
  cout << "Dreifni talnanna er " << dreifni << endl;
}

int main(){
  vector<double> v;
  double input;

  while(cin >> input){
    v.push_back(input);    // Tek tolurnar inn ur .txt skra. Nota cout
    cout << input << endl; // til að það sjaist i cmd hvad er sett inn
  }

  reikna(v);
  return 0;
}
