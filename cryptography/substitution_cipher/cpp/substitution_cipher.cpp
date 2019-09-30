#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map <char, char> subs_table_enc;
map <char, char> subs_table_dec;
map <char, string> options;

void help () {
    cout << "Instructions:" << endl;
    cout << "This is an implementation of substitution cipher that at the end gives you a file called <my_file>_encrypted.txt or <my_file>_decryted.txt" << endl;
    cout << endl;
    cout << "The program has 3 options:" << endl;
    cout << "--encrypt, -e: encrypt a file passed as an argument" << endl;
    cout << "--decript, -d: decrypt a file passed as an argument" << endl;
    cout << "--subs_table, -s: use a substitution table passed as an argument" << endl;
    cout << endl;
    cout << "Example:" << endl;
    cout << "./substitution_cipher -e my_file_decrypted.txt -s my_table.txt" << endl;
    cout << "./substitution_cipher -d my_file_encrypted.txt -s my_table.txt" << endl; 
}

int load_options (int argc, char* argv[]) {
    for (int i = 1; i < argc; i += 2) {
        string option = argv[i];
        if (i + 1 >= argc) {
            return -1;
        }
        if (option == "-e" || option == "encrypt") {
            options['e'] = argv[i + 1];
        }
        else if (option == "-d" || option == "decrypt") {
            options['d'] = argv[i + 1];
        }
        else if (option == "-s" || option == "subs_table") {
            options['s'] = argv[i + 1];
        }
        else {            
            return -1;
        }
    }
    return 0;
}

int load_table () {
    ifstream table_file (options['s']);

    if (!table_file.is_open ()) {
        return -1;
    }
    
    string line1;
    string line2;
    
    getline (table_file, line1);
    getline (table_file, line2);
    
    if (line1.size() != line2.size()) {
        return -1;
    }
    
    for (int i = 0; i < line1.size(); ++i) {
        subs_table_enc[line1[i]] = line2[i];
        subs_table_dec[line2[i]] = line1[i];
    }
    
    table_file.close ();
    return 0;
}

string remove_ext (const string &file_name) {
    int pos = file_name.size () - 1;
    for (; pos >= 0; --pos) {
        if (file_name[pos] == '.') {
            break;
        }
    }
    return file_name.substr (0, pos);
}

int base_function (const string &file_name, map<char, char> &subs, const string &cypher_name) {
    ifstream file (file_name);
    if (!file.is_open()) {
        return -1;
    }
    ofstream o_file;
    o_file.open (remove_ext (file_name) + "_" + cypher_name);
    string line;
    string nline;
    while (getline (file, line)) {
        nline = "";
        for (char c : line) {
            if (!subs.count(c)) {
                nline += c;
                continue;
            }
            nline += subs[c];
        }
        o_file << nline << endl;
    }
    o_file.close ();
    return 0;
}

int encrypt (const string &file_name) {
    return base_function (file_name, subs_table_enc, "encrypted.txt");
}

int decrypt (const string &file_name) {
    return base_function (file_name, subs_table_dec, "decrypted.txt");
}

int main (int argc, char* argv[]) {
    
    if (argc != 5) {
        help ();
        return 0;
    }
    
    if (load_options (argc, argv) == -1) {
        cout << "The command is not valid" << endl;
        help ();
        return 0;
    }
    
    if (load_table() == -1) {
        cout << "Table file not found" << endl;
        help ();
        return 0;
    }
    
    if (options.count ('e')) {
        if (encrypt (options['e']) == -1) {
            cout << "Error encrypting the file" << endl;
            help ();
        }
    }
    else if (options.count ('d')) {
        if (decrypt (options['d']) == -1) {
            cout << "Error decrypting the file" << endl;
            help ();
        }
    }
    else {
        cout << "The command is not valid" << endl;
        help ();
    }
    
    return 0;
}
