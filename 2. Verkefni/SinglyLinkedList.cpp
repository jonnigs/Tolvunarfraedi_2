#include <iostream>
#include <stdexcept>

using namespace std;

class SinglyLinkedList {
   private:
    class Node {
       public:
        Node* next;
        char data;

        Node(char data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };

    Node* head;
    int length;

   public:
    SinglyLinkedList() {
        this->head = nullptr;
        this->length = 0;
    }

    ~SinglyLinkedList() {
        cout << "Kallad hefur verid a eydinn fyrir listann" << endl;

        Node* head2 = this->head;   // Byrja med hausinn og naesta thar
        Node* n = this->head->next; // a eftir og lykkja svo i gegnum listann
        while(n != 0){
          delete head2;
          Node* head2 = n;
          n = n->next;
        }
        delete head2;               // Enda a ad henda ollu sem er eftir
        delete n;
    }

    int size() { return this->length; }

    void display() {
        for (Node* node = this->head; node != nullptr; node = node->next) {
            cout << node->data << " -> ";
        }
        cout << "--FIN--" << endl;
    }

    void prepend(char c) {
        Node* n = new Node(c, this->head);
        this->head = n;
        this->length++;
    }

    char operator[](int n) {   // Grip strax villu ef ad bedid er um
        if (n > this->length){ // stak utan listans
            throw out_of_range("Index out of range");
        }

        Node* hnutur = this->head;    // Ytra i gegnum listan ad
        for (int i = 0; i < n; i++){  // umbednu staki
            hnutur = hnutur->next;
        }
        if (hnutur->data){     // Tekka hvort ad listinn se tomur
            return hnutur->data;
        } else{
            throw out_of_range("Index out of range");
        }
    }
};

int main() {
    // Skilgreining lista sem inniheldur takn
    SinglyLinkedList list;
    list.prepend('G');
    list.prepend('3');
    list.prepend('0');
    list.prepend('2');
    list.prepend('L');
    list.prepend('O');
    list.prepend('T');

    list.display();

    cout << "Stak 0 i listanum er " << list[0] << endl;
    cout << "Stak 3 i listanum er " << list[3] << endl;

    return 0;
}
