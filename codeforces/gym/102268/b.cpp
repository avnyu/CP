#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int N = 2e5 + 7;
int n, k;
vi a(N);
set<ii> lis;

void solve() {
    cin >> n >> k;
    for (int i = 0; i++ < n;) cin >> a[i];

    rotate(a.begin() + 1, min_element(a.begin() + 1, a.begin() + n + 1),
           a.begin() + n + 1);

    ll l = a[1], r = 2e9, res = 0;
    while (l <= r) {
        ll m = l + r >> 1;

        int len = 0;
        lis.clear();
        lis.insert({0, 0});

        for (int i = 0; i++ < n;) {
            ii u = {a[i], 0};
            auto t = lis.upper_bound({m - a[i], n});
            if (t == lis.begin()) continue;
            --t;
            u.second = t->second + 1;
            len = max(len, u.second);

            bool add = true;

            while (1) {
                auto v = lis.upper_bound(u);
                if (v == lis.end())
                    break;
                else if (u.first == v->first) {
                    add = false;
                    break;
                } else if (u.second >= v->second)
                    lis.erase(v);
                else
                    break;
            }

            while (1) {
                auto v = lis.lower_bound(u);
                if (v == lis.begin())
                    break;
                else {
                    --v;
                    if (u.first == v->first)
                        lis.erase(v);
                    else if (u.second <= v->second) {
                        add = false;
                        break;
                    } else
                        break;
                }
            }

            if (add) lis.insert(u);
        }

        if (len >= k) {
            res = m;
            r = m - 1;
        } else
            l = m + 1;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}