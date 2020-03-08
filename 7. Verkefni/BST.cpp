#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
  /*
  Táknar hnút í tvíleitartré sem inniheldur strengi
  */
public:
  string data;
  Node* left;
  Node* right;

  Node(string data) {
    /*
    Býr til nýjan barnlausan hnút sem inniheldur strenginn <data>
    */
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }

  ~Node() {
    /*
    Passar endurkvæmt upp á að engin börn séu skilin eftir í reiðileysi
    */
    delete this->left;
    delete this->right;
  }

  /*void print(Node k) {
    if (k->left == nullptr) {
      cout << k->data << endl;
    }
  }*/
};

class StringSearchTree {
  /*
  Táknar tvíleitartré sem inniheldur strengi.
  Samanburðir fara fram á strengjunum sjálfum.
  Einu aðgerðirnar sem eru studdar eru innsetning (put) og uppfletting (contains)
  */
public:
  StringSearchTree() {
    /*
    Upphafsstillir tómt (hnútalaust) tvíleitartré.
    */
    this->root = nullptr;
  };

  ~StringSearchTree() {
    /*
    Eyðingu úthlutað til klasans Node.
    */
    delete this->root;
  }

  void put(string data) {
    /*
    Býr til hnút utan um strenginn <data> og setur hann á réttan stað í tvíleitartréð.
    Sé hnútur með sömu gögn þegar í trénu er þeim ekki bætt við aftur.
    Strengurinn <data> þarf að vera skilgreindur, ekki þarf að meðhöndla nullptr.
    */

    Node* nyr = new Node(data);
    Node* leit = this->root;
    bool s = true;

    if (this->root == nullptr) { // Ef rotin er tom verdur nyr ad rotinni
      this->root = nyr;
    } else { // Annars finnum vid hvar thad a ad vera
      while (s == true) {
        if (nyr->data < leit->data == 1) {  // Nytt stak minna?
          if (leit->left == nullptr) { // Vinstri grein i tre tom?
            leit->left = nyr;
            s = false; // Stoppum lykkju
          } else {
            leit = leit->left; // Annars faera nedar i tre
          }
        }
        if (nyr->data > leit->data == 1) { // Nytt stak staerra?
          if (leit->right == nullptr) { // Haegri grein i tre tom?
            leit->right = nyr;
            s = false; // Stoppum lykkju
          } else {
            leit = leit->right; // Annars faera nedar i tre
          }
        }
      }
    }
  }

  bool contains(string data) {
    /*
    Skilar sönnu sé <data> í trénu, annars ósönnu.
    */
    Node* leit = this->root;
    bool s = true;
    while (s == true) {
      if (data == leit->data) {
        return s;
      } else if (data < leit->data == 1) {
        if (leit->left == nullptr) {
          return false;
        }
        leit = leit->left;
      } else if (data > leit->data == 1) {
        if (leit->right == nullptr) {
          return false;
        }
        leit = leit->right;
      }
    }
  }

private:
  Node* root;

  friend ostream& operator<<(std::ostream& os, StringSearchTree& tree);
};

ostream& operator<<(ostream& os, StringSearchTree& tree) {
  os << "Her!";
  return os;
};

int main() {
  /*
  Tvíleitartréð prófað með því að setja í það ávexti.
  */

  StringSearchTree tree;

  // Skilgreinum ávextina okkar
  vector<string> fruits = {"Ananas", "Banani", "Epli",    "Greip",          "Mandarina",
  "Mango",  "Melona", "Sitrona", "Stjornuavoxtur", "Suraldin"};
  // Innsetningin á að virka óháð innsetningarröð
  random_shuffle(fruits.begin(), fruits.end());
  cout << "Setjum avexti i tred i eftirfarandi rod:" << endl;
  for (string fruit : fruits) {
    cout << fruit << " ";
    tree.put(fruit);
  }
  cout << endl << endl;

  // Athugum hvort tréð innihaldi ávextina
  int missing = 0;
  for (string fruit : fruits) {
    if (!tree.contains(fruit)) {
      missing++;
    }
  }
  if (0 < missing) {
    cout << missing << " Avextir skiludu ser ekki i tred.";
  } else {
    cout << "Allir avextirnir lentu i trenu." << endl;
  }
  if (tree.contains("Ferskja")) {
    cout << "Ferskja fannst i trenu sem ekki var sett thangad. Thetta er villa." << endl << endl;
  } else {
    cout << "Engin ferskja er i trenu, sem er edlilegt." << endl << endl;
  }

  cout << "Skrifum ut avextina i trenu i rettri rod:" << endl;
  cout << tree << endl;
}
