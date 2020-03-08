#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class SinglyLinkedList {
private:
  class Node {
  public:
    Node* next;
    T data;

    Node(T data, Node* next) {
      this->data = data;
      this->next = next;
    }

    ~Node() {
      if (this->next != nullptr) {
        delete this->next;
      }
    }
  };

  Node* head;
  int length;

public:
  SinglyLinkedList() {
    this->head = nullptr;
    this->length = 0;
  }

  ~SinglyLinkedList() { delete this->head; }

  int size() { return this->length; }

  void display() {
    for (Node* node = this->head; node != nullptr; node = node->next) {
      cout << node->data << " -> ";
    }
    cout << "--" << endl;
  }

  void prepend(T data) {
    this->head = new Node(data, this->head);
    this->length += 1;
  }

  void reverse() {
    if (this->size() == 0 || this->size() == 1){
      // Gera ekkert
    } else if (this->size() == 2) {
      Node* temp = this->head->next->next;
      this->head->next = nullptr;  // Hausinn bendir a null
      temp->next = this->head;     // Temp bendir a hausinn
      this->head = temp;           // Temp verdur hausinn
    } else {
      Node* x = this->head;
      Node* y = this->head->next;
      Node* z = this->head->next->next;
      this->head->next = nullptr;
      for (int i = 0; i < this->size()-2; i++) {
        y->next = x;
        x = y;
        y = z;
        z = z->next;
      }
      this->head = y;
      this->head->next = x;
    }
  }
};

int main() {
  // Skilgreining lista sem inniheldur tákn
  SinglyLinkedList<char> list;
  list.prepend('G');
  list.prepend('3');
  list.prepend('0');
  list.prepend('2');
  list.prepend('L');
  list.prepend('O');
  list.prepend('T');

  list.display();

  list.reverse();

  list.display();

  return 0;
}
