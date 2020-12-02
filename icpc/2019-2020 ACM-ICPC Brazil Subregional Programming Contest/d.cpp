#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define viii vector<tuple<int,int,int>>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e5+7;
vvi g(N);
vii bst(N, {-1, -1});
vi pas(N), par(N);

ii dfs(int u){
    bst[u]={1,u};
    for(auto&v:g[u]){
        auto pv=dfs(v);
        bst[u]=max(bst[u], ii{pv.fi+1,pv.se});
    }
    return bst[u];
}
void solve(int T) {
    int n, k;
    cin >> n >> k;
    for(int i=1;i++<n;){
        cin >> par[i];
        g[par[i]].push_back(i);
    }
    par[1] = 0;
    pas[0] = 1;
    
    dfs(1);
    priority_queue<ii>pq;
    pq.push(bst[1]);
    
    int res = 0;
    for(;pq.size() && k--;){
        ii h = pq.top();
        pq.pop();
        
        res += h.fi;
        
        for(int u=h.se;!pas[u];u=par[u]){
            pas[u] = 1;
            for(auto&v:g[u]){
                if(pas[v])continue;
                
                pq.push(bst[v]);
            }
        }
            
    }
    
    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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
