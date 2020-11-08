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

bool test(int x, int n, int a = 0, int b = 0, int c = 0) {
    if (n == 2) {
        int k = (x - a - b) / 2;
        if (k * 2 + a + b == x && gcd(k + a, k + b) == 1 && k + a > 1)
            return true;
    } else if (n == 3) {
        int k = (x - a - b - c) / 3;
        if (k * 3 + a + b + c == x && gcd(k + a, k + b) == 1 &&
            gcd(k + a, k + c) == 1 && gcd(k + b, k + c) == 1 && k + a > 1)
            return true;
    }
    return false;
}
void solve(int T) {
    cout << "Case #" << T << ": ";
    int x;
    cin >> x;
    if (test(x, 2, 0, 1))
        print(1);
    else if (test(x, 2, 0, 2))
        print(2);
    else if (test(x, 3, 0, 1, 2))
        print(2);
    else if (test(x, 3, 0, 1, 3))
        print(3);
    else if (test(x, 3, 0, 2, 3))
        print(3);
    else if (test(x, 3, 0, 1, 4))
        print(4);
    else if (test(x, 3, 0, 2, 4))
        print(4);
    else if (test(x, 3, 0, 3, 4))
        print(4);
    else
        print(-1);
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