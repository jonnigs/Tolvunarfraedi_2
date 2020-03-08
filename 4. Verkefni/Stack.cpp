#include <iostream>

using namespace std;

class Stack {
    /*
    Táknar LIFO hlaða af ótiltekinni stærð, útfærður með eintengdum hnútum.
    Allar aðgerðir taka fastan tíma.
    */
  private:
    class Node {
    public:
      Node* next;
      int data;

      Node(int data, Node* next) {
        this->data = data;
        this->next = next;
      }

      ~Node() {
        if (this->next != nullptr) {
          delete this->next;
        }
      }
    };

    Node* first;
    int lengd;

  public:
    Stack() {
        /*
        Smiður, upphafsstillir tóman hlaða.
        */
        this->first = nullptr;
        this->lengd = 0;
    }

    ~Stack() { delete this->first; }

    void push(int n) {
        /*
        Bætir heiltölunni n efst á hlaðann.
        */
        this->lengd = this->lengd++; // lengjum listann um 1
        this->first = new Node(n, this->first); // Buum til nyjan hnut sem bendir a
                                            // hausinn og setjum hann sem haus a sama tima
    }

    int pop() {
        /*
        Fjarlægir þá tölu sem styst hefur verið á hlaðanum og skilar henni
        */
        if (this->first == nullptr) {
            throw underflow_error("Reynt var að fjarlægja efsta stak af tómum hlaða");
        }
        int i = this->first->data;
        this->first = this->first->next;
        return i;
    }

    int peek() {
        /*
        Skilar gildi þeirrar tölu sem styst hefur verið á hlaðanum en skilur við hlaðann í sama ástandi
        */
        if (this->first == nullptr) {
            throw underflow_error("Reynt var að kíkja á efsta stak tóms hlaða");
        }
        return this->first->data;
    }

    bool isEmpty() {
        /*
        Skilar sönnu innihaldi hlaðinn engar tölur
        */
        return (first == nullptr);
    }
};

int main() {
    Stack s;
    cout << "Setjum tolurnar 1, 2 og 4 a hladann s." << endl;
    s.push(1);
    s.push(2);
    s.push(4);
    cout << "Stelum efsta stakinu, " << s.pop() << ", af s." << endl;
    cout << "Setjum tolurnar 8, 16 og 32 a s." << endl;
    s.push(8);
    s.push(16);
    s.push(32);

    cout << "Kikjum a efsta stak s, thad er " << s.peek() << "." << endl;

    cout << "Fjarlaegjum nu tolurnar af s: " << endl;
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    try {
        s.peek();
    } catch (underflow_error e) {
        cout << "Ekki tokst ad kikja a s, enda tomur" << endl;
    }

    try {
        s.pop();
    } catch (underflow_error e) {
        cout << "Ekki tokst ad fjarlaegja stak af s, enda tomur" << endl;
    }

    return 0;
}
