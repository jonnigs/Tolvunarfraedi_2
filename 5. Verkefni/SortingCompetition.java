import edu.princeton.cs.algs4.*;

public class SortingCompetition {

  /* Tekur timann a hvad tolvan er lengi a rada fylki
  ** ad lengd size med Insertion adferd. */
  public static double timeInsertionSort(int size, long seed) {
    double time = 0;
    Double[] fylki = MoreRandom.getRandomDoubleArray(size, seed);
    double startTime = System.nanoTime();
    Insertion.sort(fylki);
    double endTime = System.nanoTime();
    time = time + endTime - startTime;
    return time;
  }

  /* Tekur timann a hvad tolvan er lengi a rada fylki
  ** ad lengd size med Megre adferd.*/
  public static double timeMergeSort(int size, long seed) {
    double time = 0;
    Double[] fylki = MoreRandom.getRandomDoubleArray(size, seed);
    double startTime = System.nanoTime();
    Merge.sort(fylki);
    double endTime = System.nanoTime();
    time = time + endTime - startTime;
    return time;
  }

  public static void main(String[] args) {

    int maxN = 1000; // Vid gefumst upp eftir 1000 stok
    int numTrials = 50000; // Fjoldi maelinga fyrir hverja staerd fylkis, her mjog stort
    long seed = 203; // Fastur grunnur fyrir slembitolugjafann
    int totalN = 0;
    for (int j = 0; j < 10; j++) {  // Baetti vid for lykkju utan um allt til að enda a ad taka medaltal af medaltolunum vegna flokts
      int n = 10; // Byrjum að skoða fylki af þessari staerd

      long insertionTime = 0;
      long mergeTime = Long.MAX_VALUE;
      while (insertionTime < mergeTime && n < maxN) { // Profa thar til Merge er fljotvirkara
        double totalInsertion = 0;
        double totalMerge = 0;
        for (int i = 0; i < numTrials; i++){ // 50.000 sinnum tekur forritid tima a Insertion og Merge á n staka fylki
          totalInsertion = totalInsertion + timeInsertionSort(n , seed);
          totalMerge = totalMerge + timeMergeSort(n, seed);
        }
        insertionTime = (long)totalInsertion/(long)numTrials;
        mergeTime = (long)totalMerge/(long)numTrials;
        n++;
      }
      totalN = totalN + n;
      StdOut.println(n);
    }
    StdOut.print("Medal tala sem Merge tekur framur Insertion er: " + totalN/10);
  }
}
