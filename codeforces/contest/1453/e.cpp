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

vvi g, h;
vi a, pas;


int dfs(int u = 1){
    if(pas[u]) return -1;
    pas[u] = 1;
    
    
    for(auto&v:g[u]){
        int t = dfs(v);
        if(t==-1)continue;
        
        h[u].push_back(t);
        
        a[u] = max(a[u], a[v]);
    }
    sort(h[u].begin(), h[u].end());
    
    if(h[u].empty()){
        a[u] = 0;
        return 1;
    }
    if(h[u].size() == 1){
        a[u] = max(a[u], h[u][0]);
        return h[u][0] + 1;
    }
    if(u != 1){
        a[u] = max(a[u], h[u].back() + 1);
        return h[u][0] + 1;
    }
    a[u] = max(a[u], h[u].back());
    a[u] = max(a[u], h[u][h[u].size() - 2] + 1);
    return 0;
}
void solve() {
    int n;
    cin >> n;
    
    g.assign(n + 1, vi());
    h.assign(n + 1, vi());
    a.assign(n + 1, 0);
    pas.assign(n + 1, 0);
    
    for(int i=1;i<n;++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs();
    
    print(a[1]);
    //for(int i=0;i++<n;)print(i, a[i]);
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
