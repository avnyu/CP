#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e6 + 5;
const int mod = 1e9 + 7;

int n;
int a[maxN];
int strip, dif, len;
int miner[22][maxN];
int maxer[22][maxN];
int coef;
int pw2[maxN];
int l[maxN];
int dp[maxN];

int l11, r11;

bool calc(int left, int right) {
    // if(left == 0) return 0;
    int h = pw2[right - left + 1];
    int fakeMax = max(maxer[h][left], maxer[h][right - (1 << h) + 1]);
    int fakeMin = min(miner[h][left], miner[h][right - (1 << h) + 1]);
    return (fakeMax - fakeMin <= dif);
}

deque<int> q;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    strip = 0;
    cin >> n >> dif >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pw2[i] = log2(i);
    }

    coef = log2(n);
    for (int i = 0; i <= coef; i++) {
        for (int j = 1; j <= n + 1 - (1 << i); j++) {
            if (i == 0) {
                miner[0][j] = a[j];
                maxer[0][j] = a[j];
            } else {
                miner[i][j] =
                    min(miner[i - 1][j], miner[i - 1][j + (1 << (i - 1))]);
                maxer[i][j] =
                    max(maxer[i - 1][j], maxer[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    dp[0] = 0;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        l11 = 1;
        r11 = i;
        while (r11 != l11) {
            int mid = (r11 + l11) / 2;
            if (calc(mid, i) == 0)
                l11 = mid + 1;
            else
                r11 = mid;
        }
        // cout << l11 << " ";
        l11--;
        if (i - l11 < len) {
            dp[i] = mod;
            continue;
        }
        if (l11 == 1) l11 = 0;
        r11 = i - len;
        while (!q.empty() && q.front() < l11) q.pop_front();
        while (!q.empty() && dp[q.back()] >= dp[r11]) q.pop_back();
        q.push_back(r11);
        if (i - l11 < len) {
            dp[i] = mod;
            continue;
        }
        dp[i] = dp[q.front()] + 1;
    }
    if (dp[n] > n)
        cout << "-1";
    else
        cout << dp[n];
}