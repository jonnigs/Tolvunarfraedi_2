import edu.princeton.cs.algs4.*;

public class reverse<Item> {
  public static void reverseStack(Stack<Item> stack) {
    Stack<Item> reversed = new Stack<Item>();
    Stack<Item> same = new Stack<Item>();
    while(!stack.isEmpty()) {
      reversed.push(stack.pop()); // Snuum stack vid a reversed
    }
    while(!reversed.isEmpty()) {
      same.push(reversed.pop());  // Snuum reversed vid a same, sem er tha eins og stack
    }
    while(!same.isEmpty()) {
      stack.push(same.pop());  // Snuum same vid a stack, stack er tha i ofugri rod midad vid hvernig hann byrjadi
    }
  }

  public static void main(String[] args) {
    Stack<Integer> hladi1 = new Stack<Integer>();
    //Stack<String> hladi2 = new Stack<String>;
    hladi1.push(1);
    hladi1.push(2);
    hladi1.push(3);
    hladi1.push(4);
    reverseStack(hladi1);
    for(int i = 0; i < 4; i++) {
      StdOut.print(hladi1.pop());
    }
    /*hladi2.push('a');
    hladi2.push('b');
    hladi2.push('c');
    hladi2.push('d');*/


  }

}
