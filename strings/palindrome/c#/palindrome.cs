class StringUtility
{
    public static bool IsPolindrome(string text)
    {
        string reversedText = string.Empty;
        for (int i = text.Length - 1; i > -1; i--)
        {
            reversedText += text[i];
        }
        return reversedText == text ? true : false;
    }
}

