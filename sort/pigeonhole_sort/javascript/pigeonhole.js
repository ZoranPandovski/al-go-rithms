<script>
 
// JavaScript program to implement
// Pigeonhole Sort
 
function pigeonhole_sort(arr, n)
{
    let min = arr[0];
    let max = arr[0];
    let range, i, j, index;
   
    for(let a = 0; a < n; a++)
    {
        if(arr[a] > max)
            max = arr[a];
        if(arr[a] < min)
            min = arr[a];
    }
   
    range = max - min + 1;
    let phole = [];
       
    for(i = 0; i < n; i++)
    phole[i] = 0;
   
    for(i = 0; i < n; i++)
        phole[arr[i] - min]++;
   
       
    index = 0;
   
    for(j = 0; j < range; j++)
        while(phole[j] --> 0)
            arr[index++] = j + min;
   
}
 
// Driver Code
 
    let arr = [8, 3, 2, 7,
                 4, 6, 8];
   
    document.write("Sorted order is : ");
   
    pigeonhole_sort(arr,arr.length);
       
    for(let i = 0 ; i < arr.length ; i++)
        document.write(arr[i] + " ");
     
    // This code is contributed by target_2.
</script>