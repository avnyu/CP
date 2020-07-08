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

    int n = 3;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int m = a[0].size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '=') {
                for (int k = j + 1; k < m; ++k) {
                    if (a[i][k] != '.') {
                        cout << a[i][k] << '\n';
                        return 0;
                    }
                }
                cout << "You shall pass!!!\n";
                return 0;
            }
        }
    cout << "You shall pass!!!\n";

    return 0;
}