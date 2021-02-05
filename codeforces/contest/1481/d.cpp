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
    for (auto &i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n, m;
    cin >> n >> m;
    vvi e(n + 1, vi(n + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == 'a')
                e[i][j] = 1;
            else if (c == 'b')
                e[i][j] = 2;
        }

    int cnt[2][1003][3] = {};

    if (m & 1) {
        print("YES");
        for (int i = 0; i <= m; ++i) cout << (i & 1) + 1 << " \n"[i == m];
    } else {
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt[0][i][e[i][j]]++;
                cnt[1][i][e[j][i]]++;
            }
            if (cnt[0][i][1] && cnt[1][i][1]) {
                b = i;
                for (int j = 0; j < n; ++j)
                    if (e[i][j] == 1) {
                        c = j;
                        break;
                    }
                for (int j = 0; j < n; ++j)
                    if (e[j][i] == 1) {
                        a = j;
                        break;
                    }
            } else if (cnt[0][i][2] && cnt[1][i][2]) {
                b = i;
                for (int j = 0; j < n; ++j)
                    if (e[i][j] == 2) {
                        c = j;
                        break;
                    }
                for (int j = 0; j < n; ++j)
                    if (e[j][i] == 2) {
                        a = j;
                        break;
                    }
            }
        }

        if (a == -1)
            print("NO");
        else {
            vi res(m + 1);
            res[m / 2] = b;
            for (int i = m / 2 - 1, j = m / 2 + 1; i >= 0; --i, ++j) {
                if ((m / 2 - i) % 2 == 1) {
                    res[i] = a != c ? a : a;
                    res[j] = a != c ? c : a;
                } else {
                    res[i] = a != c ? c : b;
                    res[j] = a != c ? a : b;
                }
            }
            print("YES");
            for (int i = 0; i <= m; ++i) cout << res[i] + 1 << " \n"[i == m];
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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