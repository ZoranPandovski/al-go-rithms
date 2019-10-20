package strings.string_search.knuth_morris_pratt.Java;

/**
 * Author - archit.s
 * Date - 18/10/18
 * Time - 1:38 PM
 */
public class KMP {

    void computeLPS(String pattern, int lps[]){

        int len = 0;
        int i = 1;
        lps[0] = 0;

        while(i<pattern.length()){
            if(pattern.charAt(i) == pattern.charAt(len)){
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len!=0){
                    len = lps[len-1];
                }else {
                    lps[i]= 0;
                    i++;
                }
            }
        }
    }

    int KMPSearch(String pattern, String text){

        int M = pattern.length();
        int N = text.length();

        int[] lps = new int[M];

        computeLPS(pattern, lps);

        int j=0;
        int i=0;

        while(i<N){
            if(pattern.charAt(j) == text.charAt(i)){
                i++;
                j++;
            }

            if(j == M){
                return i-j;
            }
            else if(i<N && pattern.charAt(j)!=text.charAt(i)){
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        String pattern = "tect";
        String text = "architecture";

        KMP kmp = new KMP();
        final int kmpSearch = kmp.KMPSearch(pattern, text);
        if(kmpSearch != -1){
            System.out.println("Pattern Found at : " + (kmpSearch));
        }
        else{
            System.out.println("No Matching Pattern Found");
        }
    }
}
