#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int oo = 1e6;

int cal(int a, int b) {
    if (a % b == 0) return a / b;
    int m = a / b;
    while (1) {
        if (m * (b - 1) <= a && a <= b * m) return m;
        if (m * (b - 1) > a) break;
        m++;
    }
    return -1;
}

int get_cnt(vector<int>& sum, int s) {
    int cnt = 0;

    for (auto& j : sum) {
        int x = cal(j, s);
        if (x == -1) return -1;
        cnt += x;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0), sum;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (auto& i : cnt)
        if (i > 0) sum.emplace_back(i);
    sort(sum.begin(), sum.end());

    for (int i = 1; i * i <= sqrt(sum.front()); ++i) {
        int s = sum.front() / i + 1;
        int cnt = get_cnt(sum, s);
        if (cnt != -1) {
            cout << cnt << '\n';
            return;
        }

        s--;
        cnt = get_cnt(sum, s);
        if (cnt != -1) {
            cout << cnt << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}