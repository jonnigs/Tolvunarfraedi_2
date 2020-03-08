/*
 Takmörkuð eftirlíking af java.util.ArrayList klasanum fyrir Tölvunarfræði 2
 */
import java.util.Iterator;
import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdOut;

public class ArrayList<Item> implements Iterable<Item>{
    private Item[] storage; // Fjölnota geymslusvæði
    private int length; // Fjöldi staka í listanum

    public ArrayList() {
        //Smiður, býr til tóman lista með upphafsrýmd 2
        this.storage = (Item[]) new Object[2];
        this.length = 0;
    }

    public int size() {
        // Skilar fjölda staka í listanum
        return this.length;
    }

    public int capacity() {
        // Skilar rýmd listans, fjölda staka sem hægt er að bæta við án þess að breyta geymslusvæðinu
        return this.storage.length;
    }

    public void clear() {
        // Eyðir öllum stökum úr listanum og upphafsstillir rýmd hans
        this.storage = (Item[]) new Object[2];
        this.length = 0;
    }

    private void resize(int newCapacity) {
        // Eykur rýmd listans upp í newCapacity, ekki er gert ráð fyrir minnkun á rýmd
        assert newCapacity >= length;

        Item[] temp = (Item[]) new Object[newCapacity];
        for (int i = 0; i < this.length; i++) {
            temp[i] = this.storage[i];
        }
        this.storage = temp;
    }

    public Item get(int index) {
        // Sækir stak númer index í listanum
        if (index < 0 || this.size() <= index) {
            throw new IndexOutOfBoundsException("Þessi vísir er utan geymslunnar");
        }
        return this.storage[index];
    }

    public Item set(int index, Item item) {
        // Yfirskrifar stak númer index með item
        Item previousItem = this.storage[index];
        this.storage[index] = item;
        return previousItem;
    }

    public void add(Item item) {
        // Bætir item aftast í listann, eykur rýmd ef á þarf að halda
        if (this.length == this.storage.length) {
            this.resize(2 * this.storage.length);
        }
        this.storage[this.length++] = item;
    }

    public void add(int index, Item item) {
        // Bætir item í listann í staðsetningu index,
        if (index < 0 || this.size() < index) {
            throw new IndexOutOfBoundsException("Þessi vísir er utan geymslunnar");
        } else if (index == this.length) {
            this.add(item);
        } else {
            Item oldItem = this.set(index, item);
            this.add(index + 1, oldItem);
        }
    }

    public Iterator<Item> iterator()  {
      return new ListIterator<Item>(storage);
    }

    private class ListIterator<Item> implements Iterator<Item> {
      private int currentIndex;
      private Item[] current;

      public ListIterator(Item[] first) {
        current = first;
        currentIndex = 0;
      }

      public boolean hasNext() { return current != null;                     }
      public void remove()     { throw new UnsupportedOperationException();  }

      public Item next() {
        if (!hasNext()) throw new NoSuchElementException();
        Item item = current[currentIndex];
        if (currentIndex < size()-1) {
          currentIndex = currentIndex + 1;
        } else {
          current = null;
        }
        return item;
      }
    }

    public static void main(String[] args) {
        ArrayList<Character> myList = new ArrayList<>();
        myList.add(0, 'A'); // Tómur listi búinn til
        myList.add(1, 'N');
        myList.add(1, 'A');
        myList.add(3, 'I'); // Bætt aftast í lista
        myList.add(0, 'B'); // Bætt framan á lista
        myList.add(2, 'N');

        StdOut.print("[ ");

        // Afkommentið þetta fyrir sýnidæmið
        for (Character c : myList) {
            StdOut.print(c + " ");
        }
        StdOut.println("]");
    }

}
