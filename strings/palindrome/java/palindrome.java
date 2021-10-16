public class Main {

    public static void main(String[] args) {
        System.out.println(palindrome("GUTOXOTUG")); //PALINDROME
        System.out.println(palindrome("ABCDEFGHJ")); // NOT PALINDROME
    }

    public static String palindrome2(String word){
        StringBuilder right;
        String left;
        int length = word.length(), axys = 0;

        if(length%2 == 0)
            axys = length/2;
        else
            axys = (length/2)+1;

        right = new StringBuilder(word.substring(axys,length));
        left = word.substring(0, (length/2));

        if(left.equals(right.reverse().toString()))
            return "Palindrome";
        return "Not Palindrome";
    }
}
