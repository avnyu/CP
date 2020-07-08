#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size(), M = 1e9 + 7;
    vector<vector<int64_t>>dp(2, vector<int64_t>(10, 1));
    set<int>seti;
    int p = 0, q = 1;
    for (int i = 0; i < n; i += 3) {
        p ^= 1, q ^= 1;
        int cnt = (s[i] - 48) * 100 + (s[i + 1] - 48) * 10 + s[i + 2] - 48;
        for (int k = 0; k < 10; ++k) {
            seti.clear();
            int tmp;
            if (s[i] - 48 == k) {
                tmp = (s[i + 1] - 48) * 10 + s[i + 2] - 48;
                seti.insert(tmp);
            }
            if (s[i + 1] - 48 == k) {
                tmp = (s[i] - 48) * 10 + s[i + 2] - 48;
                seti.insert(tmp);
            }
            if (s[i + 2] - 48 == k) {
                tmp = (s[i] - 48) * 10 + s[i + 1] - 48;
                seti.insert(tmp);
            }
            dp[q][k] = (dp[p][k] * int64_t(seti.size() + (cnt < 128))) % M;
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < 10; ++i)
        ans = (ans + dp[q][i]) % M;
    cout << ans;
    return 0;
}
