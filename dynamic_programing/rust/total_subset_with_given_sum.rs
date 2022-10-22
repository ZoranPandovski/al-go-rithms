// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
fn f(i : usize, target : i32, nums: &Vec<i32>, dp : &mut Vec<Vec<i32>>) -> i32{

    if target == 0 {
        return 1;
    }

    if target < 0 {
        return 0;
    }

    if i == 0 {
        if nums[0] == target {
            return 1;
        }
        return 0;
    }

    return f(i -1, target - nums[i], nums, dp) + f(i-1, target, nums, dp);

}

fn num_subseq(nums: Vec<i32>, target: i32) -> i32 {

    let mut dp : Vec<Vec<i32>> = vec![ vec![-1 ; target as usize +1] ; nums.len()+1];
       
    f(nums.len() -1, target, &nums, &mut dp)
}

fn main(){

    let target = 6;
    let nums = vec![1,2,3,3];

    println!("{}", num_subseq(nums, target));


}
