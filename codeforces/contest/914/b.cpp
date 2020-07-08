#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i > b; --i)
using namespace std;

void solve() {
    int n, a[100000];
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    map<int, int> number;
    int odd = 0;
    rep(i, 0, n) number[a[i]]++;
    for (map<int, int>::iterator it = number.begin(); it != number.end();
         it++) {
        odd += (it->second % 2 == 1);
    }
    if (odd == 0)
        cout << "Agasa";
    else
        cout << "Conan";
    return;
}
int main() {
    // int n;cin>>n;
    // while(n-->0)solve();
    solve();
    return 0;
}
