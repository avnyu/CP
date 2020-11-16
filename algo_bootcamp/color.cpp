#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

#define iii tuple<int, int, int>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int m, n;
    cin >> m >> n;
    vi st(n + 1, -1), ed(n + 1), a(m), used(n + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (st[a[i]] == -1) st[a[i]] = i;
        ed[a[i]] = i;
    }

    vector<iii> res;
    stack<int> s;
    for (int i = 0; i < m; ++i) {
        if (st[a[i]] == i) {
            s.push(a[i]);
            res.push_back(iii{a[i], st[a[i]], ed[a[i]]});
        }
        if (ed[a[i]] == i) {
            if (s.empty() || s.top() != a[i]) {
                print(-1);
                return;
            }
            s.pop();
        }
        if (st[a[i]] != i && ed[a[i]] != i)
            if (s.empty() || s.top() != a[i]) {
                print(-1);
                return;
            }
    }

    cout << res.size() << '\n';
    for (auto& i : res) {
        int c, x, y;
        tie(c, x, y) = i;
        print(c, x + 1, y + 1);
    }
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}