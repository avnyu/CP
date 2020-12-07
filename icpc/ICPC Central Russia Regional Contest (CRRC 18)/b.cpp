#include <bits/stdc++.h>

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
#define lcm(a, b) (long long)a / __gcd(a, b) * b
#define debug(x) cerr << #x << ' ' << x << '\n'
#define prt(u) \
    for (auto &i : u) cout << i << " \n"[&i == &u.back()];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 5e2 + 7;
vi par(N * N, -1);

int root(int u){return par[u] < 0 ? u : par[u] = root(par[u]);};
int merge(int u, int v){
    u=root(u), v=root(v);
    if(u==v)return u;
    par[u] = min(par[u], par[v]);
    return par[v]=u;
}
int key(int u, int v){return u * N + v;}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vvi a(n + 2, vi(n + 2, 0));
    
    for(int i=0;i<n+1;++i){
        merge(key(i, 0), key(i + 1, 0));
        merge(key(i, n + 1), key(i + 1, n + 1));
        merge(key(0, i), key(0, i + 1));
        merge(key(n + 1, i), key(n + 1, i + 1));
        
        a[i][0] = a[i + 1][0] = 1;
        a[i][n + 1] = a[i + 1][n + 1] = 1;
        a[0][i] = a[0][i + 1] = 1;
        a[n + 1][i] = a[n + 1][i + 1] = 1;
    }
    
    
    int u, v, u2, v2;
    for(;m--;){
        cin >> u >> v;
        u++, v++;
        
        par[key(u, v)] = -2;
        a[u][v] = 1;
        
        for(int i=-1;i<2;i+=2){
            u2 = u + i, v2 = v + i;
            if (a[u2][v]) merge(key(u2, v), key(u, v));
            if (a[u][v2]) merge(key(u, v2), key(u, v));
        }
    }
    
    for(int i=0;i<k;++i){
        if (par[root(key(0, 0))] == -2){
            print(i);
            return;
        }
        cin >> u >> v;
        u++, v++;
        
        a[u][v] = 1;
        
        for(int j=-1;j<2;j+=2){
            u2 = u + j, v2 = v + j;
            if (a[u2][v]) merge(key(u2, v), key(u, v));
            if (a[u][v2]) merge(key(u, v2), key(u, v));
        }
    }
    print(k);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
        cout << x << endl;
    }
}
