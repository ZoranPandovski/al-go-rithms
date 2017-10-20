#include <bits/stdc++.h>

using namespace std;

int get_int_value( char c ){
    return toupper(c) - 65;
}

char get_char_value( int c ){
    return char(c + 65);
}

string extend_key( int size, string &key ){
    string new_key = key;
    while( new_key.size() < size ){
        new_key += key;
    }
    return new_key;
}

string encrypt( string &plain_text, string key ){
    string cipher_text = "";
    int p, k;
    key = extend_key(plain_text.size(), key);

    for( int i = 0; i < plain_text.size(); ++i ){
        p = get_int_value(plain_text[i]);
        k = get_int_value(key[i]);
        cipher_text += get_char_value((p + k) % 26);
    }
    return cipher_text;
}

string decrypt(string &cipher_text, string key ){
    string plain_text = "";
    int p, k;
    key = extend_key(cipher_text.size(), key);

    for( int i = 0; i < cipher_text.size(); ++i ){
        p = get_int_value(cipher_text[i]);
        k = get_int_value(key[i]);
        plain_text += get_char_value((p - k + 26) % 26);
    }
    return plain_text;
}

void test(){
    string action, text, result, key;
    text = "HACKTOBERFEST";
    key = "CRYPTO";
    result = encrypt( text, key );

    cout << "\n-------------------------------------\n";
    cout << "- Test\n";
    cout << "- Plain text: " << text <<'\n';
    cout << "- Key: " << key <<'\n';
    cout << "- Cipher text: " << result <<'\n';
    cout << "- Cipher text must be: JRAZMCDVPUXGV\n- \n";

    text = "JRAZMCDVPUXGV";
    result = decrypt( text, key );

    cout << "- Cipher text: " << text <<'\n';
    cout << "- Key: " << key <<'\n';
    cout << "- Plain text: " << result <<'\n';
    cout << "- Plain text must be: HACKTOBERFEST\n";
    cout << "-------------------------------------\n";
}

void instructions(){
    cout << "----------------------------------------\n";
    cout << "- This program implements vigenere cipher.\n";
    cout << "- It has two funcionalities.\n";
    cout << "- Encrypt: --encrypt plain_text key\n";
    cout << "- Decrypt: --decrypt cipher_text key\n";
    cout << "- All arguments are strings.\n";
    cout << "- Example:\n";
    cout << "- ./vigenere.out -encrypt hello bye\n";
    cout << "----------------------------------------\n";
}

int main( int argc, char* argv[] ){
    if( argc != 4 ){
        instructions();
        return 0;
    }

    string action, text, result, key;

    action = argv[1];
    text = argv[2];
    key = argv[3];

    if(action == "encrypt"){
        cout << encrypt(text, key) << '\n';
    }
    else{
        cout << decrypt(text, key) << '\n';
    }

    // Uncomment to run a test
    // test();
}
