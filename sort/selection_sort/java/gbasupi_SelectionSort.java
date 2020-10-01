public class gbasupi_SelectionSort
{
    public static void SelectionSort()
    {
        //Sorting an Array
        int [] Array = {1,8,7,4,6,5,3,2,10,11};

        //Print Array before sorting
        System.out.println("Array before sorting");
        for(int x :Array)
        {
            System.out.print(x+", ");
        }
        System.out.println(" ");

        for(int i = Array.length-1;i>=0;i--)
        {
            int max = Array[0];
            int Pos = 0;
            for(int j = 0;j<=i;j++)
            {
                if(max<Array[j])
                {
                    max = Array[j];
                    Pos = j;
                }
            }
            int temp = Array[i];
            Array[i] = max;
            Array [Pos] = temp;
        }

        //Print Array after sorting
        System.out.println("Array After sorting");
        for(int x :Array)
            System.out.print(x+", ");
    }

    public static void main(String []args)
    {
        SelectionSort();
    }
}
