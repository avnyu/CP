#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define pb push_back
#define eb emplace_back
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
    int n;
    cin >> n;
    vector<string> a = {"Ashishgup", "FastestFinger"};
    if (n & 1) {
        print(a[n == 1]);
        return;
    }
    int d2 = 1;
    while (n % 2 == 0) {
        d2 <<= 1;
        n >>= 1;
    }
    int cnt = 0;
    for (int i = 3; i < int(1e5); i += 2)
        while (n % i == 0) {
            n /= i;
            ++cnt;
        }
    cnt += n != 1;
    if (cnt > 1) {
        print(a[0]);
        return;
    }
    cnt += (d2 > 2);
    print(a[cnt & 1]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    cout << x << ' ';
    print(args...);
}