class Solution {
    public static int[] findArray(int[] pref) {

        int[] res = new int[pref.length];
        res[0]=pref[0];
        int cum=pref[0];
        // Used property that if a xor b = c; then a xor c = b;
        for(int i=1;i<pref.length;i++){
            res[i] = cum ^ pref[i];
            cum^=res[i];
        }
        return res;
    }

    public static int main(String[] str){

        int[] pref = {5,2,0,3,1};

        System.out.println("===Input===");
        for(int i:pref){
          System.out.print(i+" ");
        }
        System.out.println("===Input===");

        int[] ans = findArray(pref);

        System.out.println("===Output===");
        for(int i:ans){
          System.out.print(i+" ");
        }
        System.out.println("===Output===");
    }
}
