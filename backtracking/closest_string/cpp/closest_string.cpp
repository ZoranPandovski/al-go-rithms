#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int hamming_distance(const string &s1, const string &s2) {
	assert(s1.size() == s2.size());
	int d = 0;
	for (int i = 0; i < (int)s1.size(); ++i) {
		d += (s1[i] != s2[i]);
	}
	return d;
}

// current solution string s, input strings a, max number of changes left l, parameter m
string center(string s, vector<string> a, int l, int m) {
	if (l < 0) { // negative number of changes
		return "";
	}
	int k = a.size(), n = s.size();
	for (int i = 0; i < k; ++i) { 
		// look for a string with hamming_distance to s of at least m + 1
		if (hamming_distance(s, a[i]) > m) { 
			// try to change s in m + 1 positions where it differs to a[i]
			for (int j = 0, cnt = 0; j < n && cnt < m + 1; ++j) {
				if (s[j] != a[i][j]) {
					string nxt = s;
					nxt[j] = a[i][j];
					string res = center(nxt, a, l - 1, m);
					if (res != "") { // res is a solution
						return res;
					}
					++cnt;
				}
			}
			return "";
		}
	}
	// no string with hamming_distance > m found --> s is a solution
	return s;
}

// parameterized algorithm with runtime (m + 1)^m*n*k for closest string problem:
// given k strings a_1, ..., a_k of length n, integer m
// is there a string s with hamming_distance(s, a_i) <= m for all i?
// returns: one such string, or if none exists the empty string
// https://en.wikipedia.org/wiki/Closest_string
string closest_string(vector<string> a, int m) {
	assert(!a.empty());
	return center(a[0], a, m, m);
}


int main() {
	vector<string> a{"abc", "bbc", "bac"};
	cout << closest_string(a, 1) << endl; // bbc

	a = {"gctaggagtcagaagtaggcgttgcat", 
		 "gcaatgaatcagaactgggcctagcat",
		 "gctagggatcagaactaggcctagcat",
		 "gcaaggaatcataactaggcctagcat",
		 "gcaaggaattagaaataggcctagcat",
		 "gcaagaaatcagaactagccctagcat"};
	cout << closest_string(a, 4) << endl; // solution with m = 4 exists
	cout << closest_string(a, 3) << endl; // solution with m = 3 does not exist

	a = {"gctaggagtcagaataggcgttgcat", 
		 "gcaatgaatcagaatgggcctagcat",
		 "gctagggatcagaataggcctagcat",
		 "gcaaggaatcataataggcctagcat",
		 "gcaaggaattagaataggcctagcat",
		 "gcaagaaatcagaatagccctagcat"};
	cout << closest_string(a, 3) << endl; // solution with m = 3 exists
	cout << closest_string(a, 2) << endl; // solution with m = 2 does not exist
	return 0;
}