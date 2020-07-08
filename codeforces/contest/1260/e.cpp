#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> ii;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    priority_queue<int> q;
    int pnt = n - 1, sub = n;

    ll res = 0;
    while (1) {
        if (a[pnt] == -1) {
            cout << -res << "\n";
            return 0;
        }
        q.push(-a[pnt--]);
        res += q.top();
        q.pop();

        for (; pnt >= sub / 2; --pnt) {
            if (a[pnt] == -1) {
                cout << -res << '\n';
                return 0;
            }
            q.push(-a[pnt]);
        }

        sub >>= 1;
    }

    return 0;
}