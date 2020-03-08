import edu.princeton.cs.algs4.*;
import java.util.Arrays;


public class farthest {

  static Bag<Double> farthestM(Bag<Point2D> points, int m) {
    int staerd = points.size();
    Double[] lengdir = new Double[staerd];
    int stadsetning = 0;
    Point2D start = new Point2D(0, 0);
    for(Point2D s : points) {
      lengdir[stadsetning] = s.distanceTo(start);
      stadsetning++;
    }
    Arrays.sort(lengdir);
    Bag<Double> skilaBag = new Bag<Double>();
    if (m >= staerd) {
      for(Double s : lengdir) {
        skilaBag.add(s);
      }
    } else {
      for (int i = m; i > 0; i--) {
        skilaBag.add(lengdir[i]);
      }
    }
    return skilaBag;
  }

  public static void main(String[] args) {
    Bag<Point2D> points = new Bag<Point2D>();
    points.add(new Point2D(1, 1));
    points.add(new Point2D(1, 2));
    points.add(new Point2D(1, 3));
    points.add(new Point2D(1, 4));

    Bag<Double> res = farthestM(points, 2);
    StdOut.println("Skjodan hefur " + res.size() + " stok.");
    StdOut.print("Thau eru: ");
    for (Double s : res) {
        StdOut.print(s + " , ");
    }
  }

}
