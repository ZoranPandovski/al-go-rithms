#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1000000;//maximum nodes in the trie (the sum of lengths of our dictiory words is a common upperbound)
const int ALPHABET_SIZE = 26;//Implementation works for english lowercase letters

int cntNodes = 1;//the root counts as one node (the node 1). The node 0 is left as null reference
int nodes[ MAX_NODES ][ ALPHABET_SIZE ];
int fail[ MAX_NODES ];
vector< vector< int > > matches( MAX_NODES );//matches[i] contains the indexes of patterns matched when reach the i node.
string t, p;//string t is the text when the patterns are going to be search
int k;//number of patterns
vector<string> patterns;

void insert( int node, int idx, string pat ){
	int cur = node;
	char next;
	for( int i = 0; i < pat.size(); i++ ){
		next = pat[i] - 'a';
		if( !nodes[cur][next] ) nodes[cur][next] = ++cntNodes;
		cur = nodes[cur][next];
	}
	matches[ cur ].push_back( idx );
}

//Read k patterns and inserts each of them in a Trie
void buildTrie(){
	for( int i = 0; i < k; i++ ){
		cin >> p;
		patterns.push_back( p );
		insert( 1, i, p );
	}
}

int move( int curNode, int next ){
	while( !nodes[curNode][next] )
		curNode = fail[ curNode ];
	return nodes[curNode][next];
}

//Do a BFS to build the fail function for the Trie nodes
void buildAho(){
	queue<int> q;
	for( int i = 0; i < ALPHABET_SIZE; i++ ){
		if( !nodes[1][i] )
			nodes[1][i] = 1;//sentinel
		else{
			fail[ nodes[1][i] ] = 1;
			q.push( nodes[1][i] );
		}
	}

	while( !q.empty() ){
		int curNode = q.front(); q.pop();
		int failCh;
		for( int i = 0; i < ALPHABET_SIZE; i++ ){
			if( !nodes[curNode][i] ) continue;
			failCh = fail[ nodes[curNode][i] ] = move( fail[ curNode ], i );
			if( matches[ failCh ].size() ){
				matches[ nodes[curNode][i] ].insert( matches[ nodes[curNode][i] ].end(), matches[ failCh ].begin(), matches[ failCh ].end() );
			}
			q.push( nodes[curNode][i] );
		}
	}
}

//Search for patterns matching in string t
void match( ){
	int curNode = 1;
	for( int i = 0; i < t.size(); i++ ){
		curNode = move( curNode, t[i] - 'a' );
		for( int j = 0; j < matches[curNode].size(); j++ ){
			cout << "Pattern " << patterns[ matches[curNode][j] ];
			cout << " find in range [" << (i - patterns[ matches[curNode][j] ].size() + 1 ) << "-" << i << "]\n";
		}
	}
}

int main(){

	cin >> k;//read number of patterns
	buildTrie();//read k patterns and buildTrie with them
	buildAho();//build fail function for trie nodes
	cin >> t;//read text to search for patterns matching
	match();//search and print matches

}
