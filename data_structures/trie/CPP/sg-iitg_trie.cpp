// the code implements trie data structure
// this data structure helps in reducing search complexities in strings to length of string and hence in highly efficient retrieval data structure
// each branch of trie represents one of the 26 characters

//space complexity: O(26*key_length*n)
// key_length = maximum length of key
// n = number of keys in trie

#include <bits/stdc++.h>
using namespace std;

// each trie node contains 26 children corresponding to 26 characters of english alphabet
// each node also contains a boolean variable named enofword, to indicate if any words ends at this node

class TrieNode{
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode()
    {
        // this is a pointer to the current object
        // initially all childrens are NULL and endofword is false
        this->isEndOfWord = false;
        for(int i=0;i<26;i++)
        {
            this->children[i] = NULL;
        }
    }
};

// to insert a new string into trie
// time complexity: O(key_length)
void insert(string key, TrieNode* root)
{
    int n= key.size();
    TrieNode* itr= root;

    // iterate over the given string
    for(int i=0;i<n;i++)
    {
        int idx= key[i]-'a';
        // if idx is not present as child of the current node, add new
         if(itr->children[idx]==NULL)
         {
            itr->children[idx] = new TrieNode();
         }
         // else jump to it
        itr = itr->children[idx];
    }
    // set the endofword now
    itr->isEndOfWord = true;
}

// this returns whether the given string is present in the trie or not
// time complexity: O(key_length)
bool search(string key, TrieNode* root)
{
    int n= key.size();
    TrieNode* itr= root;
    for(int i=0;i<n;i++)
    {
        int idx= key[i]-'a';
        // if idx is not present as child of itr, this means this string is not in trie, and hence return false
         if(itr->children[idx]==NULL)
         {
            return false;
         }
        itr = itr->children[idx];
    }

    // if all characters of the string were found, and this is the end of word, only then return true
    // the below is done to handle such case: say "apple" is already in trie , we are searching for "app", app is present in trie,
    // but its not a word, since endofword is not true there and hence our function should return false
    if(itr!=NULL && itr->isEndOfWord)
    {
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    // get the set of strings available
    vector<string> arr(n);

    // initialise the trie
    TrieNode* root = new TrieNode();

    // build the trie by inserting all strings into it
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        insert(arr[i], root);
    }

    // example queries

    // check if strings a and b are present in the trie or not
    string a, b;
    cin>>a>>b;

    if(search(a, root))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    if(search(b, root))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}

/*
Test cases:
TC1: arr = ["apple", "ball", "cat", "android"]
     a = ball
     b = app

     output:
     True
     False
*/
