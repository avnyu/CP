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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    map<string, int> val;
    val["ter"] = 12;
    val["gig"] = 9;
    val["meg"] = 6;
    val["kil"] = 3;
    val["dec"] = -1;
    val["cen"] = -2;
    val["mil"] = -3;
    val["mic"] = -6;
    val["nan"] = -9;

    map<string, int> len;
    len["ter"] = 4;
    len["gig"] = 4;
    len["meg"] = 4;
    len["kil"] = 4;
    len["dec"] = 4;
    len["cen"] = 5;
    len["mil"] = 5;
    len["mic"] = 5;
    len["nan"] = 4;

    string s;
    cin >> s;
    int p = 0, res = 0;

    while (s.substr(p, 3) != "met") {
        res += val[s.substr(p, 3)];
        p += len[s.substr(p, 3)];
    }

    if (s.back() == '2')
        res *= 2;
    else if (s.back() == '3')
        res *= 3;

    print(res);
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