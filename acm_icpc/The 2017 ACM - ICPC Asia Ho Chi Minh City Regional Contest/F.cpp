#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define iii tuple<int, int, int>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int n, g, k;
    cin >> n >> g >> k;

    vector<int> a(n);
    vector<vector<ll>> a(n, vector<ll>(g));
    for (auto& i : a) cin >> i;

    return 0;
}