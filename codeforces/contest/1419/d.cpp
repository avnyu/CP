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
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    priority_queue<int, vector<int>, greater<int>>x, y;
    vi res;
    for (int i = 0; i < (n - 1) >> 1; ++i)x.push(a[i]);
    for (int i = (n - 1) >> 1; i < n; ++i)y.push(a[i]);
    int i = 0;

    res.push_back(y.top());
    y.pop();

    vi out;

    while (1) {
        if (res.size() & 1) {
            if (x.empty())
                break;
            else if (x.top() >= res.back())
                if (y.empty())
                    break;
                else {
                    out.push_back(res.back());
                    res.pop_back();

                    res.push_back(y.top());
                    y.pop();
                }
            else {
                res.push_back(x.top());
                x.pop();
            }
        } else {
            if (y.empty())
                break;
            else if (y.top() <= res.back()) {
                out.push_back(y.top());
                y.pop();
            }
            else {
                res.push_back(y.top());
                y.pop();
            }
        }
    }
    while (x.size()) {
        out.push_back(x.top());
        x.pop();
    }
    while (y.size()) {
        out.push_back(y.top());
        y.pop();
    }

    print((res.size() - 1) >> 1);
    for (int i = 0; i < res.size(); ++i)cout << res[i] << " \n"[i == n - 1];
    for (int i = 0; i < out.size(); ++i)cout << out[i] << " \n"[i == out.size() - 1];
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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