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
#define prtarr(u) \
    for (auto& i : u) cout << i << " \n"[&i == &u.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1 << 15;
const int lgN = 15;
vvi st(N, vi(lgN, -N));

vi longestBracket(string s) {
    int n = s.size();
    vvi pos(N << 1);
    st[0][0] = N;
    for (int i = 0; i < n; ++i) {
        st[i + 1][0] = st[i][0] + (s[i] == '(' ? 1 : -1);
        pos[st[i + 1][0]].push_back(i + 1);
    }

    for (int j = 1; j < lgN; ++j)
        for (int i = 0; i + (1 << j) < N; ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    auto lowest = [&](int l, int r) {
        int t = 31 - __builtin_clz(r - l + 1);
        return min(st[l][t], st[r + 1 - (1 << t)][t]);
    };

    int len = 0, cnt = 1;
    for (int i = 0; i++ < n;) {
        int r = i - 1, add = N, &prv = st[i - 1][0];
        while (add) {
            if (r + add < N && lowest(r, r + add) >= prv) r += add;
            add >>= 1;
        }
        if (r < i) continue;
        r = upper_bound(pos[prv].begin(), pos[prv].end(), r) -
            pos[prv].begin() - 1;

        // cout << i - 1 << ' ' << pos[prv][r] << endl;

        if (pos[prv][r] - i + 1 > len) {
            len = pos[prv][r] - i + 1;
            cnt = 1;
        } else if (pos[prv][r] - i + 1 == len)
            cnt++;
    }

    // cout << "res " << len << ' ' << cnt << '\n';
    // for (int i = 0; i++ < n;) cout << st[i][0] << " \n"[i == n];

    return vi{len, cnt};
}
void solve(int T) {
    string s;
    cin >> s;
    auto res = longestBracket(s);
    prtarr(res);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
        cout << x << endl;
    }
}