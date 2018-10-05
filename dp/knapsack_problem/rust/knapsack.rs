// n = number of items we have left to consider
// c = capacity we have left
fn knapsack(memo: &mut Vec<Vec<Option<usize>>>,
            w: &Vec<usize>,
            v: &Vec<usize>,
            n: usize,
            c: usize) -> usize {
    if let Some(r) = memo[n][c] {
        return r;
    }

    let result;

    if n == 0 || c == 0 {
        result = 0;
    } else if w[n] > c {
        result = knapsack(memo, w, v, n-1, c);
    } else {
        let tmp1 = knapsack(memo, w, v, n-1, c);
        let tmp2 = v[n] + knapsack(memo, w, v, n-1, c - w[n]);
        result = if tmp1 > tmp2 { tmp1 } else { tmp2 };
    }

    memo[n][c] = Some(result);
    result
}

fn main() {
    let weights = vec![1, 2, 4, 2, 5];
    let values = vec![5, 3, 5, 3, 2];

    let n = weights.len() - 1;

    let capacity: usize = 10;

    let mut memo = vec![vec![None; capacity + 1]; n + 1];

    println!("Optimal value: {}", knapsack(&mut memo,
                                           &weights,
                                           &values,
                                           n, 
                                           capacity));
}
