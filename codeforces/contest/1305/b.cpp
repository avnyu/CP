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
    string s;
    cin >> s;
    vi lef, rig;
    int n = s.size();
    int i = 0, j = n - 1;
    while (1) {
        while (i < n && s[i] != '(') i++;
        while (j > i && s[j] != ')') j--;
        if (j <= i) break;
        lef.eb(i++);
        rig.eb(j--);
    }
    if (lef.empty()) {
        cout << "0\n";
        return;
    }
    cout << "1\n" << lef.size() + rig.size() << '\n';
    for (int i = 0; i < lef.size(); ++i) cout << lef[i] + 1 << ' ';
    for (int i = rig.size(); i--;) cout << rig[i] + 1 << " \n"[!i];
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
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}