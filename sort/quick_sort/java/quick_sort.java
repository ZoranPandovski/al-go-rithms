//quick_sort classic algorithm

package quick_sort;

import java.util.Random;

public class Main {

    public static  void QuickSort(int[] Data, int Low, int High)
    {
        if(Low<High)
        {
            int Part = Partition(Data, Low, High);
            QuickSort(Data, Low, Part - 1);
            QuickSort(Data, Part + 1, High);
        }

    }

    public static int Partition(int[] Data, int Low, int High)
    {
        int Pivot = Data[High];
        int i=Low-1;
        for(int j=Low;j<High;j++)
        {
            if(Data[j]<=Pivot)
            {
                i++;
                int temp = Data[i];
                Data[i] = Data[j];
                Data[j] = temp;
            }
        }
        if(Data[High]<=Data[i+1])
        {
            int temp = Data[i+1];
            Data[i+1] = Data[High];
            Data[High] =temp;
        }
        return i+1;
    }

    public static int[] GenerateRandom(int ElementLength)
    {
        int[] Garbage = new int[ElementLength];
        Random Random = new Random();
        for(int i=0;i<Garbage.length;i++) Garbage[i] = Random.nextInt(ElementLength);
        return  Garbage;
    }

    public static void main(String[] args) {
        int[] test = new int[10];
        test = GenerateRandom(10);
        for (int i=0;i<10;i++) System.out.print(test[i]+",");
        System.out.println();
        //how to use? 1st param: array of int, 2nd param: starting index, 3rd param: ending index, if it the last one, substract it by one.
        QuickSort(test,0,test.length-1);
        for (int i=0;i<10;i++) System.out.print(test[i]+",");
    }
}
