public class SinglyLinkedList<T> {

  private class Node {

    Node next;
    T data;

    Node(T data, Node next) {
      this.data = data;
      this.next = next;
    }
  }

  private Node head;
  private int length;

  SinglyLinkedList() {
    /*
    Smidur sem upphafsstillir toman lista.
    */
    this.head = null;
    this.length = 0;
  }

  public int size() {
    /*
    Skilar fjolda staka i listanum.
    */
    return this.length;
  }

  public boolean isEmpty() {
    /*
    Skilar sonnu innihaldi listinn engin stok, annars osonnu
    */
    return this.head == null;
  }

  @Override
  public String toString() {
    /*
    Adferd sem synir fallega strengjaframsetningu a listanum.
    */
    String c = "";
    Node curr = this.head;
    for (int i = 0; i < this.size(); i++) {
      c = c + " " + this.get(i);
      curr = curr.next;
    }
    return "[" + c + " ]";
  }

  public T get(int index) {
    /*
    Skilar staki numer index i listanum an thess ad breyta honum.
    */
    if (index < 0 || this.size() <= index) {
      throw new ArrayIndexOutOfBoundsException("Vísað út fyrir lista");
    }
    Node curr = this.head;
    for (int i = 0; i < index; i++) {
      curr = curr.next;
    }
    return curr.data;
  }

  public void insert(int index, T data) {
    /*
    Baetir staki vid listann i saeti numer index, an thess ad yfirskrifa stak.
    Ollum stokum sem koma a eftir nyja stakinu er hlidrad i att ad enda listans.
    */
    if (index < 0 || this.size() < index) {
      throw new ArrayIndexOutOfBoundsException("Visað ut fyrir lista");
    }
    if (index == 0) {
      Node newHead = new Node(data, this.head); // By til nyjan hnut
      this.head = newHead;                      // Geri thennan hnut ad nyja hausnum
      this.length = this.size() + 1;            // Lengi listann um einn
    } else {
      Node newIndex = new Node(data, null);
      Node aUndan = this.head;
      for (int i = 0; i < index-1; i++) { // Faum hnutinn sem er i saetinu a
        aUndan = aUndan.next;             // undan thvi sem vid erum ad setja i
      }
      newIndex.next = aUndan.next;        // Latum nyja hnutinn visa i thad sem hnuturinn a undan var ad visa i
      aUndan.next = newIndex;             // Latum svo hnutinn a undan nu benda a nyja hnutinn
      this.length = this.size() + 1;
    }
  }

  public static void main(String[] args) {
    SinglyLinkedList<Integer> list1 = new SinglyLinkedList<>();
    try {
      list1.insert(0, 2); // Athugum hvort vid getum baett vid staki i toman lista
      System.out.println(list1); // [ 2 ]
      list1.insert(0, 1); // Athugum hvort vid getum baett staki fremst i lista
      System.out.println(list1); // [ 1 2 ]
      list1.insert(2, 4); // Athugum hvort vid getum baett staki aftast i lista
      System.out.println(list1); // [ 1 2 4 ]
      list1.insert(2, 3); // Athugum hvort vid getum baett staki i midjan lista
      System.out.println(list1); // [ 1 2 3 4]
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Innsetningaradferdin brast thegar hun atti ekki ad gera thad");
      e.printStackTrace();
    }

    for (int i = 0; i < list1.size(); i++) { // Synum ad get adferdin virki
      System.out.println("list1.get(" + i + "): " + list1.get(i));
    }

    try {
      System.out.println(list1.get(-1));
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Kall a list1.get(-1) mistokst rettilega");
    }

    try {
      System.out.println(list1.get(list1.size()));
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Kall a list1.get(list1.size()) mistokst rettilega");
    }

    // Profum annan lista til ad syna ad hann se fjolnota:
    SinglyLinkedList<Character> list2 = new SinglyLinkedList<>();
    list2.insert(0, 'D');
    list2.insert(0, 'C');
    list2.insert(0, 'B');
    list2.insert(0, 'A');
    System.out.println(list2);
  }
}
