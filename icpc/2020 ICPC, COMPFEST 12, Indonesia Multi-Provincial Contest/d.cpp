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

template <class Type>
struct BIT1D {
    vector<Type> data;
    int size;
    BIT1D(int n) : size(n + 1) { data.assign(size, 0); }
    void update(int x, int c) {
        while (x < size) {
            data[x] += c;
            x += x & -x;
        }
    }
    void update(int u, int v, int c) {
        update(u, c);
        update(v + 1, -c);
    }
    Type get(int x) {
        Type ans = 0;
        while (x > 0) {
            ans += data[x];
            x -= x & -x;
        }
        return ans;
    }
    Type get(int u, int v) { return get(v) - get(u - 1); }
};

template <class Type>
struct BIT2D {
    vector<BIT1D<Type>> data;
    int n, m;
    BIT2D(int _n, int _m) : n(_n + 1), m(_m + 1) {
        data.assign(n, BIT1D<Type>(m));
    }
    void update(int x, int y1, int y2, int c) {
        while (x < n) {
            data[x].update(y1, y2, c);
            x += x & -x;
        }
    }
    void update(int x1, int y1, int x2, int y2, int c) {
        update(x1, y1, y2, c);
        update(x2 + 1, y1, y2, -c);
    }
    Type get(int x, int y) {
        Type ans = 0;
        while (x > 0) {
            ans += data[x].get(y);
            x -= x & -x;
        }
        return ans;
    }
};
void solve() {}
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
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}