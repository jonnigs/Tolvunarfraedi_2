import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.EdgeWeightedDigraph;
import edu.princeton.cs.algs4.DirectedEdge;
import edu.princeton.cs.algs4.DijkstraSP;

public class v1 {

  public static void main(String[] args) {
    In in = new In(args[0]);
    EdgeWeightedDigraph G = new EdgeWeightedDigraph(in);
    int s = Integer.parseInt(args[1]);

    DijkstraSP sp = new DijkstraSP(G,s);

    int[] hnutar = {168, 200, 201};
    for (int t = 0; t < hnutar.length; t++) {
        if (sp.hasPathTo(hnutar[t])) {
            StdOut.printf("%d to %d (%.2f)  ", s, hnutar[t], sp.distTo(hnutar[t]));
            for (DirectedEdge e : sp.pathTo(hnutar[t])) {
                StdOut.print(e + "   ");
            }
            StdOut.println();
        }
        else {
            StdOut.printf("%d to %d         no path\n", s, hnutar[t]);
        }
    }
  }
}
