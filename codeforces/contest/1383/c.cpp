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

int cnt=0;
int cal(vvi &req, vi &per) {
    for(int i=0;i<per.size();++i)cout<<per[i]<<" \n"[i==per.size()-1];
    int res = 0;
    // for (int i = 0; i < 20; ++i)
    //     for (int j = i + 1; j < 20; ++j)
    //         if (req[per[i]][per[j]]) {
    //             res++;
    //             for (int k = j + 1; k < 20; ++k) {
    //                 req[per[j]][per[k]] += req[per[i]][per[k]];
    //                 req[per[i]][per[k]] = 0;
    //             }
    //             break;
    //         }
    return res;
}
void solve() {
    print(1);
    int n;
    string a, b;
    cin >> n >> a >> b;

    vvi req(20, vi(20));
    for (int i = 0; i < n; ++i) req[a[i] - 'a'][b[i] - 'a']++;

    vi per(10);
    iota(all(per), 0);

    int res = 20;
    while (1) {
        res = min(res, cal(req, per));
        if (!next_permutation(all(per))) break;
    }

    print(res);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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