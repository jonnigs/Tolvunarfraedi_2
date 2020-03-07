#include<iostream>
#include<vector>

using namespace std;

void exch(vector<int> &v, int i, int j) {
int swap = v[i];
v[i] = v[j];
v[j] = swap;
}
void insertionSort(vector<int> &v) {
  for(int i=0; i < v.size()-1; i++) {
    int k = i;
    for(int j=i+1; j>0; j--) {
      if (v[k] > v[j]) {
        exch(v, k, j);
      } else {
        break;
      }
      k--;
    }
  }
}

void disp(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main () {
  vector<int> v;
  int input;

  while(cin >> input){
    v.push_back(input);
  }

  disp(v);
  insertionSort(v);
  disp(v);
  return 0;
}
