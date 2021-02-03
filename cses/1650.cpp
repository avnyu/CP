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
#define what_is(x) cerr << #x << " is " << x << endl;
#define iii tuple<int, int, int>

using namespace std;

const int N = 1e5 + 7;
const int S = sqrt(N);

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<iii> query(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        query[i] = {l - 1, r, i};
    }

    sort(all(query), [](iii& a, iii& b) {
        if (get<0>(a) / S != get<0>(b) / S)
            return get<0>(a) / S < get<0>(b) / S;
        return get<1>(a) < get<1>(b);
    });

    vi res(q);
    int nim = 0, pl = 0, pr = 0;
    for (auto& q : query) {
        int l, r, p;
        tie(l, r, p) = q;

        for (int i = l; i < pl; ++i) nim ^= a[i];
        for (int i = pr; i < r; ++i) nim ^= a[i];

        for (int i = pl; i < l; ++i) nim ^= a[i];
        for (int i = r; i < pr; ++i) nim ^= a[i];

        res[p] = nim;

        pl = l, pr = r;
    }

    for (int i = 0; i < q; ++i) cout << res[i] << "\n";
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
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}