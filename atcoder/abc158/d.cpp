#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
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
template <typename T>
void print_all(vector<T>& a);

void solve() {
    const int N = 5e5;
    string s(N, '0');
    int l = 2e5, r = 2e5;
    string t;
    cin >> t;
    for (auto& c : t) s[r++] = c;
    int q, rev = 0;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1)
            rev ^= 1;
        else {
            int f;
            char c;
            cin >> f >> c;
            if ((f ^ rev) & 1)
                s[--l] = c;
            else
                s[r++] = c;
        }
    }
    t = string(s.begin() + l, s.begin() + r);
    if (rev) reverse(all(t));
    cout << t << '\n';
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