import java.util.*;

public class ShellSort {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[] elements;
    System.out.println("Enter the number of elements: ");
    int j, n = sc.nextInt();
    elements = new int[n];
    int gap = n / 2;
    System.out.println("Enter elements: ");
    for(int i = 0; i < n; i++)
      elements[i] = sc.nextInt();
    while(gap >= 1) {
      for(int i = gap; i < n; i += gap) {
        int item = elements[i];
        for(j = i - gap; j >= 0 && elements[j] > item; j -= gap) {
          elements[j + gap] = elements[j];
        }
        elements[j + gap] = item;
      }
      gap /= 2;
    }
    for(int i = 0; i < n; i++) {
      System.out.print(elements[i] + " ");
    }
    System.out.println();
  }
}
