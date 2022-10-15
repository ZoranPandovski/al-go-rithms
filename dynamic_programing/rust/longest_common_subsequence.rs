fn longest_common_subsequence(text1: String, text2: String) -> i32 {
    let m = text1.len();
    let n = text2.len();

    let t1 = text1.as_bytes();
    let t2 = text2.as_bytes();

    // BottomUp Tabulation
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
                continue;
            }
            if t1[i - 1] == t2[j - 1] {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = std::cmp::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // for v in dp.iter() {
    //     for k in v.iter() {
    //         print!("{} ", k);
    //     }
    //     println!("");
    // }

 

    return dp[m][n];
}

fn main() {
    let text1 = String::from("aggtab");
    let text2 = String::from("gxtxayb");

    println!("{}", longest_common_subsequence(text1, text2));
}
