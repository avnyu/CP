#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
vector<int>p(N);

void init() {
    for (int i = 1; i < N; ++i)if (!p[i])for (int j = 1, x = i; x < N; j++, x = i * j * j)if (!p[x])p[x] = i;
}
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto&i : a)cin >> i;

    unordered_map<int, int>cnt;
    for (auto&i : a)cnt[p[i]]++;

    vector<int>ans(2, 0);
    for (auto&i : cnt)ans[0] = max(ans[0], i.second);
    for (auto&i : cnt)ans[1] += i.second % 2 == 0 || i.first == 1 ? i.second : 0;
    ans[1] = max(ans[1], ans[0]);

    int m;
    cin >> m;
    for (long long x; m--;) {
        cin >> x;
        cout << ans[min(x, 1LL)] << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    init();

    int t = 1;
    cin >> t;
    for (; t--;)solve();

    return 0;
}
