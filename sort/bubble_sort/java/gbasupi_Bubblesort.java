public class gbasupi_Bubblesort
{
    //method for bubble sorting
    public static void BubbleSort()
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
            for(int j = 0;j<i;j++)
            {
                if(Array[j]>Array[j+1])
                {
                    int temp = Array[j];
                    Array[j] = Array[j+1];
                    Array[j+1] = temp;
                }
            }
        }

        //Print Array after sorting
        System.out.println("Array After sorting");
        for(int x :Array)
            System.out.print(x+", ");
    }


    public static void main(String []args)
    {
        BubbleSort();
    }
}
