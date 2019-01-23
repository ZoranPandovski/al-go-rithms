static void Main(string[] args)
{
    Console.WriteLine(Isogram("Psuedomythical"));

    Console.ReadKey();
}

public static Boolean Isogram(String input)
{
    // Convert characters to lower case, and split it into an array of characters
    char[] array = input.ToLower().ToCharArray();

    // Run through an outer and inner loop to search for matches. To explain:
    // OUTER: Runs through each character in the string...
    for (int x = 0; x < array.Length; x++)
    {
        // INNER: ...and checks it against every remaining letter after it to see if there's a match.
        for (int y = x + 1; y < array.Length; y++)
        {
            //  And if they do match...
            if (array[x] == array[y])
            {
                // ...return a failure
                return false;
            }
        }
    }

    // But if we make it to the end, everything is good
    return true;
}
