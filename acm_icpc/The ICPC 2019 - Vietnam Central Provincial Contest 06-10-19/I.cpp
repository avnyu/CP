#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int nlog = (int) log2(n) + 1;
    vector<vector<int>> gcd(n, vector<int>(nlog + 1));
    vector<int> log(n + 1);
    vector<int> p(1, 1);
    log[0] = log[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log[i] = log[i >> 1] + 1;
    }
    for (int i = 1; i <= nlog; ++i) {
        p.push_back(p.back() * 2);
    }
    for (int i = 0; i < n; ++i) {
        gcd[i][0] = a[i];
    }
    for (int i = 1; i <= nlog; ++i) {
        for (int j = 0; j + p[i] <= n; ++j) {
            gcd[j][i] = __gcd(gcd[j][i - 1], gcd[j + p[i - 1]][i - 1]);
        }
    }
    auto get = [&](int x, int y) {
        return __gcd(gcd[x][log[y - x + 1]], gcd[y - p[log[y - x + 1]] + 1][log[y - x + 1]]);
    };
    map<int, long long> cnt;

    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n) {
            int lef = j;
            int rig = n - 1;
            int cur = get(i, j);
            int pos;
            while (lef <= rig) {
                int mid = (lef + rig) >> 1;
                if (get(i, mid) == cur) {
                    pos = mid;
                    lef = mid + 1;
                } else {
                    rig = mid - 1;
                }
            }
            cnt[cur] += pos - j + 1;
            j = pos + 1;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (cnt.find(x) != cnt.end()) {
            cout << cnt[x] << '\n';
        } else {
            cout << "0\n";
        }
    }
    return 0;
}