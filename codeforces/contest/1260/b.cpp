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
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);

        if ((a + b) % 3 != 0)
            cout << "NO\n";
        else if (!a && b)
            cout << "NO\n";
        else if (a && !b)
            cout << "NO\n";
        else if (a + a < b)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}