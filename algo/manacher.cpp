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
#define prt(vec) \
    for (auto& ele : vec) cout << ele << " \n"[&ele == &vec.back()]
#define ub(vec, u) upper_bound(vec.begin(), vec.end(), u) - vec.begin()
#define viii vector<tuple<int, int, int>>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

vvi manacher(string s) {
    int n = s.size(), m;
    vvi d(2, vi(n, 0));
    m = 0;
    for (int i = 0; i < n; ++i) {
        d[0][i] = m + d[0][m] > i ? min(d[0][m + m - i], m + d[0][m] - i) : 0;
        while (i - d[0][i] - 1 >= 0 && i + d[0][i] + 1 < n && s[i - d[0][i] - 1] == s[i + d[0][i] + 1]) d[0][i]++;
        if (i + d[0][i] > m + d[0][m]) m = i;
    }
    m = 0;
    for (int i = 0; i < n; ++i) {
        d[1][i] = m + d[1][m] > i ? min(d[1][m + m - i - 1], m + d[1][m] - i) : 0;
        while (i - d[1][i] - 1 >= 0 && i + d[1][i] < n && s[i - d[1][i] - 1] == s[i + d[1][i]]) d[1][i]++;
        if (i + d[1][i] > m + d[1][m]) m = i;
    }
    return d;
}
void solve(int T) {
	string s = "aabaccabcba";
	auto d = manacher(s);
	prt(d[0]);
	prt(d[1]);
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
