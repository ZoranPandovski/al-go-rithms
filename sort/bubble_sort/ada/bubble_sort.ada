import std.stdio, std.algorithm : swap;
 
T[] bubbleSort(T)(T[] data) pure nothrow
{
    foreach_reverse (n; 0 .. data.length)
    {
        bool swapped;
        foreach (i; 0 .. n)
            if (data[i] > data[i + 1]) {
                swap(data[i], data[i + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
    return data;
}
 
 
void main()
{
    auto array = [28, 44, 46, 24, 19, 2, 17, 11, 25, 4];
    writeln(array.bubbleSort());
}
