#include <bits/stdc++.h>
using namespace std;

vector< vector<bool> > dp;
string s;

void preprocess() {
	int n = s.size();

	//single letter is always a pallindrome
	for(int i = 0; i < n; ++i) 
		dp[i][i] = true;

	//if adjacent letters are same then they are pallindrome
	for(int i = 0; i < n - 1; ++i)
		if(s[i] == s[i + 1])
			dp[i][i + 1] = true;

	//if s[i] == s[j] and between i + 1 and j - 1 is pallindrome
	//then from i to j is also a pallindrome
	for(int gap = 2; gap < n; ++gap) {
		for(int i = 0; i + gap < n; ++i) {
			int j = gap + i;
			if(s[i] == s[j] and dp[i + 1][j - 1])
				dp[i][j] = true;
		}
	}
}

bool is_pallindrome(int l, int r) {
	return dp[l][r];
}

int main() {
	std :: ios_base :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s;
	dp.assign(s.size(), vector<bool>(s.size(), false));

	preprocess();

	int l, r;
	cin >> l >> r;
	l--, r--;

	if(is_pallindrome(l, r)) 
		cout << "Substring is a pallindrome" << endl;
	else
		cout << "Substring is not a pallindrome" << endl;
}