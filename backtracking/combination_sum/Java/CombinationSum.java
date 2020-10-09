public class CombinationSum {
    /*
    Problem Statement:

    Given an array of distinct integers candidates and a target integer target,
    return a list of all unique combinations of candidates where the chosen numbers sum to target.
    You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times.
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    Example 1:

    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation:
    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
    7 is a candidate, and 7 = 7.
    These are the only two combinations.
    Example 2:

    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]
    Example 3:

    Input: candidates = [2], target = 1
    Output: []
    Example 4:

    Input: candidates = [1], target = 1
    Output: [[1]]
    Example 5:

    Input: candidates = [1], target = 2
    Output: [[1,1]]


    Constraints:

    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    All elements of candidates are distinct.
    1 <= target <= 500

    */

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList();
        backtrack(candidates, 0, target, new ArrayList(), result);
        return result;
    }

    private void backtrack(int[] cand, int start, int target, List<Integer> list, List<List<Integer>> result) {
        if (target < 0)
            return;
        if (target == 0)
            result.add(new ArrayList(list));
        for (int i = start; i < cand.length; i++) {
            list.add(cand[i]);
            backtrack(cand, i, target - cand[i], list, result);
            list.remove(list.size() - 1);
        }
    }
}