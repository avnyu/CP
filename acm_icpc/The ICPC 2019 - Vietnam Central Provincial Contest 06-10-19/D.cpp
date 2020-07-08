#include <bits/stdc++.h>
using namespace std;

const int m = (int) 1e6 + 1;
const int sm = (int) sqrt(m) + 1;

vector<bool> prime;

void init() {
    prime.assign(m, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < sm; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < m; j += i) {
                prime[j] = false;
            }
        }
    }
}

const int oo = 1000000;
vector<int> t;

void up(int x) {
    cout << "up " << x << '\n';
    while (x < oo) {
        t[x] += 1;
        x += x & -x;
    }
}

int get(int x) {
    cout << "get " << x;
    int res = 0;
    while (x > 0) {
        res += t[x];
        x -= x & -x;
    }
    cout << ' ' << res << '\n';
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    init();
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i] = a[i - 1] + prime[x];
    }
    vector<int> b(n + 1);
    for (int i = 0; i <= n; ++i) {
        b[i] = a[i] * 2 - i + n + n;
    }
    t.assign(oo + 1, 0);
    long long ans = 0;
    up(b[0]);
    for (int i = 1; i <= n; ++i) {
        ans += get(b[i]);
        up(b[i]);
    }
    cout << ans << '\n';
    return 0;
}