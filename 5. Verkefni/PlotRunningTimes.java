import edu.princeton.cs.algs4.*;

public class PlotRunningTimes {

  public static double timeInsertionSort(int arraySize, int numTrials, long seed) {
    /*
    Skilar meðalkeyrslutíma innsetningarröðunar á slembifylki af stærð <arraySize>
    eftir <numTrials> keyrslur, með slembitölugjafann stilltan á <seed>.
    */
    double time = 0;
    for (int i = 0; i < numTrials; i++) {
      Double[] fylki = MoreRandom.getRandomDoubleArray(arraySize, seed); // Verdur alltaf sama fylkid...

      double startTime = System.nanoTime();
      Insertion.sort(fylki);
      double endTime = System.nanoTime();
      time = time + endTime - startTime;
    }
    return time/numTrials;
  }

  public static void main(String[] args) {
    /* Skilgreining gagna */
    int maxArraySize = 5000; // Mesta stærð á fylki sem við ætlum að tímamæla
    int stride = 10; // Bil á milli stærða
    int numTrials = 20; // Fjöldi mælinga fyrir hverja stærð fylkis
    long seed = 203; // Fastur grunnur fyrir slembitölugjafann

    /* Mælingar */
    double[] medalTimaFylki = new double[maxArraySize/stride];
    int saeti = 0;
    for (int i = 0; i < maxArraySize; i += stride) {
      double time = timeInsertionSort(i, numTrials, seed);
      medalTimaFylki[saeti] = time;
      saeti++;
    }

    /* Teikning á niðurstöðum */
    StdDraw.setXscale(-(0.05*maxArraySize),maxArraySize*1.05);
    double max = 0;
    for (int i = 1; i < medalTimaFylki.length; i++)
    {
      if (medalTimaFylki[i] > max)
      {
        max = medalTimaFylki[i];
      }
    }
    StdDraw.setYscale(-(0.05*max), max*1.05);
    StdDraw.setPenRadius(0.008);
    for (int i = 0; i < medalTimaFylki.length; i++) {
      StdDraw.point(i*stride, medalTimaFylki[i]);
    }
  }
}
