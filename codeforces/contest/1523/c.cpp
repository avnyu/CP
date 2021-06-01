#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> b;

    stack<int> s;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            b.push_back(vi{1});
        } else {
            if (a[i] == 1) {
                b.push_back(b.back());
                b.back().push_back(1);
            } else {
                while (b[s.top()].back() != a[i] - 1) s.pop();
                b.push_back(b[s.top()]);
                b.back().back()++;
                s.pop();
            }
        }
        s.push(i);

        for (int j = 0; j < b[i].size(); ++j)
            cout << b[i][j] << ".\n"[j == b[i].size() - 1];
    }

    // prt(p);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve();

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