fn encode_decode(text: &str) -> String {
    atbash(text).collect()
}

fn transcode_char(c: char) -> char {
    // Ignore digits and spaces otherwise shift the character
    // the required number of spaces
    if c.is_ascii_digit() || c.is_ascii_whitespace() {
        c
    } else {
        (b'z' + b'a' - c as u8) as char
    }
}

/// Filter out non-ascii characters and transcode the text
/// character by character
fn atbash<'a>(s: &'a str) -> impl Iterator<Item = char> + 'a {
    s.chars().filter_map(|c| {
        Some(c)
            .filter(|c| c.is_ascii_alphanumeric() || c.is_ascii_whitespace())
            .map(|c| transcode_char(c.to_ascii_lowercase()))
    })
}

fn main() {
    let plaintext = "The quick brown fox jumps over the lazy dog.";
    let ciphertext = "gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt";

    // It can encode plaintext
    assert_eq!(
        encode_decode(plaintext),
        "gsv jfrxp yildm ulc qfnkh levi gsv ozab wlt"
    );

    // It can decode ciphertext
    assert_eq!(
        encode_decode(ciphertext),
        "the quick brown fox jumps over the lazy dog"
    );
}
