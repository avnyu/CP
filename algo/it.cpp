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

const int lgN = 18;
const int N = 1 << lgN;
const int M = 1e9 + 7;
vi mit(N << 1), lef(N << 1), rig(N << 1);

int upd(int p, int v, int i = 1, int l = 0, int r = N - 1) {
    if (p < l || p > r) return -M;
    if (l == r) return mit[i] = v;
    int m = (l + r) >> 1;
    mit[i] = max(upd(p, v, i << 1, l, m), upd(p, v, i << 1 | 1, m + 1, r));
}
int get(int b, int e, int i = 1, int l = 0, int r = N - 1) {
    if (e < l || b > r) return -M;
    if (b <= l && r <= e) return mit[i];
    int m = (l + r) >> 1;
    return max(get(b, e, i << 1, l, m), get(b, e, i << 1 | 1, m + 1, r));
}

int main() { return 0; }

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