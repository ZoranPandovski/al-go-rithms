public class countingSort {
    static void CountSort(int a[],int n){
        int max=a[0];
        for (int i = 0; i <n; i++) {
            if(a[i]>max){
                max=a[i];
            }
        }
        int[] elements=new int[max+1];
        for (int i = 0; i <n; i++) {
            elements[a[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            elements[i]+=elements[i-1];
        }
        int[] output=new int[max];
        for (int i = n-1; i>=0; i--) {
            output[--elements[a[i]]]=a[i];
        }
        for (int i = 0; i < n; i++) {
            a[i]=output[i];
        }

    }
    public static void main(String[] args) {
        int[] a={1,6,4,2,7,5,3,8,5,7,4,6,2,1,5,7,4,7,4,7,5,67};
        CountSort(a, a.length);
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
    }
}
