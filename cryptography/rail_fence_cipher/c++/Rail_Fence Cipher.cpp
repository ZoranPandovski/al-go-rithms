// C++ program for Rail Fence Cipher
#include <bits/stdc++.h>
using namespace std;
 
// Encryption----------------------
string encrypt(string object, int key)
{
    // create the matrix to plain text
    // key = rows , length(object) = columns
    char rail[key][(object.length())];
 
    // filling the rail matrix
    for (int i=0; i < key; i++)
        for (int j = 0; j < object.length(); j++)
            rail[i][j] = '\n';
 
    // to find the direction
    bool dir = false;
    int row = 0, col = 0;
 
    for (int i=0; i < object.length(); i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key-1)
            dir = !dir;
 
        // fill the corresponding alphabet
        rail[row][col++] = object[i];
 
        // find the next row using direction flag
        dir?row++ : row--;
    }
 
    //Construct the cipher using the rail matrix
    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < object.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
 
    return result;
}
 
// Decryption-------------------------------
string decrypt(string cipher, int key)
{
    // create the matrix to plain text
    // key = rows , length(cipher) = columns
    char rail[key][cipher.length()];
 
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';
 
    // to find the direction
    bool dir;
 
    int row = 0, col = 0;
 
    // mark the places with '*'
    for (int i=0; i < cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir = true;
        if (row == key-1)
            dir = false;
 
        // place the marker
        rail[row][col++] = '*';
 
        // find the next row using direction flag
        dir?row++ : row--;
    }
 
    //Construct the fill the rail matrix
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];
 
 
    // now read the matrix in zig-zag manner 
    string result;
 
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir = true;
        if (row == key-1)
            dir = false;
 
        // place the marker
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
 
        // find the next row using direction flag
        dir?row++: row--;
    }
    return result;
}
 
//driver program(main function)
int main()
{
   cout << encrypt("Rail fence", 3) << endl;
    cout << encrypt("Cryptography", 3) << endl;
    cout << encrypt("Github", 3) << endl;
    cout<<"DEcrypted Code"<<endl;
    cout << decrypt("R calfneie",3) << endl;
    cout << decrypt("Ctarporpyygh",3) << endl;
    cout << decrypt("Guihbt",3) << endl;
 
    return 0;
}
