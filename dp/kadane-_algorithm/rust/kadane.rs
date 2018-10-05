fn kadane(v: &Vec<i32>) -> i32{
    let mut max_global = v[0];
    let mut max_current = max_global;

    for i in 1..(v.len()-1) {
        max_current = if v[i] > max_current + v[i] {
            v[i]
        } else {
            max_current + v[i]
        };

        if max_current > max_global {
            max_global = max_current;
        }
    }

    return max_global;
}

fn main() {
    let v: Vec<i32> = vec![-2, 3, 2, -1];

    println!("Maximum subarray sum: {}", kadane(&v));
}
