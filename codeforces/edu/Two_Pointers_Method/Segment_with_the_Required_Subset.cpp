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

typedef pair<int, bitset<1000>> state;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& i : a) cin >> i;

    stack<state> s, t;
    int res = n + 1;
    state x;
    x.second.set(0);

    auto good = [](stack<state>&vs, stack<state>&vt, int vk) {
        if (vs.empty() && vt.empty())
            return false;
        else if (vs.empty())
            return vt.top().second.test(vk);
        else if (vt.empty())
            return vs.top().second.test(vk);
        else {
            for (int i = 0; i <= vk; ++i)
                if (vs.top().second.test(i) & vt.top().second.test(vk - i))
                    return true;
            return false;
        }
    };

    auto add = [] (stack<state>&vs, int v, state vx) {
        if (vs.empty()) {
            state tmp;
            tmp.first = v;
            tmp.second = vx.second | (vx.second << v);
            vs.push(tmp);
        } else {
            state tmp;
            tmp.first = v;
            tmp.second = vs.top().second | (vs.top().second << v);
            vs.push(tmp);
        }
    };

    auto rem = [] (auto vadd, stack<state>&vs, stack<state>&vt, state vx) {
        if (vt.empty()) {
            while (!vs.empty()) {
                vadd(vt, vs.top().first, vx);
                vs.pop();
            }
        } else vt.pop();
    };

    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && !good(s, t, k)) {
            add(s, a[j], x);
            ++j;
        }

        if (good(s, t, k)) {
            gmin(res, j - i);
            print(i, j);
        }

        rem(add, s, t, x);
    }

    print(res <= n ? res : -1);
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