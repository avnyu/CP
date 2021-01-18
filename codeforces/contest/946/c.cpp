#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i > b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define m(i, j) map<i, j>
#define F first
#define S second
using namespace std;

int main() {
    string s;
    cin >> s;
    char c = 'a';
    rep(i, 0, s.length()) {
        if (c >= s[i]) s[i] = c++;
        if (c > 'z') break;
    }
    if (c > 'z')
        cout << s;
    else
        cout << -1;
    return 0;
}
