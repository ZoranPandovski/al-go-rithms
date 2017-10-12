fn binary_search(arr :Vec<i32>, n :i32) -> i32{
    let mut low = 0;
    let mut high = arr.len()-1;
   loop {
        let mid = (low + high) / 2;
        if n == arr[mid] {
            return mid as i32;
        }else if n > arr[mid] {
            low = mid + 1;
        }else {
            high = mid -1;
        }
        if low >= high {
            break;
        }
    }
    -1
}

fn main() {
    let arr = vec![0, 4, 5, 8, 12, 14, 20, 34, 55, 60, 84, 111, 134, 154, 188, 189, 200];
    let num = 8;
    let index = binary_search(arr, num);
    if index != -1 {
        println!("{} found at index {}",num,index);
    }else {
        println!("{} not found!", num);
    }
}