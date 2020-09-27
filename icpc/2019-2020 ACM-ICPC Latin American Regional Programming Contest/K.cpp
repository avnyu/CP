#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    lli n = s.size();
    vector<lli> b;
    for (lli i = 1; i < n; ++i)
        if (s[i] != s[i - 1]) b.push_back(-2 * i - 1);

    n = b.size();
    vector<vector<lli>> res(2, vector<lli>(n + 2, 0));

    lli p = 0;
    res[p][0] = (s.back() == 'H' ? 1 : -1);

    for (lli i = 0; i < n; ++i) {
        p = 1 - p;
        
        for (lli j = 0; j < n + 2; ++j) res[p][j] = 0;

        for (lli j = 0; j < n + 1; ++j) {
            res[p][j] += res[1 - p][j];
            res[p][j + 1] += b[i] * res[1 - p][j];
        }
    }

    cout << n << '\n';
    for (lli i = 0; i < n + 1; ++i) cout << res[p][i] << ' ';
    cout << '\n';

    return 0;
}