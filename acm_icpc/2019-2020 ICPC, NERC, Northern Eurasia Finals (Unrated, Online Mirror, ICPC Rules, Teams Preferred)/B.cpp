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

    string s;
    cin >> s;

    int n = s.size();
    int l = 0, r = n - 1;

    while (1) {
        if (s[l] != s[r]) {
            cout << "0\n";
            return 0;
        }
        
        int nl = l;
        int nr = r;

        while (nl < n && s[nl] == s[l]) nl++;
        while (nr >= 0 && s[nr] == s[r]) nr--;

        if (nl <= nr) {
            int cnt = nl - l + r - nr;
            if (cnt < 3) {
                cout << 0 << '\n';
                return 0;
            }
            l = nl, r = nr;
        } else {
            int cnt = r - l + 1;
            if (cnt < 2) {
                cout << "0\n";
                return 0;
            } else {
                cout << cnt + 1 << '\n';
                return 0;
            }
        }
    }

    return 0;
}