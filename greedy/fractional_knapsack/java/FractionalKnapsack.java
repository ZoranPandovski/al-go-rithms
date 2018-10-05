import java.util.Arrays;

public class FractionalKnapsack {


  private static double getMaxValue(int[] wt, int[] val, int capacity) {
    ItemValue[] iVal = new ItemValue[wt.length];
    for (int i = 0; i < wt.length; i++) {
      iVal[i] = new ItemValue(wt[i], val[i], i);
    }
    //sorting items by value;
    Arrays.sort(iVal, (o1, o2) -> o2.cost.compareTo(o1.cost));
    double totalValue = 0d;
    for (ItemValue i : iVal) {
      int curWt = (int) i.wt;
      int curVal = (int) i.val;
      if (capacity - curWt >= 0) {//this weight can be picked while
        capacity = capacity - curWt;
        totalValue += curVal;
      } else {//item cant be picked whole
        double fraction = ((double) capacity / (double) curWt);
        totalValue += (curVal * fraction);
        capacity = (int) (capacity - (curWt * fraction));
        break;
      }
    }
    return totalValue;

  }

  // item value class
  static class ItemValue {
    Double cost;
    double wt, val, ind;

    // item value function
    ItemValue(int wt, int val, int ind) {
      this.wt = wt;
      this.val = val;
      this.ind = ind;
      cost = (double) (val / wt);
    }

  }

}
