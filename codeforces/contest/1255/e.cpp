#include <bits/stdc++.h>
#define lli long long
using namespace std;

lli N = 1e6 + 1;
lli n;
lli oo = 1e18;
vector<lli> prefix_sum(N);
vector<lli> prime;

void get_prime(lli sum) {
    vector<char> chk(N);
    for (lli i = 2; i < N; ++i) {
        if (!chk[i]) {
            if (sum % i == 0) prime.push_back(i);
            while (sum % i == 0) sum /= i;
            lli j = i + i;
            while (j < N) {
                chk[j] = 1;
                j += i;
            }
        }
    }
    if (sum > 1) prime.push_back(sum);
}
lli cal_res(lli d) {
    lli res = 0;
    for (lli i = 1; i <= n; ++i)
        res += min(prefix_sum[i] % d, d - prefix_sum[i] % d);
    return res;
}

void solve() {
    cin >> n;
    for (lli i = 1; i <= n; ++i) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }

    get_prime(prefix_sum[n]);

    lli res = oo;
    for (auto& i : prime) res = min(res, cal_res(i));

    cout << (res == oo ? -1 : res) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}