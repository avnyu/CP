#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    long long res = 0;

    vector<int> cnt(128, 0);
    for (auto& i : t) cnt[i]++;
    int i = 0, j = 0, n = s.size();
    while (i < n) {
        while (j < n && cnt[s[j]]) {
            cnt[s[j]]--;
            j++;
        }
        res += 1LL * (j - i);
        cnt[s[i]]++;
        i++;
    }

    cout << res << '\n';

    return 0;
}