import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class EgyptianFractions {
  private static BigInteger gcd(BigInteger a, BigInteger b) {
    if (b.equals(BigInteger.ZERO)) {
      return a;
    }
    return gcd(b, a.mod(b));
  }

  private static class Frac implements Comparable<Frac> {
    private BigInteger num, denom;

    public Frac(BigInteger n, BigInteger d) {
      if (d.equals(BigInteger.ZERO)) {
        throw new IllegalArgumentException("Parameter d may not be zero.");
      }

      BigInteger nn = n;
      BigInteger dd = d;
      if (nn.equals(BigInteger.ZERO)) {
        dd = BigInteger.ONE;
      } else if (dd.compareTo(BigInteger.ZERO) < 0) {
        nn = nn.negate();
        dd = dd.negate();
      }
      BigInteger g = gcd(nn, dd).abs();
      if (g.compareTo(BigInteger.ZERO) > 0) {
        nn = nn.divide(g);
        dd = dd.divide(g);
      }
      num = nn;
      denom = dd;
    }

    public Frac(int n, int d) {
      this(BigInteger.valueOf(n), BigInteger.valueOf(d));
    }

    public Frac plus(Frac rhs) {
      return new Frac(
              num.multiply(rhs.denom).add(denom.multiply(rhs.num)),
              rhs.denom.multiply(denom)
      );
    }

    public Frac unaryMinus() {
      return new Frac(num.negate(), denom);
    }

    public Frac minus(Frac rhs) {
      return plus(rhs.unaryMinus());
    }

    @Override
    public int compareTo(Frac rhs) {
      BigDecimal diff = this.toBigDecimal().subtract(rhs.toBigDecimal());
      if (diff.compareTo(BigDecimal.ZERO) < 0) {
        return -1;
      }
      if (BigDecimal.ZERO.compareTo(diff) < 0) {
        return 1;
      }
      return 0;
    }

    @Override
    public boolean equals(Object obj) {
      if (!(obj instanceof Frac)) {
        return false;
      }
      Frac rhs = (Frac) obj;
      return compareTo(rhs) == 0;
    }

    @Override
    public String toString() {
      if (denom.equals(BigInteger.ONE)) {
        return num.toString();
      }
      return String.format("%s/%s", num, denom);
    }

    public BigDecimal toBigDecimal() {
      BigDecimal bdn = new BigDecimal(num);
      BigDecimal bdd = new BigDecimal(denom);
      return bdn.divide(bdd, MathContext.DECIMAL128);
    }

    public List<Frac> toEgyptian() {
      if (num.equals(BigInteger.ZERO)) {
        return Collections.singletonList(this);
      }
      List<Frac> fracs = new ArrayList<>();
      if (num.abs().compareTo(denom.abs()) >= 0) {
        Frac div = new Frac(num.divide(denom), BigInteger.ONE);
        Frac rem = this.minus(div);
        fracs.add(div);
        toEgyptian(rem.num, rem.denom, fracs);
      } else {
        toEgyptian(num, denom, fracs);
      }
      return fracs;
    }

    public void toEgyptian(BigInteger n, BigInteger d, List<Frac> fracs) {
      if (n.equals(BigInteger.ZERO)) {
        return;
      }
      BigDecimal n2 = new BigDecimal(n);
      BigDecimal d2 = new BigDecimal(d);
      BigDecimal[] divRem = d2.divideAndRemainder(n2, MathContext.UNLIMITED);
      BigInteger div = divRem[0].toBigInteger();
      if (divRem[1].compareTo(BigDecimal.ZERO) > 0) {
        div = div.add(BigInteger.ONE);
      }
      fracs.add(new Frac(BigInteger.ONE, div));
      BigInteger n3 = d.negate().mod(n);
      if (n3.compareTo(BigInteger.ZERO) < 0) {
        n3 = n3.add(n);
      }
      BigInteger d3 = d.multiply(div);
      Frac f = new Frac(n3, d3);
      if (f.num.equals(BigInteger.ONE)) {
        fracs.add(f);
        return;
      }
      toEgyptian(f.num, f.denom, fracs);
    }
  }
}
