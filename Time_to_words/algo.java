
import java.util.*;
import java.io.*;


public class stringcount {

    public static String Switch(int i){
        switch(i)
        {
             case 1:
                return "one";
             case 2:
                return "two";
             case 3:
                return "three";
             case 4:
                return "four";
             case 5:
                return "five";
             case 6:
                return "six";
             case 7:
                return "seven";
             case 8:
                return "eight";
             case 9:
                return "nine";
             case 10:
                return "ten";
             case 11:
                return "eleven";
             case 12:
                return "twelve";
             case 13:
                return "thirteen";
             case 14:
                return "fourteen";
             case 15:
                return "fifteen";
             case 16:
                return "sixteen";
             case 17:
                return "seventeen";
             case 18:
                return "eighteen";
             case 19:
                return "nineteen";
             case 20:
                return "twenty";
             case 21:
                return "twenty one";
             case 22:
                return "twenty two";
             case 23:
                return "twenty three";
             case 24:
                return "twenty four";
             case 25:
                return "twenty five";
             case 26:
                return "twenty six";
             case 27:
                return "twenty seven";
             case 28:
                return "twenty eight";
             case 29:
                return "twenty nine";
             default :
                return "None";
        }
    }

    // Complete the timeInWords function below.
    static String timeInWords(int h, int m) {
        String ans = "";
        if(m == 0){
            String hour = Switch(h);
            ans = hour + " o' clock";

        }

        if(m == 15){
            String hour = Switch(h);
            ans = "quarter past "+ hour;
        }

        if(m == 45){
            if(h == 12){
                ans = "quarter to one";
            }
            else{
                String hour = Switch(h+1);
                ans = "quarter to "+hour;
            }
        }

        if(m == 30){
            String hour = Switch(h);
            ans = "half past "+hour;
        }

        if(m < 30 && m > 0 && m != 15){
            String hour = Switch(h);
            if(m == 1){
                ans = "one minute past "+hour;
            }
            else{
                String minute = Switch(m);
                ans = minute+" minutes past "+hour;
            }
        }

        if(m > 30 && m != 45){
            if(h == 12){
                if(m == 59){
                    ans = "one minute to one";
                }
                else{
                    String minute = Switch(60-m);
                    ans = minute+" minutes to one";
                }
            }
            else{
                String hour = Switch(h+1);
                if(m == 59){
                    ans = "one minute to "+hour;
                }
                else{
                    String minute = Switch(60-m);
                    ans = minute+" minutes to "+hour;
                }
            }
        }
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
