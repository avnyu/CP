#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        cout << min(n - 2, a[n - 2] - 1) << endl;
    }

    return 0;
}