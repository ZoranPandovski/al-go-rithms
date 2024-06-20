import java.util.Random;

public class Demo {
    public static void main(String[] args) {
        Random n = new Random();
        int[] b = new int[1000];

        //generating random numbers between 0 and 10000
        for(int i=0;i<1000;i++)
        {
            b[i]= n.nextInt(10000);
        }

        Sort ISort=new Sort();
        System.out.println("-- Insertion Sort --");
        ISort.Insertion(b);

        System.out.println("-- Selection Sort --");
        ISort.SelectionSort(b);

        System.out.println("-- Bubble Sort --");
        ISort.BubbleSort(b);
    }
}

class Sort{
    public void Insertion(int[] a){
        for(int i=1;i<a.length;i++)
        {
            int j=i;
            for(j=i;j>0;j--)
            if(a[j]<a[j-1])
            {   int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }

        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
    }

    public void SelectionSort(int[] a)
    {
        for(int i=0;i<a.length;i++)
        {
            int min=a[i];
            int MinIndex=i;
            for(int j=i+1;j<a.length;j++)
            {
                if(min>a[j])
                {
                    min=a[j];
                    MinIndex=j;
                }
            }
            if(min<a[i])
            {
                int temp=a[i];
                a[i]=a[MinIndex];
                a[MinIndex]=temp;
            }
        }

        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
    }

    public void BubbleSort(int[] a){
        for(int i=a.length;i>0;i--)
        {
            for(int j=0;j<i-1;j++)
            {
                if(a[j+1]<a[j])
                {
                    int temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
            }
        }

        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
    }
}
