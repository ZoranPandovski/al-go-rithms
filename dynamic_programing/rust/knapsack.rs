// https://atcoder.jp/contests/dp/tasks/dp_d
// use proconio::input;
use std::cmp::max;

fn knapsack(i: usize, wl: usize, items: &Vec<(i64, i64)>, dp: &mut Vec<Vec<i64>>) -> i64 {
    // if wl <= 0 {
    //     return i64::MIN;
    // }

    if i == 0 {
        if wl as i64 >= items[0].0 {
            return items[0].1;
        }

        return 0;
    }

    if dp[i][wl] != -1 {
        return dp[i][wl];
    }

    if (wl as i64) < (items[i].0) {
        dp[i][wl] = knapsack(i - 1, wl, items, dp) + 0;
        return dp[i][wl];
    }

    dp[i][wl] = max(
        knapsack(i - 1, wl - items[i].0 as usize, items, dp) + items[i].1,
        knapsack(i - 1, wl, items, dp) + 0,
    );
    return dp[i][wl];
}

fn main() {
    // input! {
    //     n : usize,
    //     w : usize,
    //     items : [(i64, i64) ; n],
    // }
    let n = 6;
    let w = 15;
    let items = vec![(6,5), (5,6), (6,4), (6,6), (3,5), (7,2)];

    // TopDown Recursion
    let mut dp: Vec<Vec<i64>> = vec![vec![-1; w + 1]; n + 1];
    println!("TopDown Recursion: {}", knapsack(n - 1, w, &items, &mut dp));

    // BottomUp Tabulation
    let mut dp: Vec<Vec<i64>> = vec![vec![0; w + 1]; n + 1];
    for i in 0..n {
        for j in 0..(w + 1) {
            if i == 0 {
                if j as i64 >= items[0].0 {
                    dp[i][j] = items[0].1;
                    continue;
                }
                dp[i][j] = 0;
                continue;
            }
            if (j as i64) < (items[i].0) {
                dp[i][j] = dp[i - 1][j] + 0;
                continue;
            }
            dp[i][j] = max(
                dp[i - 1][j - items[i].0 as usize] + items[i].1,
                dp[i-1][j] + 0,
            );
        }
    }
    println!("BottomUp Tabulation: {}", dp[n - 1][w]);
}
