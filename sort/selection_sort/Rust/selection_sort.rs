fn selection_sort(mut arr :Vec<i32>) -> Vec<i32> {
    let len = arr.len();
    
    for i in 0..len-1 {
        let mut min = i;
        for j in i+1..len {
            if arr[j] < arr[min] {
                min  = j;
            }
        }
        if min != i{
            arr.swap(i, min);
        }
    }

    arr
}

fn main() {
    let arr = vec![38,58,13, 15,21,27,10,19,12,86,49,67,84,60,25];
    println!("Sorted array: {:?}", selection_sort(arr));
}