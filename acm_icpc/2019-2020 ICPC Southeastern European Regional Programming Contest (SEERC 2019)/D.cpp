#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();

    if (n == 2) {
        if (s[0] == s[1]) cout << "NO\n";
        if (s[0] != s[1]) cout << "YES\n" << s << '\n';
        return 0;
    }

    int cnt[26] = {};
    for (auto& i : s) cnt[i - 97]++;

    for (auto& i : s)
        if (cnt[i - 97] > n / 2) i -= 32;

    sort(s.begin(), s.end());

    int p = upper_bound(s.begin(), s.end(), s[0]) - s.begin();

    if (p > n - 2) {
        cout << "NO\n";
        return 0;
    }

    if (n > 4 && p == n - 2 && s[n - 2] == s[n - 1]) {
        cout << "NO\n";
        return 0;
    }

    swap(s[n - 2], s[n / 2]);
    for (auto& i : s)
        if (i < 97) i += 32;
    cout << "YES\n";
    cout << s << '\n';

    return 0;
}