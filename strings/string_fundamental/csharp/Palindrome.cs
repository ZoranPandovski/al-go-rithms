static void Main(string[] args)
{
    Console.WriteLine(Palindrome("A Santa dog lived as a devil God at NASA."));
    Console.WriteLine(PalindromeQuick("Red rum, sir, is murder."));

    Console.ReadKey();
}

public static Boolean Palindrome(String input)
{
    // Split the input into an array of characters
    char[] array = input.ToCharArray();

    // Create the first string builder to hold the processed input
    StringBuilder sb = new StringBuilder();

    // Process the input to set all letters to lower case, and remove non-alphabetical characters
    for (int i = 0; i < array.Length; i++)
    {
        char o = array[i];

        // If the character is upper-case, increment it by 32, to move it to it's lower case counterpart
        // See ASCII Table for more details on this
        if (o >= 'A' && o <= 'Z')
        {
            o += (char)32;
        }

        // Once processed, only add characters to the string builder if they are between lowercase 'a', and 'z'
        if (o >= 'a' && o <= 'z')
        {
            sb.Append(o);
        }
    }

    // Dump the newly-processed characters into a string object
    String inputProcessed = sb.ToString();

    // Reset the input array to the newly processed input
    array = inputProcessed.ToCharArray();

    // Reset the StringBuilder back to scratch for the output
    sb = new StringBuilder();

    // Loop through the word backwards (starting at the last letter, decrementing to 0)
    for (int i = array.Length; i > 0; i--)
    {
        // Add each character to the Output string in the reverse order
        sb.Append(array[i - 1]);
    }

    // Dump the output into a string object
    String output = sb.ToString();

    // If the Input is the same as the reversed Output, return appropriate boolean value
    if (inputProcessed == output)
    {
        return true;
    }
    else
    {
        return false;
    }
}

public static Boolean PalindromeQuick(string input)
{
    // Set to lowercase, and strip any non-alphanumerical characters
    Regex rgx = new System.Text.RegularExpressions.Regex("[^a-z0-9]");
    input = rgx.Replace(input.ToLower(), "");

    // Split the sanatized input into an array, reverse it, and dump it into an output string
    char[] array = input.ToCharArray();
    Array.Reverse(array);
    string output = new string(array);

    // If the Input is the same as the flipped Output, return appropriate boolean value
    if (input == output)
    {
        return true;
    }
    else
    {
        return false;
    }
}
