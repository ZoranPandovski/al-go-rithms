fn merge(v: &mut Vec<i32>, start: usize, mid: usize, end: usize) {
    let mut com1 = start;
    let mut com2 = mid+1;
    let mut com_aux = 0;
    let mut v_aux = vec![0; end-start+1];
    while com1 <= mid && com2 <= end {
        if v[com1] < v[com2] {
            v_aux[com_aux] = v[com1];
            com1 += 1;
        } else {
            v_aux[com_aux] = v[com2];
            com2 += 1;
        }
        com_aux += 1;
    }
    while com1 <= mid {
        v_aux[com_aux] = v[com1];
        com1 += 1;
        com_aux += 1;
    }
    while com2 <= end {
        v_aux[com_aux] = v[com2];
        com2 += 1;
        com_aux += 1;
    }
    for i in start..(end+1) {
        v[i] = v_aux[i - start];
    }
}
fn merge_sort(v: &mut Vec<i32>, start: usize, end: usize) {
    if start < end {
        let mid = (start+end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}
fn main() {
    let mut v = vec![8, 4, 6, 3, 2, 6, 9];
    println!("{:?}", v);
    let end = v.len()-1;
    merge_sort(&mut v, 0, end);
    println!("{:?}", v);
}
