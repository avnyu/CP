#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

typedef pair<int, bitset<1001>> state;

bool good(stack<state>& x, stack<state>& y, int k) {
    if (x.empty() && y.empty())
        return false;
    else if (x.empty())
        return y.top().second.test(0);
    else if (y.empty())
        return x.top().second.test(k);
    else {
        state tmp;
        tmp.second = x.top().second & y.top().second;
        return tmp.second.any();
    }
}
void add(stack<state>& x, int v, int k) {
    state tmp;

    if (x.empty())
        tmp.second.set(0);
    else
        tmp.second = x.top().second;

    x.push(make_pair(v, tmp.second | (tmp.second << v)));
}
void rem(stack<state>& x, stack<state>& y, int k) {
   if (y.empty()) {
        while (x.size()) {
            int v = x.top().first;
            x.pop();

            state tmp;
            if (y.size())
                tmp.second = y.top().second;
            else
                tmp.second.set(k);

            y.push(make_pair(v, tmp.second | (tmp.second >> v)));
        }
    }
    y.pop();
}
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& i : a) cin >> i;

    stack<state> x, y;

    int res = n + 1;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && !good(x, y, k)) {
            add(x, a[j], k);
            j++;
        }
        if (good(x, y, k)) {
            gmin(res, j - i);
            // print(i, j);
            // if (x.size()) print(x.top().second.to_string());
            // else print("x");
            // print(x.size());
            // if (y.size()) print(y.top().second.to_string());
            // else print("y");
            // print(y.size());
        }
        rem(x, y, k);
    }

    print(res == n + 1 ? -1 : res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve();

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