import java.util.*;

class minNumberOfJumps {
  static int minJumps(int[] a) {
    int currF = 0, currM = 0, jumps = 0;
    if (a[0] == 0)
      return -1;
    for (int i = 0; i < a.length - 1; i++) {
      currF = Math.max(currF, i + a[i]);
      if (currM == i) {
        jumps++;
        currM = currF;
      }
    }
    if (currM >= a.length - 1)
      return jumps;
    else
      return -1;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    int ans = minJumps(arr);
    System.out.println(ans);
  }
}