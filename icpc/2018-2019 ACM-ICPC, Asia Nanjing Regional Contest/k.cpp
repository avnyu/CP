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
#define prt(vec) for(auto&ele:vec)cout<<ele<<" \n"[&ele == &vec.back()]
#define ub(vec, u) upper_bound(vec.begin(), vec.end(), u) - vec.begin()
#define viii vector<tuple<int, int, int>>
#define vc vector<char>
#define vvc vector<vc>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 50;
vvi g(N * N);
vi res, pas(N * N);

void dfs(int u){
    for(auto&v:g[u])
        if(!pas[v]){
            pas[v] = 1;
            res.push_back(v-u);
            dfs(v);
            res.push_back(u-v);
        }
}
void solve(int T) {
    int n, m;
    cin >> n >> m;
    vvc a(n, vc(m));
    for(auto&i:a)for(auto&j:i)cin>>j;
    
    
    
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        if(a[i][j]=='1' && i<n-1 && a[i+1][j]=='1'){
            g[i*N+j].push_back(i*N+j + N);
            g[i*N+j + N].push_back(i*N+j);
        }
        if(a[i][j]=='1' && j<m-1 && a[i][j+1]=='1'){
            g[i*N+j].push_back(i*N+j + 1);
            g[i*N+j + 1].push_back(i*N+j);
        }
    }

    for(int i=0;i<n;++i)for(int j=0;j<m;++j)
        if(a[i][j]=='1'){
            pas[i*N+j]=1;
            dfs(i*N+j);
            break;
        }
    
    int num = res.size();
    for(int i = 0; i < 50000; ++i)
        if(res[i % num] == N)cout << "D";
        else if(res[i % num] == -N)cout << "U";
        else if(res[i % num] == 1)cout << "R";
        else cout<<"L";
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
