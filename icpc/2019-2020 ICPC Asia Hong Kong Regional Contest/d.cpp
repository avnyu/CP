#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e10;

void solve() {
    int bas;
    cin >> bas;
    vector<long long> p;
    p.push_back(1);
    while (p.back() < INF) {
        p.push_back(p.back() * bas);
    }
    long long n;
    cin >> n;
    int digits = 1;
    while (n > p[digits]) {
        n -= p[digits++];
    }
    string ans;
    for (int i = 1; i <= digits; ++i) {
        int pos = -1;
        for (int num = 0; num < bas; ++num) {
            if (n > 1LL * num * p[digits - i]) {
                pos = num;
            }
        }
        ans.push_back((char)('0' + 10 - bas + pos));
        n -= 1LL * pos * p[digits - i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}