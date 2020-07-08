#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i > b; --i)
using namespace std;

int main() {
    int n, a[1000];
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    int rs = -10000000;
    rep(i, 0, n) {
        if ((a[i] > rs) && (a[i] < 0) ||
            ((a[i] > rs) && ((int)sqrt(a[i]) * (int)sqrt(a[i]) != a[i])))
            rs = a[i];
    }
    cout << rs;
    return 0;
}
