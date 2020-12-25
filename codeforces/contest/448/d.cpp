#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    long long res = 0, add = 1LL << 40;
    auto count = [&](long long t) {
        long long cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += min(1LL * m, t / i);
        return cnt;
    };
    while (add) {
        if (count(res + add) < k) res += add;
        add >>= 1;
    }

    cout << res + 1 << '\n';

    return 0;
}