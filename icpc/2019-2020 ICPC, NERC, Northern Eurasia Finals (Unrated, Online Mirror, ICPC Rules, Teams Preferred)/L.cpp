#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, l, k;
    cin >> n >> l >> k;

    vector<string> res(n, string(l, 0));
    string s;
    cin >> s;

    priority_queue<char> save;
    for (auto& i : s) save.push(128 - i);

    int beg = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = beg; j < k; ++j) {
            res[j][i] = 128 - save.top();
            save.pop();
        }
        for (int j = k - 2; j >= beg; --j)
            if (res[j][i] != res[k - 1][i]) {
                beg = j + 1;
                break;
            }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < l; ++j)
            if (res[i][j] == 0) {
                res[i][j] = 128 - save.top();
                save.pop();
            }

    for (int i = 0; i < n; ++i) cout << res[i] << "\n";

    return 0;
}