class Test
{
    
    public static void main(String[] args) 
    {
        int x = 35, index = -1; 
        int arr[] = new int[]{1, 3, 7, 12, 14, 19, 23, 26, 30, 34, 35, 39, 46, 53};
        int lo = 0, hi = (arr.length - 1);
        while (lo <= hi && x >= arr[lo] && x <= arr[hi])
           {
            int pos = lo + (((hi-lo)/(arr[hi]-arr[lo]))*(x - arr[lo]));
            if (arr[pos] == x)
                index = pos;
            if (arr[pos] < x)
                lo = pos + 1;
            else
                hi = pos - 1;
            }
        if (index != -1)
           System.out.println("Element found at index " + index);
        else
           System.out.println("Element not found.");
    }
}