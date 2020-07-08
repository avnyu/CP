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
        int c, sum;
        cin >> c >> sum;

        vector<int> a(c);
        for (int i = 0; i < c; ++i) a[i] += sum / c;
        for (int i = 0; i < sum % c; ++i) a[i]++;
        for (int i = 0; i < c; ++i) a[i] *= a[i];
        partial_sum(a.begin(), a.end(), a.begin());
        cout << a.back() << '\n';
    }

    return 0;
}