#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, N = 1e4 + 1;
    cin >> n;
    vector<vector<int>>a(N, vector<int>());

    for (int i = 0; i < n; ++i) {
        pair<int, int>x;
        cin >> x.first >> x.second;
        a[x.first].emplace_back(x.second);

        int ans = 0, cnt = 0;

        for (int i = 0; i < N; ++i)
            for (auto&j : a[i]) {
                cnt += j;
                ans = max(cnt - i, ans);
            }

        cout << max(ans, 0) << '\n';
    }

    return 0;
}