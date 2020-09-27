#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 100;
int n, m;
vector<vector<int>> vote(N, vector<int>(100));
vector<vector<int>> res(N);

void cal(int p, int o) {
    int dif = 0;
    priority_queue<pair<int, int>> difs;

    for (int i = 0; i < m; ++i) {
        dif += vote[i][o] - vote[i][p];
        difs.push({vote[i][o] - vote[i][p], i});
    }

    while (dif > 0) {
        int rem_dif = difs.top().first, i = difs.top().second;
        difs.pop();

        dif -= rem_dif;
        res[p].push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) cin >> vote[i][j];

    for (int i = 0; i < n - 1; ++i) cal(i, n - 1);

    sort(res.begin(), res.begin() + n - 1,
         [&](vector<int> &a, vector<int> &b) { return a.size() < b.size(); });

    cout << res[0].size() << '\n';
    for (int i = 0; i < res[0].size(); ++i)
        cout << res[0][i] + 1 << " \n"[i == res.size() - 1];

    return 0;
}