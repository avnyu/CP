#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<ll>>
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

bool change(vi& a, vvi& ans, ll x, ll y, ll z) {
    ans.push_back(vi{x + 1, y + 1, z});
    a[x] -= (x + 1) * z;
    a[y] += (x + 1) * z;
    return a[x] >= 0 && a[y] >= 0;
}
void solve() {
    ll n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;
    ll sum = 0;
    for (auto& i : a) sum += i;
    if (sum / n * n != sum) {
        print("-1");
        return;
    }
    ll des = sum / n;
    vector<vector<ll>> ans;
    for (ll i = 1; i < n; ++i) {
        ll x = a[i] / (i + 1);
        if (!change(a, ans, i, 0, x)) {
            print("-1");
            return;
        }
    }
    vii prior(n);
    for (ll i = 0; i < n; ++i) {
        if (a[i] > des)
            prior[i] = ii{des + i + 1 - a[i], i};
        else
            prior[i] = ii{n + n, i};
    }
    sort(all(prior));

    // print("Des", des);
    // for (ll i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];

    for (ll j = 0; j < n; ++j) {
        if (prior[j].se == 0) continue;
        ll i = prior[j].se;

        if (a[i] > des) {
            if (!change(a, ans, 0, i, des + i + 1 - a[i])) {
                print("-1");
                return;
            }
            if (!change(a, ans, i, 0, 1)) {
                print("-1");
                return;
            }
        } else {
            if (!change(a, ans, 0, i, des - a[i])) {
                print("-1");
                return;
            }
        }
        if (a[i] != des) {
            print("-1");
            return;
        }
    }
    print(ans.size());
    for (auto& i : ans) print(i[0], i[1], i[2]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    ll t = 1;
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