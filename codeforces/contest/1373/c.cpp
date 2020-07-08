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

int cal(string s) {
    int res = 0;
    for (int init = 0; init < 1e6; ++init) {
        int cur = init;
        bool ok = true;
        for (auto& c : s) {
            res++;
            if (c == '+')
                ++cur;
            else
                --cur;
            if (cur < 0) {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    return res;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll res = 0;
    int prv = 0;
    vi cnt(n + 1);
    for (int i = 0; i < n; ++i) cnt[i + 1] = cnt[i] + (s[i] == '+' ? 1 : -1);
    for (int i = 0; i++ < n;) {
        cnt[i] = min(cnt[i], cnt[i - 1]);
        while (prv + cnt[i] < 0) res += i, prv++;
    }
    res += n;
    print(res);
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
    cout << x << ' ';
    print(args...);
}
