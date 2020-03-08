#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void exch(vector<int>& pq, int i, int j) {
  int swap = pq[i-1];
  pq[i-1] = pq[j-1];
  pq[j-1] = swap;
}

bool lesss(vector<int>& pq, int i, int j) {
  if (pq[i-1] <= pq[j-1]) {
    return false;
  } else {
    return true;
  }
  //return pq[i-1].compareTo(pq[j-1]) < 0;
}

void sink(vector<int>& pq, int k, int n) {
  while (2*k <= n) {
    int j = 2*k;
    if (j < n && lesss(pq, j, j+1)) {
      j++;
    }
    if (!lesss(pq, k, j)){
      break;
    }
    exch(pq, k, j);
    k = j;
  }
}

void heapsort(vector<int>& pq) {
  int n = pq.size();
  for (int k = n/2; k >= 1; k--)
  sink(pq, k, n);
  while (n > 1) {
    exch(pq, 1, n--);
    sink(pq, 1, n);
  }
  reverse(pq.begin(), pq.end());
}

bool issorted(vector<int>& v) {
  /*
  * Athugar hvort vigurinn v sé í stígandi röð
  */
  cout << endl;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] < v[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  // Prófum sort á vigrum af lengdunum 0, 101, og 1000:
  vector<int> sizes = {0, 101, 1000};
  for (int n : sizes) {
    // Upphafstillum v með tölunum 0 upp í n-1 í slembinni röð
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = i;
    }
    random_shuffle(v.begin(), v.end());

    // Röðum v aftur
    heapsort(v);
    
    // Athugum hvort röðunin tókst
    if (issorted(v)) {
      cout << "Rodun a " << v.size() << " staka vigri tokst" << endl;
    } else {
      cout << "Rodun a " << v.size() << " staka vigri mistokst" << endl;
    }
  }
}
