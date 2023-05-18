int[] array = {22, 27, 16, 2, 18, 6};

var tempData = 0;
var minNumber = 0;

for(var i = 0; i < array.Length-1; i++)
{
    minNumber = i;
    for (var j = i+1; j<array.Length; j++)
    {
        if (array[j] < array[minNumber])
        {
            minNumber = j;
        }
    }
    tempData = array[i];
    array[i] = array[minNumber];
    array[minNumber] = tempData;
}
 