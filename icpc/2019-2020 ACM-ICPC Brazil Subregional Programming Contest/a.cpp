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

const int K = 1e3 + 7;
vi par(K, -1);

int root(int u){return par[u]<0?u:par[u]=root(par[u]);}
void merge(int u, int v){
    u=root(u),v=root(v);
    if(u==v)return;
    par[v]=u;
}
int dis2(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
void solve(int T) {
    int m, n, k;
    cin >> m >> n >> k;
    viii a(k);
    for(auto &[x,y,s]:a)cin>>x>>y>>s;
    
    for(int i=0;i<k;++i)for(int j=i;j<k;++j){
        auto &[x1,y1,s1] = a[i];
        auto &[x2,y2,s2] = a[j];
        
        if(dis2(x1,y1,x2,y2) <= (s1+s2)*(s1+s2))merge(i, j);
        
        if(s1 >= x1 || s1 >= n-y1)merge(i, K - 1);
        if(s2 >= x2 || s2 >= n-y2)merge(j, K - 1);
        
        if(s1 >= m-x1 || s1 >= y1)merge(i, K - 2);
        if(s2 >= m-x2 || s2 >= y2)merge(j, K - 2);
    }
    
    print(root(K-1)==root(K-2) ? "N" : "S");
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
