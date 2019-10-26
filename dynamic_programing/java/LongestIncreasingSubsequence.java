import java.util.ArrayList;
import java.util.List;

public class LIS {
    public static int lowerBound(List<Integer> a, int low, int high, int element){
        while(low < high){
            int middle = low + (high - low)/2;
            if(element > a.get(middle))
                low = middle + 1;
            else
                high = middle;
        }
        return low;
    }

    public static int upperBound(List<Integer> a, int low, int high, int element){
        while(low < high){
            int middle = low + (high - low)/2;
            if(a.get(middle) > element)
                high = middle;
            else
                low = middle + 1;
        }
        return low;
    }

    public static int longestIncreasingSubsequence(List<Integer> a){
        //equals included then upperbound
        // else lower bound use as required
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=0;i<a.size();i++){
            int x = lowerBound(ans,0,ans.size(),a.get(i));
            if(x+1>ans.size()){
                ans.add(a.get(i));
            }
            else
            ans.set(x,a.get(i));
        }
        return ans.size();
    }

}