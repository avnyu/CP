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

bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return n > 2;
}
void solve() {
    int n;
    cin >> n;
    if (isprime(n)) {
        print(1);
        print(n);
    } else if (isprime(n - 2)) {
        print(2);
        print(2, n - 2);
    } else {
        const int N = 1e4;
        vi p(N), fp;
        for (int i = 2; i < N; ++i)
            if (p[i] == 0) {
                fp.push_back(i);
                for (int j = i + i; j < N; j += i) p[j] = 1;
            }
        vii com(N, {-1, -1});
        int m = fp.size();
        for (int i = 0; i < m; ++i)
            for (int j = i; j < m && fp[i] + fp[j] < N; ++j)
                com[fp[i] + fp[j]] = {fp[i], fp[j]};

        for (int i = 0; i < N; ++i)
            if (com[i].fi != -1 && isprime(n - i)) {
                print(3);
                print(com[i].fi, com[i].se, n - i);
                break;
            }    
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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