static void Main(string[] args)
{
    Console.WriteLine(Anagram("Tom Marvolo Riddle", "I am Lord Voldemort"));

    Console.ReadKey();
}

public static Boolean Anagram(String input1, String input2)
{
    // Convert both inputs to lower case, and remove non-alphabetical characters
    Regex rgx = new System.Text.RegularExpressions.Regex("[^a-z0-9]");
    input1 = rgx.Replace(input1.ToLower(), "");
    input2 = rgx.Replace(input2.ToLower(), "");

    // Break both inputs down into character arrays
    char[] process1 = input1.ToCharArray();
    char[] process2 = input2.ToCharArray();

    // Prepare two arrays to count ocurrences each letter of the alphabet in their respective inputs
    int[] array1 = new int[26];
    int[] array2 = new int[26];

    // Count up the letters in the first input
    for (int i = 0; i < input1.Length; i++)
    {
        int v = (int)process1[i] - 97;
        array1[v]++;
    }

    // Count up the letters in the second input
    for (int i = 0; i < input2.Length; i++)
    {
        array2[((int)process2[i])-97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }

    return true;
}
