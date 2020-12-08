#include <bits/stdc++.h>

using namespace std;

typedef array<int, 26> ai;

map<ai, bool> dp;
ai b;

bool nim_ok(ai &a) {
    for (auto &i: a) if (i > 3) return false;
    return true;
}
int nim(ai &a) {
    int res = 0;
    for (auto &i: a) res ^= i;
    return res;
}
int dfs(ai a) {
    if (dp.find(a) != dp.end()) return dp[a];

    if (nim_ok(a)) return dp[a] = nim(a);

    for (int i = 0; i < 26; ++i) {
        if (a[i] <= 3) continue;
        if (a[i] >= 1) {
            b = a;
            b[i] -= 1;
            if (dfs(b) == 0) return dp[a] = 1;
        }
        if (a[i] >= 2) {
            b = a;
            b[i] -= 2;
            if (dfs(b) == 0) return dp[a] = 1;
        }
        if (a[i] >= 3) {
            b = a;
            b[i] = 0;
            if (dfs(b) == 0) return dp[a] = 1;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (a[i] >= 1) {
            b = a;
            b[i] -= 1;
            if (dfs(b) == 0) return dp[a] = 1;
        }
        if (a[i] >= 2) {
            b = a;
            b[i] -= 2;
            if (dfs(b) == 0) return dp[a] = 1;
        }
        if (a[i] >= 3) {
            b = a;
            b[i] = 0;
            if (dfs(b) == 0) return dp[a] = 1;
        }
    }

    return dp[a] = 0;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    ai a, zero;

    a.fill(0);
    for (auto &c : s) a[c - 65]++;

    zero.fill(0);
    dp[zero] = 0;

    cout << (dfs(a) == 1 ? "Alice" : "Bob") << '\n';
    
    /*
    for (auto &[u, v]: dp) {
        // if (v) continue;
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            cout << u[i] << " ";
            res ^= u[i] % 3;
        }
        cout << "- " << v << " " << res << '\n';
    }
    */

    return 0;
}
