#include <bits/stdc++.h>
using namespace std;

int n, k, len_res = 0;
string s;
vector<pair<int, int>> res(3e3);

void rev(int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

int fid(int l, char c) {
    while (l < n && s[l] != c) l++;
    return l;
}

void solve() {
    len_res = 0;
    cin >> n >> k >> s;

    k = n / 2 - k;
    int cnt = n / 2, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum <= k) {
            int r = fid(i, '(');
            rev(i, r);
            res[len_res++] = {i, r};
            sum++;
        } else {
            int r = fid(i, ')');
            rev(i, r);
            res[len_res++] = {i, r};
            sum--;
            k = 0;
        }
    }

    cout << len_res << '\n';
    for (int i = 0; i < len_res; ++i)
        cout << res[i].first + 1 << ' ' << res[i].second + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}