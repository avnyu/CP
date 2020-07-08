#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define dd pair<double, double>
#define fi first
#define se second
#define vd vector<double>
#define vi vector<int>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < int(1e5); ++i) {
        int t = i + ceil(double(d) / (i + 1));
        if (t <= n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}