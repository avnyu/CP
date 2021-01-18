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

bool chk(ll &a, ll &b) {
    if (a == 0 || b == 0) return 1;
    if (a < 2 * b && b < 2 * a) return 1;
    return 0;
}
void make(ll &a, ll &b) {
    if (a < b) {
        ll i = 4;
        while (a * i <= b) i *= 2;
        b -= a * i / 2;
    } else {
        ll i = 4;
        while (b * i <= a) i *= 2;
        a -= b * i / 2;
    }
    return;
}
int main() {
    ll a, b;
    cin >> a >> b;
    while (!chk(a, b)) make(a, b);
    cout << a << ' ' << b;
    return 0;
}
