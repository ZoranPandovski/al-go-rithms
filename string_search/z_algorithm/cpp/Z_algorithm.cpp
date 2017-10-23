/*
Created by Daniel Caceres
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Time Complexity
 * O( n ) where n = |text|
 * Description
 * For each i, z[ i ] is equal to the longest substring starting at i that is prefix of the text.
 */
vector<int> z_algorithm( string str ) {
    int len = int( str.size() );
    vector<int> z( len );
    z[ 0 ] = 0;
    for( int i = 1, l = 0, r = 0; i < len; ++i ) {
        if( i <= r )
            z[ i ] = min( r-i+1, z[ i-l ] );

        while( i+z[ i ] < len && str[ z[i] ] == str[ i+z[i] ] )
            z[ i ]++;

        if( i+z[ i ]-1 > r ) {
            l = i;
            r = i+z[ i ]-1;
        }
    }
    return z;
}

void match_text( string text, string pattern ) {
    string concat = pattern + '$' + text;
    vector<int> z = z_algorithm( concat );

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    for (int i = 0; i < int(concat.size()); ++i ) {
        // If z[i] (matched region) is equal to pattern length, we got the pattern
        if (z[i] == int(pattern.size()))
            cout << "Pattern found at index " <<  i - int(pattern.size()) -1 << endl;
    }
    cout << endl;
}

int main( ) {
    match_text( "Example of testing for Z algorithm", "test" );
    match_text( "Example of testing for Z algorithm", "not" );
    match_text( "AAAABBCBDDBABABAABCBBCDD", "AAB" );
    return 0;
}
