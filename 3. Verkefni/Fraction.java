public class Fraction implements Comparable<Fraction> {
  private int num;
  private int den;


  Fraction(int numerator, int denominator) {
    if (denominator == 0) {
      throw new ArithmeticException("Bannað að deila með núlli");
    }
    this.num = numerator;
    this.den = denominator;
  }

  public Fraction plus(Fraction f) {
    return new Fraction(this.num * f.den + f.num * this.den, this.den * f.den);
  }

  public boolean equals(Fraction f) {
    if (f == null) {                          // Byrja strax a ad gefa false a null
      return false;
    }
    float a = ((float) this.num) / this.den; // Breyti almennu broti i
    float b = ((float) f.num) / f.den;       // tugabrot til að bera saman
    if (a == b){
      return true;
    } else {
      return false;
    }
  }

  @Override
  public int compareTo(Fraction f) {
    float a = ((float) this.num) / this.den; // Breyti almennu broti i
    float b = ((float) f.num) / f.den;       // tugabrot til að bera saman
    if (a == b) {
      return 0;
    } else if (a >= b) {
      return 1;
    } else {
      return -1;
    }
  }

  public static void main(String args[]) {
    Fraction p = new Fraction(1, 2);
    Fraction r = new Fraction(-1, -2);
    Fraction q = new Fraction(2, 6);
    Fraction s = new Fraction(1, 4);
    Fraction t = new Fraction(2, 4);

    // Profum hvort .equals adferdin se sjalfhverf (tharf ad vera satt)
    System.out.println("p.equals(p): " + p.equals(p));
    // Profum hvort .equals adferdin se samhverf (tharf ad vera eins)
    System.out.println("p.equals(r): " + p.equals(r));
    System.out.println("r.equals(p): " + r.equals(p));
    // Profum hvort .equals adferdin se gegnvirk (allt tharf ad vera eins)
    System.out.println("p.equals(r): " + p.equals(r));
    System.out.println("r.equals(t): " + r.equals(t));
    System.out.println("p.equals(t): " + p.equals(t));
    // Profum hvort .equals adferdin hafni samanburdi vid null (tharf ad vera false):
    System.out.println("t.equals(null): " + t.equals(null));

    // Profum hvort .compareTo se sjalfhverf (tharf ad vera 0)
    System.out.println("q.compareTo(q): " + q.compareTo(q));

    // Profum hvort .compareTo se andsamhverf (tharf ad vera mismunandi)
    System.out.println("r.compareTo(q): " + r.compareTo(q));
    System.out.println("q.compareTo(r): " + q.compareTo(r));

    // Profum hvort .compareTo se gegnvirk (allt tharf ad vera eins)
    System.out.println("r.compareTo(q): " + r.compareTo(q));
    System.out.println("q.compareTo(s): " + q.compareTo(s));
    System.out.println("r.compareTo(s): " + r.compareTo(s));

  }


}
