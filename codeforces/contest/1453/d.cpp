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
#define debug(x) cerr << #x << ' ' << x << '\n'
#define prt(u) \
    for (auto& i : u) cout << i << " \n"[&i == &u.back()];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    ll k;
    cin >> k;
    
    if(k & 1){ print(-1); return; }
    
    k >>= 1;
    
    vi res;
    
    ll add = 60;
    while(add){
        if(k >= (1LL << add) - 1){
            res.push_back(add);
            k -= (1LL << add) - 1;
        }
        add--;
    }
    while(k){
        res.push_back(1);
        k--;
    }
    
    int cnt=0;
    for(auto&i:res)cnt+=i;
    
    print(cnt);
    for(auto&i:res){
        i--;
        cout<< "1" << " \n"[(i == 0) && (&i == &res.back())];;
        while(i--)cout << "0" << " \n"[(i == 0) && (&i == &res.back())];
    }
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
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}
