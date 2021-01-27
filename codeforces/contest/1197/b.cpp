#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    int p = 0, l, r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == n) p = i;
    }
    l = p - 1, r = p + 1;
    while (1) {
        if (l >= 0 && a[l] == a[p] - 1) {
            p = l;
            l--;
            continue;
        }
        if (r < n && a[r] == a[p] - 1) {
            p = r;
            r++;
            continue;
        }
        break;
    }
    cout << (a[p] == 1 ? "YES" : "NO");

    return 0;
}