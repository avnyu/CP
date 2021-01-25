#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vi a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    vi cnt(128);
    for (int i = 0; i < (int)s.size(); ++i) cnt[s[i]]++;

    int cur = 127;
    vi pos(57);
    int ps = 0;
    string res(m, '_');

    for (; cur >= 0;) {
        int c = 0;

        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < ps; ++j) sum += abs(i - pos[j]);
            
            if (res[i] == '_' && a[i] == sum) {
                c++;
            }
        }

        for (; cur >= 0 && cnt[cur] < c;) cur--;

        if (cur < 0) {
            print("WA");
            break;
        }

        int nps = ps;

        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < ps; ++j) sum += abs(i - pos[j]);
            
            if (res[i] == '_' && a[i] == sum) {
                pos[nps++] = i;
                res[i] = cur;
            }
        }

        ps = nps;
        cur--;
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

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