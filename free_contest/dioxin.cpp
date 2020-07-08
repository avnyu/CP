#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
 
int n, m, q;
 
vector<vector<int>>arr_U, arr_D, arr_L, arr_R;
 
int get(vector<vector<int>>&a, int px, int py) {
    int s = 0;
    py += 1;
    while (py) {
        s += a[px][py];
        py -= py & (-py);
    }
    return s;
}
void upd(vector<vector<int>>&a, int px, int py, int val) {
    py += 1;
    int mx = int(a[0].size());
    while (py < mx) {
        a[px][py] += val;
        py += py & (-py);
    }
}
 
int find(vector<vector<int>>&a, int px, int py) {
    int l = py + 1, r = int(a[0].size()) - 1, ans = -1;
    int cnt = get(a, px - 1, py - 1);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(a, px - 1, mid - 1) > cnt) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    arr_L.resize(n, vector<int>(m + 1));
    arr_R.resize(n, vector<int>(m + 1));
    arr_U.resize(m, vector<int>(n + 1));
    arr_D.resize(m, vector<int>(n + 1));
    vector<vector<bool>>done(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            upd(arr_L, i, m - 1 - j, 1);
            upd(arr_R, i, j, 1);
            upd(arr_U, j, n - 1 - i, 1);
            upd(arr_D, j, i, 1);
        }
    }
    for (int i = 0; i < q; ++i) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'c') {
            if (done[x - 1][y - 1])continue;
            upd(arr_L, x - 1, m - y, -1);
            upd(arr_R, x - 1, y - 1, -1);
            upd(arr_U, y - 1, n - x, -1);
            upd(arr_D, y - 1, x - 1, -1);
            done[x - 1][y - 1] = 1;
        }
        else if (c == 'u') {
            int ans = find(arr_U, y, n + 1 - x);
            if (ans == -1)cout << "-1\n";
            else cout << n + 1 - ans << ' ' << y << endl;
        }
        else if (c == 'd') {
            int ans = find(arr_D, y, x);
            if (ans == -1)cout << "-1\n";
            else cout << ans << ' ' << y << endl;
        }
        else if (c == 'l') {
            int ans = find(arr_L, x, m - y + 1);
            if (ans == -1)cout << "-1\n";
            else cout << x << ' ' << m + 1 - ans << endl;
        }
        else {
            int ans = find(arr_R, x, y);
            if (ans == -1)cout << "-1\n";
            else cout << x << ' ' << ans << endl;
        }
    }
    return 0;
}
