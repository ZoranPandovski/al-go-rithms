import java.util.*;
import java.math.*;

public class CombSort {

  public static void main(String[] args) {
      int[] elements = init();
      sort(elements);
      Arrays.stream(elements).forEach(i -> System.out.print(i + " "));
      System.out.println();
  }

  public static void sort(int[] elements) {
    int gap = elements.length;
    double shrink = 1.3;
    boolean isSorted = false;
    while(!isSorted) {
      gap = (int)Math.floor(gap / shrink);
      if (gap > 1) {
         isSorted = false;
      } else {
         gap = 1;
         isSorted = true;
      }
      for(int i = 0; i + gap < elements.length; i++) {
        if (elements[i] > elements[i + gap]) {
          int tmp = elements[i + gap];
          elements[i + gap] = elements[i];
          elements[i] = tmp;
        }
      }
    }
  }

  public static int[] init() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of elements: ");
    int j, n = sc.nextInt();
    int[] elements = new int[n];
    int gap = n / 2;
    System.out.println("Enter elements: ");
    for(int i = 0; i < n; i++)
      elements[i] = sc.nextInt();
    return elements;
  }
}
