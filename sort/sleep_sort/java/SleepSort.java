import java.util.*;

public class SleepSort{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    //Array expected as space separated one line (length in first)
    //10 2 3 11 4 6 7 1 9 8 5 10

    int length = sc.nextInt();
    int[] arr = new int[length];
    for(int i=0; i<length; i++){
      arr[i] = sc.nextInt();
    }
    SleepSort(arr);
  }

  public static void SleepSort(int[] original){
    System.out.println("Sorted Array:");
    for(int i=0; i<original.length; i++){
      final int index = i;
      new Thread()
      {
          @Override
          public void run() {
              try {
                  Thread.sleep(original[index]);
                  System.out.print(original[index]+" ");
              }
              catch (InterruptedException e) {
              }
          }
      }.start();
    }
  }
}