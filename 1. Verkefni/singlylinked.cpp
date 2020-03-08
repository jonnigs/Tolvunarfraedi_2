#include <iostream>

using namespace std;

class Node {
   public:
    Node* next;
    int data;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

int length(Node* head) {
    int counter = 1;
    Node* next = head;

    if (head == nullptr){    // Tekkar fyrst hvort að head se tomi listinn
      return 0;
    }

    while (next->next != 0){ // Itrar svo i gegnum listann og telur fra 1
      next = next->next;
      counter++;
    }
    return counter;
}

Node* search(Node* head, int n) {
    int check = 0;
    Node* next = head;

    while(check == 0){
      if (next->data == n){ // Ber saman gildid i hnutnum og gefna gildid
        return next;
      } else {
        next = next->next;  // Fer annars i naesta hnut
        if (next == 0){     // Ekki elegant lausn en thad sem eg gerdi fyrst
          check = 1;        // skodadi ekki sidasta hnutinn
        }
      }
    }
    return nullptr;
}

int main() {
    // Skilgreining lista sem inniheldur heiltölur
    Node* n5 = new Node(3, nullptr);
    Node* n4 = new Node(1, n5);
    Node* n3 = new Node(4, n4);
    Node* n2 = new Node(1, n3);
    Node* n1 = new Node(5, n2);
    Node *head = new Node(9, n1);

    cout << "Lengd listans er:                    6" << endl;
    cout << "Lengdin sem lengdarfallið skilar er: " << length(head) << endl;
    cout << endl;

    cout << "Lengd toma listans er:               0" << endl;
    cout << "Lengdin sem lengdarfallid skilar er: " << length(nullptr) << endl;
    cout << endl;

    cout << "Minnissvaedid sem inniheldur hnut med gognin \"3\" er:        " << n5 << endl;
    cout << "Minnissvaedid sem leitaradferdin finnur med leit ad \"3\" er: " << search(head, 3) << endl;
    cout << endl;

    cout << "Ekkert minnissvaedi inniheldur hnut med gognin \"6\"." << endl;
    cout << "Minnissvaedid sem leitaradferdin finnur med leit ad \"6\" er: " << search(head, 6) << endl;

    delete head;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}
