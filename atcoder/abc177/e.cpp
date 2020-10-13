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
    const int N = 1e6 + 7;
    vi mp(N);
    iota(all(mp), 0);
    for (int i = 2; i < N; ++i) {
        if (i == mp[i])
            for (int j = i + i; j < N; j += i) mp[j] = i;
    }
    vector<bool> chk(N, 0);

    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;

    int gcd = a[0];
    int pw = 1;
    for (auto& i : a) {
        gcd = __gcd(gcd, i);
        map<int, int> tmp;
        while (i > 1) {
            if (chk[mp[i]]) pw = 0;
            tmp[mp[i]] = 1;
            i /= mp[i];
        }
        for (auto& i : tmp) {
            chk[i.fi] = 1;
        }
    }

    if (gcd == 1 && pw)
        print("pairwise coprime");
    else if (gcd == 1)
        print("setwise coprime");
    else
        print("not coprime");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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