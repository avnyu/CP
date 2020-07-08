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
    int t;
    cin >> t;
    while (t--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);

        int x = min(a[0] + a[1], a[2]);

        if (x == a[2]) x += (a[0] + a[1] - x) / 2;
        cout << x << '\n';
    }
}