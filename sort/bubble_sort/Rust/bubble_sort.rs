fn bubble_sort(mut arr :Vec<i32>) -> Vec<i32> {
    for _ in 0..arr.len() {
        let mut flag = false;
        for j in 0..arr.len() - 1 {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j+1);
                flag = true
            }
        }
        if !flag {
            break;
        }
    }
    arr
}

fn main() {
    let arr = vec![2, 1, 2,7,88,4,3,6];
    println!("Sorted array: {:?}", bubble_sort(arr));
}