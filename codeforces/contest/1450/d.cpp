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

void bruteforce(vi a){
    int n = a.size();
    vi res(n);
    for(int k=0;k++<n;){
        for(int i=0;i+k<=n;++i){
            
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vi a(n), cnt(n + 1, 0);
    for(auto&i:a)cin >> i;
    
    for(auto&i:a)cnt[i]++;
    
    vi res(n,0);
    
    res[0]=1;
    for(int i=0;i++<n;)if(cnt[i]!=1)res[0]=0;
    
    if(cnt[1])res[n-1]=1;
    
    int l=0,r=n-1;
    for(int i=1;i<n-1;++i){
        if(a[l]==i){
            cnt[i]--;
            l++;
        }else if(a[r]==i){
            cnt[i]--;
            r--;
        }else break;
        
        if(cnt[i])break;
        res[n-i-1]=1;
    }
    
    for(auto&i:res)cout<<i;
    cout<<'\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
