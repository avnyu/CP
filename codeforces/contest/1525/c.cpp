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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(3));
    for (auto& i : a) cin >> i[0];
    for (auto& i : a) {
        char c;
        cin >> c;
        i[1] = c == 'R';
    }
    for (int i = 0; i < n; ++i) a[i][2] = i;

    sort(a.begin(), a.end());
    // for (int i = 0; i < n; ++i) print(a[i][0], a[i][1], a[i][2]);

    stack<int> rig[2];
    queue<int> lef[2];
    vi res(n, -2);

    for (int i = 0; i < n; ++i) {
        if (a[i][1])
            rig[a[i][0] & 1].push(i);
        else {
            if (rig[a[i][0] & 1].size()) {
                auto& r = rig[a[i][0] & 1].top();
                res[a[i][2]] = res[a[r][2]] = a[i][0] - a[r][0];
                rig[a[i][0] & 1].pop();
            } else {
                lef[a[i][0] & 1].push(i);
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        while (lef[i].size() > 1) {
            auto l = lef[i].front();
            lef[i].pop();

            auto r = lef[i].front();
            lef[i].pop();

            res[a[l][2]] = res[a[r][2]] = a[l][0] + a[r][0];
            // print("! ", a[l][2], a[r][2]);
        }
        while (rig[i].size() > 1) {
            auto l = rig[i].top();
            rig[i].pop();

            auto r = rig[i].top();
            rig[i].pop();

            res[a[l][2]] = res[a[r][2]] = m - a[l][0] + m - a[r][0];
            // print("! ", a[l][2], a[r][2]);
        }
        while (rig[i].size() && lef[i].size()) {
            auto l = lef[i].front();
            lef[i].pop();

            auto r = rig[i].top();
            rig[i].pop();

            res[a[l][2]] = res[a[r][2]] = m + a[l][0] + m - a[r][0];
            // print("! ", a[l][2], a[r][2]);
        }
    }

    for (int i = 0; i < n; ++i) cout << res[i] / 2 << " \n"[i == n - 1];
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