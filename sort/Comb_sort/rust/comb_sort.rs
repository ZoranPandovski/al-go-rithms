fn comb_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
    let mut gap: usize = arr.len();
    let shrink: f64 = 1.3;
    let mut sorted: bool = false;
    let mut temp: &mut Vec<i32> = arr;
    while sorted == false { 
        gap = ((gap as f64 / shrink).floor()) as usize;
        if gap > 1{
            sorted = false;
        }
        else {
            gap = 1;
            sorted = true;
        }
        let mut i = 0;
        while i + gap < temp.len() {
            if temp[i] > temp[i + gap] {
                let swap = temp[i];
                temp[i] = temp[i + gap];
                temp[i + gap] = swap;
                sorted = false;
            }
            i = i + 1;
        }
    }
    return temp;
}

fn test() {
    let mut test: Vec<i32> = vec![22,84,67,1,90,15,88,23,69];
    let sorted_test = comb_sort(&mut test);
    for i in sorted_test {
        println!("{}",*i);
    }
}

fn main() {
    test();
}
