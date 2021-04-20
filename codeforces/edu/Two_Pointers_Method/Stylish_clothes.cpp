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
    vi l(4);
    vvi c(4);
    for (int i = 0; i < 4; ++i) {
        cin >> l[i];
        c[i].resize(l[i]);
        for (auto& j : c[i]) cin >> j;
        sort(all(c[i]));
    }

    int dif = 1e9;
    vi res(4);

    for (int i = 0; i < 4; ++i) {
        vi p(4, 0);
        for (; p[i] < l[i]; ++p[i]) {
            int cur = -1;
            for (int j = 0; j < 4; ++j) {
                while (p[j] < l[j] && c[j][p[j]] < c[i][p[i]]) p[j]++;
                if (p[j] == l[j]) {
                    cur = -1;
                    break;
                }
                cur = max(cur, c[j][p[j]] - c[i][p[i]]);
            }
            if (cur != -1 && cur < dif) {
                dif = cur;
                for (int j = 0; j < 4; ++j) res[j] = c[j][p[j]];
            }
        }
    }

    prt(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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