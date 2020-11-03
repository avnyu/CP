#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> res(368, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        for (int j = s; j <= t; ++j) res[j] = 1;
    }
    partial_sum(res.begin(), res.end(), res.begin());
    cout << res.back() << '\n';

    return 0;
}