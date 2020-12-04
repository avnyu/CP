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
    int n;
    cin >> n;
    vector<vector<char>>a(n, vector<char>(n));
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
    
    vvii row(10, vii(2002, {-1, -1}));
    vvii col(10, vii(2002, {-1, -1}));
    
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        int c = a[i][j] - '0';
        
        row[c][j].fi = row[c][j].fi == -1 ? i : min(i, row[c][j].fi);
        row[c][j].se = row[c][j].se == -1 ? i : max(i, row[c][j].se);
        
        col[c][i].fi = col[c][i].fi == -1 ? j : min(j, col[c][i].fi);
        col[c][i].se = col[c][i].se == -1 ? j : max(j, col[c][i].se);
        
    } 
    
    for(int i=0;i<10;++i){
        int res = 0;
        
        for(int j1=0;j1<n;++j1)
            for(int j2=0;j2<n;++j2){
                if (row[i][j1].fi == -1 || row[i][j2].fi == -1)continue;
                
                if(j1 == j2)res = max(res, max(j1, n - 1 - j1) * (row[i][j1].se - row[i][j1].fi));
                else{
                    int w = abs(j2 - j1);
                    int d1 = max(row[i][j1].se, n - 1 - row[i][j1].fi);
                    int d2 = max(row[i][j2].se, n - 1 - row[i][j2].fi);
                    res = max(res, w * max(d1, d2));
                }
            }

        for(int j1=0;j1<n;++j1)
            for(int j2=0;j2<n;++j2){
                if (col[i][j1].fi == -1 || col[i][j2].fi == -1)continue;
                
                if(j1 == j2)res = max(res, max(j1, n - 1 - j1) * (col[i][j1].se - col[i][j1].fi));
                else{
                    int w = abs(j2 - j1);
                    int d1 = max(col[i][j1].se, n - 1 - col[i][j1].fi);
                    int d2 = max(col[i][j2].se, n - 1 - col[i][j2].fi);
                    res = max(res, w * max(d1, d2));
                }
            }
        
        cout << res << " \n"[i == 9];
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
