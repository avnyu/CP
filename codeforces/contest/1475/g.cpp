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

const int N = 2e5 + 7;
vvi dv(N);

void init() {
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i) dv[j].push_back(i);
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        int t = 1;
        for (auto& d : dv[a[i]])
            if (pos.find(d) != pos.end()) t = max(t, a[pos[d]] + 1);
        pos[a[i]] = i;
        a[i] = t;
    }

    cout << n - (*max_element(a.begin(), a.end())) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

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