use std::char;

fn caesar(text: &str, shift: u32) -> String {
    text.to_lowercase()
        .chars()
        .map(|c| char::from_u32(((c as u32) + shift - 97) % 26 + 97).unwrap())
        .collect()
}

fn main() {
    assert_eq!("khoor", caesar(&String::from("hello"), 3));
}
