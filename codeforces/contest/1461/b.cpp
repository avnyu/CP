#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>>a(n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];
    
    vector<vector<int>>cal(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= max(n, m); ++i)
        for (int x = 1; x <= n; ++x)
            for (int y = 1; y <= m; ++y) {
                if (i == 1) cal[x][y] = a[x][y] == '*';
                else if (cal[x][y] >= i - 1 && cal[x - 1][y] >= i - 1 && cal[x][y - 1] >= i - 1 && cal[x][y + 1] >= i - 1) cal[x][y] = max(cal[x][y], i);
            }
    
    long long res = 0;
    for(auto&i:cal)for(auto&j:i)res+=j;
    cout << res << '\n';
}
int main() {
    ios:: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    for (; t--;) solve();
    
    return 0;
}
