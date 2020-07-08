#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

vector<bool> in(1000, false);
vector<bool> forbid(1000, false);

ii chose(int n) {
    int res = 0, cnt = 0;
    for (int i = 2; i < n; ++i) {
        int get = 0;
        if (n % i == 0) {
            int x = n / i;
            get = (x - 1) * (i - 1);
        } else {
            int x = n / i;
            get = (x - 1) * (i - 1) + n % i - 1;
        }
        if (cnt < get) {
            res = i;
            cnt = get;
        }
    }
    return ii{res, cnt};
}
void move() {}
void solve() {
    int n;
    cin >> n;

    int k = chose(n).fi;
    if (k == 0) {
        write(0);
        return;
    }

    for (int i = k - 1; i < n; i += k) forbid[i] = true;
    forbid[n - 1] = true;

    vi a(1000);
    while (1) {
        int change = 0;

        int j = 0;
        for (int i = 0; i < n; ++i)
            if (!in[i] && !forbid[i]) a[j++] = i;

        if (j < k) break;

        cout << k << ' ';
        for (int i = 0; i < k; ++i) {
            cout << a[i] + 1 << " \n"[i == k - 1];
            in[a[i]] = true;
        }
        cout.flush();

        int rep;
        cin >> rep;
        if (rep == -1) return;

        rep--;
        for (int i = 0; i < k; ++i) in[(rep + i) % n] = false;
    }
    write(0);
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}
