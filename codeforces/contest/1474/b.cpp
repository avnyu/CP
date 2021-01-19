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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e6 + 7;
vi p(N), pri(1, 1);

void init() {
    iota(p.begin(), p.end(), 0);
    for (int i = 2; i < N; ++i)
        if (p[i] == i) {
            pri.push_back(i);
            for (int j = i + i; j < N; j += i) p[j] = i;
        }
}
void solve(int T) {
    int d;
    cin >> d;
    int p1 = 0, p2 = 0;

    for (int add = 1 << 20; add; add >>= 1)
        if (p1 + add < (int)pri.size() && pri[p1 + add] - 1 < d) p1 += add;
    p1++;

    for (int add = 1 << 20; add; add >>= 1)
        if (p2 + add < (int)pri.size() && pri[p2 + add] - pri[p1] < d)
            p2 += add;
    p2++;

    print(pri[p1] * pri[p2]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
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