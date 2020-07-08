#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int m = (n - 1) * n / 2;

    set<tuple<int, int, int>> s;
    vector<int> deg(n + 1, n - 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        s.insert({u, v, w});
        s.insert({v, u, w});
    }

    int res = 0;

    return 0;
}