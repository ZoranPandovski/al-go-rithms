class ZFunction {

    public static void search(String text, String pattern)
    {

        String concat = pattern + "$" + text;
        int l = concat.length();
        int Z[] = new int[l];
        getZarr(concat, Z);
        for(int i = 0; i < l; ++i){
            if(Z[i] == pattern.length()){
                System.out.println("Pattern at index: "
                        + (i - pattern.length() - 1));
            }
        }
    }


    private static void getZarr(String str, int[] Z) {
        int n = str.length();
        int L = 0, R = 0;
        for(int i = 1; i < n; ++i) {
            if(i > R){
                L = R = i;
                while(R < n && str.charAt(R - L) == str.charAt(R))
                    R++;
                Z[i] = R - L;
                R--;

            }
            else{
                int k = i - L;
                if(Z[k] < R - i + 1)
                    Z[i] = Z[k];
                else{
                    L = i;
                    while(R < n && str.charAt(R - L) == str.charAt(R))
                        R++;

                    Z[i] = R - L;
                    R--;
                }
            }
        }
    }

    public static void main(String[] args)
    {
        String text = "SO TESTY TEST, I LIKE SUCH TESTS";
        String pattern = "TEST";

        search(text, pattern);
    }
}