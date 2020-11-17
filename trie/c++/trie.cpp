#include<iostream>
#include<cstring>
using namespace std;


/* 
A Trie is a special form of a Nary tree. Typically, a trie is used to store strings. 
Each Trie node represents a string (a prefix). Each node might have several children 
nodes while the paths to different children nodes represent different characters. And 
the strings the child nodes represent will be the origin string represented by the node 
itself plus the character on the path.

It is worth noting that the root node is associated with the empty string.

One important property of Trie is that all the descendants of a node have a common 
prefix of the string associated with that node. That's why Trie is also called prefix tree.

Trie is widely used in various applications, such as autocomplete, spell checker, etc.


*/


// This is basic trienode in trie
struct trie{
    // It will have 26 children for each lowercase alphabet 
    struct trie* children[26];
    // Is end is to determine whether it is end of string

    // For example you insert "abc" in the trie if isend is not present then searching will also give true for "ab" 
    // as it is present in trie which is not true
    bool isend;

    // This is just to set default value of every node
    trie() {
        memset(children, 0, sizeof(children));
        isend = false;
    }
};

struct trie* root;

// To insert word in the str
void insert(string str) {
    struct trie* curr = root;
    for(char ch: str) {
        int i = ch - 'a';
        // If the children is null initialize it
        if(curr->children[i] == NULL) {
            curr->children[i] = new trie;
        }
        curr = curr->children[i];
    }
    // This is very imp to tell the word has ended
    curr->isend = true;
}

// Search the word in trie
bool search(string str) {
    struct trie* curr = root;
    for(char ch: str) {
        int i = ch - 'a';
        if(curr->children[i] == NULL) {
            return false;
        }
        curr = curr->children[i];
    }
    // This is most important condition
    return curr->isend;
}

int main() {
    root = new trie;
    int n;
    string str;
    cin >> n;
    while(n--) {
        cin >> str;
        insert(str);
    }
    cin >> n;
    while(n--) {
        cin >> str;
        search(str) ? cout << str << " is present\n" : cout << str << " is not present\n";
    }
    return false;
    
}