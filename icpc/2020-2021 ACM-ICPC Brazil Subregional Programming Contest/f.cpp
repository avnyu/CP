#include <bits/stdc++.h>

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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    string s;
    cin >> s;
    int p[2] = {}, serve = 0, g[2] = {};
    for (auto& c : s) {
        if (c == 'S') {
            p[serve]++;
        } else if (c == 'R') {
            serve ^= 1;
            p[serve]++;
        } else {
            if (g[0] == 2)
                cout << "2 (winner) - " << g[1] << '\n';
            else if (g[1] == 2)
                cout << g[0] << " - 2 (winner)\n";
            else
                cout << g[0] << " (" << p[0] << (serve == 0 ? "*" : "")
                     << ") - " << g[1] << " (" << p[1] << (serve ? "*" : "")
                     << ")\n";
        }
        if (p[0] == 10 || (p[0] >= 5 && p[0] - p[1] >= 2)) {
            g[0]++;
            serve = 0;
            p[0] = p[1] = 0;
        }
        if (p[1] == 10 || (p[1] >= 5 && p[1] - p[0] >= 2)) {
            g[1]++;
            serve = 1;
            p[0] = p[1] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
        cout << x << '\n';
    }
}