import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class MoreRandom {

  public static Double[] getRandomDoubleArray(int arraySize, long seed) {
    /*
    Skilar fylki með arraySize jafndreifðum Double tölum á bilinu [0, 1[,
    slembitölugjafi upphafsstilltur með seed.
    */
    Double[] fylki = new Double[arraySize];
    StdRandom.setSeed(seed);
    for(int i = 0; i < arraySize; i++) {
      fylki[i] = StdRandom.uniform();
    }
    return fylki;
  }

  public static void main(String[] args) {
    int arraySize = 3;
    long seed = 203;
    for (Double d : getRandomDoubleArray(arraySize, seed)) {
      StdOut.print(d + " ");
    }
    StdOut.println("");
  }
}
