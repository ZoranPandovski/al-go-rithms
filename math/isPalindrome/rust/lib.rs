#[test]
fn test_valid_palindrome() {
    assert!(is_palindrome("racecar"));
}

#[test]
fn test_invalid_palindrome() {
    assert!(!is_palindrome("doggo"));
}

pub fn is_palindrome(x: &str) -> bool {
    x.chars().eq(x.chars().rev())
}
