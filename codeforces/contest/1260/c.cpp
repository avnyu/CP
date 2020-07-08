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

    int t;
    cin >> t;
    while (t--) {
        lli a, b, k;
        cin >> a >> b >> k;
        if (a > b) swap(a, b);

        lli g = __gcd(a, b);
        cout << (g + a * (k - 1LL) < b ? "REBEL\n" : "OBEY\n");
    }

    return 0;
}