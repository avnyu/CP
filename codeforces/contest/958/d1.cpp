#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define SPD                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

int main() {
    SPD;
    int n;
    cin >> n;
    double a, b, c, rs[n + 1];
    map<double, int> maps;
    char tmp;
    rep(i, 0, n) {
        cin >> tmp >> a >> tmp >> b >> tmp >> tmp >> c;
        rs[i] = (a + b) / c;
        maps[rs[i]]++;
    }
    rep(i, 0, n) rs[i] = maps[rs[i]], cout << rs[i] << ' ';
    return 0;
}
