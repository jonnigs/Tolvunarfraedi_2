import edu.princeton.cs.algs4.*;

public class v2 {

  public static double timeBST(int arraySize, int numTrials) {
    // Buum til tre til ad leita i
    BinarySearchST<Integer, Integer> bst = new BinarySearchST<Integer, Integer>();
    for (Integer i = 0; i < arraySize; i++) {
      bst.put(i, i);
    }
    // Leitum og tokum timann
    double time = 0;
    double a = (double)arraySize;
    StdRandom.setSeed(2018); // Fast random seed
    for (int i = 0; i < numTrials; i++){
      // Fáum random lykil fra 0 - arraySize
      double rand = StdRandom.uniform();
      int k = (int)(a*rand);
      double startTime = System.nanoTime();
      int d = bst.get(k);
      double endTime = System.nanoTime();
      time = time + endTime - startTime;
    }
    // Skilum medal tima sem tok ad leita fyrir arraySize
    return time/numTrials;
  }

  public static void main(String[] args) {
    /* Skilgreining gagna */
    int maxArraySize = 5000000; // Mesta stærð á fylki sem við ætlum að tímamæla
    int stride = 50000; // Bil á milli stærða
    int numTrials = 20000; // Fjöldi mælinga fyrir hverja stærð fylkis

    /* Maelingar */
    double[] medalTimaFylki = new double[maxArraySize/stride];
    int stadur = 0;

    for (int i = 50000; i < maxArraySize + 1; i += stride) {
      medalTimaFylki[stadur] = timeBST(i, numTrials);
      stadur++;
    }

    /* Teikning a nidurstodum */
    StdDraw.setXscale(-(0.05*maxArraySize),maxArraySize*1.05); // Setjum teiknigluggann 5% af arraySize utfyrir á x-as
    double max = 0;
    for (int i = 1; i < medalTimaFylki.length; i++)
    {
      if (medalTimaFylki[i] > max)
      {
        max = medalTimaFylki[i];
      }
    }
    StdDraw.setYscale(-(0.05*max), max*1.05); // 5% haerri gluggi en stardstagildid
    StdDraw.setPenRadius(0.008);
    for (int i = 0; i < medalTimaFylki.length; i++) {
      StdDraw.point(i*stride, medalTimaFylki[i]);
    }
  }
}
