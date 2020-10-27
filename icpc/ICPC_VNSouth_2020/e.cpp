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

bool test(vi &a) {
    int n = a.size();
    for (int i = 1; i < n - 1; ++i)
        if (a[i - 1] < a[i] && a[i] < a[i + 1])
            return false;
        else if (a[i - 1] > a[i] && a[i] > a[i + 1])
            return false;
    return true;
}
vi smallest(int n) {
    vi a(n);
    iota(a.begin(), a.end(), 1);
    for (int i = 2; i < n; i += 2) swap(a[i], a[i - 1]);
    return a;
}
vi bruteforce(vi a) {
    while (next_permutation(a.begin(), a.end())) {
        if (test(a)) break;
    }
    if (!test(a)) a = smallest(int(a.size()));
    return a;
}
void remain(vi &a, set<int> &b, int p) {
    int n = a.size(), i = p;
    while (i < n) {
        a[i] = *b.begin();
        b.erase(b.begin());
        i++;
    }
    for (i = p + 2; i < n; i += 2) swap(a[i - 1], a[i]);
}
void element_swap(vi &a, set<int> &b, int i, int cmp = -1) {
    b.insert(a[i]);
    set<int>::iterator t;
    if (cmp == -1)
        t = b.upper_bound(a[i]);
    else
        t = b.upper_bound(cmp);
    a[i] = *t;
    b.erase(t);
}
bool change(vi &a, set<int> &b, int i) {
    if (b.upper_bound(a[i]) == b.end()) return false;
    if (!i) {
        element_swap(a, b, i);
        remain(a, b, i + 1);
        return true;
    }
    if ((i && a[i] > a[i - 1]) || i == 1) {  // as max
        auto t = b.upper_bound(a[i]);
        if (*t > a[i - 1]) {
            element_swap(a, b, i);
            remain(a, b, i + 1);
            return true;
        }
    }
    if ((i && a[i] < a[i - 1]) || i == 1) {  // as min
        auto t = b.upper_bound(a[i]);
        if (*t > a[i - 1]) return false;
        if (b.upper_bound(*t) != b.end()) {
            element_swap(a, b, i);
            element_swap(a, b, i + 1, a[i]);
            remain(a, b, i + 2);
            return true;
        }
    }
    return false;
}
vi cal(vi a) {
    int n = a.size();
    set<int> b;
    for (int i = n; i--;) {
        if (change(a, b, i)) {
            // for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
            // cout << i << '\n';
            break;
        }
        b.insert(a[i]);
    }
    if (!test(a)) a = smallest(n);
    return a;
}
void all_config(int n) {
    vi a(n);
    iota(a.begin(), a.end(), 1);
    while (next_permutation(a.begin(), a.end())) {
        if (test(a))
            for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
    }
}
bool equal(vi &a, vi &b) {
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) return false;
    return true;
}
void check(int n) {
    vi a(n);
    iota(a.begin(), a.end(), 1);
    a = bruteforce(a);

    vi b = a;
    vi c = a;
    int cnt = 0;

    do {
        print("count", ++cnt);
        vi o = b;
        b = bruteforce(o);
        c = cal(o);

        if (!equal(b, c)) {
            print("WA");
            for (int i = 0; i < n; ++i) cout << o[i] << " \n"[i == n - 1];
            for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n - 1];
            for (int i = 0; i < n; ++i) cout << c[i] << " \n"[i == n - 1];
            return;
        }
    } while (!equal(b, a));
}
void solve() {
    // check(8);

    // all_config(10);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // vi b = bruteforce(a);
    // for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n - 1];

    vi c = cal(a);
    if (equal(c, a)) c = smallest(n);
    for (int i = 0; i < n; ++i) cout << c[i] << " \n"[i == n - 1];

    // print(test(b), test(c));
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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