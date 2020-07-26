#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n;
    cin >> n;
    n <<= 1;
    vi a(n);
    for (auto& i : a) cin >> i;

    vi seg;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && a[j] < a[i]) j++;
        seg.push_back(j - i);
        i = j;
    }

    // for (int i = 0; i < seg.size(); ++i)
    //     cout << seg[i] << " \n"[i == seg.size() - 1];
    sort(all(seg));
    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < seg.size(); ++i)
        for (int j = n; j >= 0; j--)
            if (j - seg[i] >= 0 && dp[j - seg[i]]) dp[j] = 1;
    
    print(dp[n >> 1] ? "YES" : "NO");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}
