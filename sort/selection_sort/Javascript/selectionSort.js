function SelectionSort(a)
{
    var small,pos,i;
    for(var m=0;m<a.length-1;m++)
    {
        small = a[m]; pos = m;
        for(i=m+1;i<a.length;i++)
        {
            if(a[i]<small)
            {
                //console.log("Swapped here");
                small = a[i];
                pos = i;
            }
        }

        //now we have to swap the value at index m with value at index pos
        a[pos] = a[m];//we had initially saved the value at mth index of a
        a[m] = small;
    }
    
    return a;
}

var a= [7,6,5,4,3,2,1];
console.log("Elements Before Selection sort-->",a);
console.log("Elements After Selection Sort-->",SelectionSort(a));
