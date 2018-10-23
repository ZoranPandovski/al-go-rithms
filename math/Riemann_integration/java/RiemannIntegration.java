package integralreimann;
import java.text.NumberFormat;
import java.util.Scanner;

/**
 *
 * @author erickAndreas
 */
public class IntegralReimann {

    public static void main(String[] args) {
        double a, b, h, x = 0, area = 0;
        int n, i = 0;

        NumberFormat nf = NumberFormat.getInstance();
        nf.setMaximumFractionDigits(2);
        Scanner input = new Scanner(System.in);

        System.out.print("Input limit for A: ");
        a = input.nextDouble();
        System.out.print("Input limit for B : ");
        b = input.nextDouble();
        System.out.print("Input divider number : ");
        n = input.nextInt();

        h = (b - a) / n;
        System.out.println("|i\t|x\t|f(x)\t|");
        for (x = a; x <= (b + h); x += h) {
            area += f(x);
            System.out.println("|" + i + "\t|" + nf.format(x) + "\t|"
                    + nf.format(f(x)) + "\t|");
            i++;
        }

        area *= h;
        System.out.println("area : " + nf.format(area));
        System.out.println("Eksak Value: " + nf.format((eksak(b) - eksak(a))));
        System.out.println("Error Value: " + nf.format(Math.abs(area - (eksak(b) - eksak(a)))));
    }

    static double f(double x) {
        return x * x;
    }

    static double eksak(double x) {
        return (x * x * x) / 3;
    }

}