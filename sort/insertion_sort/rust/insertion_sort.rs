fn insertion_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
    let mut temp: &mut Vec<i32> = arr;
    for i in 0..temp.len(){
        let mut j = i;
        let mut swap;
        while (j > 0) && (temp[j - 1] > temp[j]){
            swap = temp[j];
            temp[j] = temp[j - 1];
            temp[j - 1] = swap;
            j = j - 1;
        }
    }
    return temp;
}

fn test() {
    let mut test: Vec<i32> = vec![22,84,67,1,90,15,88,23,69];
    let sorted_test = insertion_sort(&mut test);
    for i in sorted_test {
        println!("{}",*i);
    }
}

fn main() {
    test();
}
