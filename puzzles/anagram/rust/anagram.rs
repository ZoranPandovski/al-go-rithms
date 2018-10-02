fn is_anagram(a: &str ,b : &str) ->  bool {
    if a.len() != b.len() { // initial check
        return false;
    }
    let mut a:Vec<char> = a.chars().collect();
    a.sort();
    let mut b:Vec<char> = b.chars().collect();
    b.sort();
    if a == b {
        return true
    }
    false
}
