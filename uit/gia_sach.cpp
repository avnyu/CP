#include <bits/stdc++.h>
using namespace std;

long long N = 1e5 + 7;
vector<long long> ft(N);

void up(long long p, long long v) {
    while (p < N) {
        ft[p] += v;
        p += p & -p;
    }
}
long long get(long long p) {
    long long res = 0;
    while (p) {
        res += ft[p];
        p -= p & -p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        long long b;
        cin >> b;
        up(i, b);
    }
    long long m;
    cin >> m;
    for (long long i = 0; i < m; ++i) {
        long long t;
        cin >> t;
        long long lower = get(t - 1);
        long long lower_equal = get(t);
        long long all = get(N - 1);

        cout << min(lower, all - lower_equal) << ' ';
        up(t, 1);
    }

    return 0;
}