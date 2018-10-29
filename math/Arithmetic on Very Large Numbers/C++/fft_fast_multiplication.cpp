/*
    This program uses Fast Fourier Transform to compute the product of 
    two big integers (as strings) in O(n log n) time.

    Sample input:
        265252859812191058636308480000000
        8841761993739701954543616000000
    Output:
        2345302654618196079156308226021870652534405390663680000000000000
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << ", "
#define REP(i, k) for(int i = 0; i < (k); ++i)
#define RREP(i, k) for(int i = (k)-1; i >= 0; --i)

typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned char byte;

template<typename T> using V = vector<T>;
template<typename T, typename U> using umap = unordered_map<T,U>;
template<typename T> using uset = unordered_set<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

using cd = complex<ld>;
using cld = complex<ld>;
const ld PI = M_PI;

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert = false) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n) {
        lg_n++;
    }

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n)) swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a) {
            x /= n;
        }
    }
}

void mult(V<cld>& a, V<cld>& b, V<int>& r) 
{
    int n = 1;
    while (n < a.size() + b.size()) {
        n *= 2;
    }

    a.resize(n);
    b.resize(n);
    r.assign(n, 0);

    fft(a);
    fft(b);
    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }  
    fft(a, true);

    int carry = 0;
    for (int i = 0; i < n; ++i) {
        r[i] += round(a[i].real()) + carry;
        carry = r[i] / 10;
        r[i] %= 10;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    string sa, sb;
    cin >> sa >> sb;
    V<cld> a(sa.size()), b(sb.size());
    for (int i = 0; i < a.size(); ++i) {
        ld v = sa[a.size()-1-i] - '0';
        a[i] = {v, 0};
    }
    for (int i = 0; i < b.size(); ++i) {
        ld v = sb[b.size()-1-i] - '0';
        b[i] = {v, 0};
    }
    V<int> r;
    mult(a, b, r);
    bool started = false;
    for (int i = 0; i < r.size(); ++i) {
        int d = r[r.size()-1-i];
        if (started) {
            cout << d;
        }
        else if (d != 0 or i == r.size()-1) {
            started = true;
            cout << d;
        }
    }
    cout << endl;
}

