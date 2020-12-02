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
#define vc vector<char>
#define vvc vector<vc>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const string s = "A23456789DQJK";
vi v(128), w(13);
vvc a(13);

void solve(int T) {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<13;++i)v[s[i]]=i;
    
    --k;
    w[k] = 1;
    
    int win=-1, val=20;
    for(int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            char c;
            cin >> c;
            a[i].push_back(c);
        }
        if(i != k && a[i][0] == a[i][1] && a[i][0] == a[i][2] && a[i][0] == a[i][3]){
            if(win == -1 || v[a[i][0]] < val){
                win = i;
                val = v[a[i][0]];
            }
        }
    }
    
    if(win!=-1){
        print(win+1);
        return;
    }
    
    for(int i = k;;i=(i+1)%n){
        if(w[i]==1)w[i]++;
        else if(w[i]==2){
            w[(i+1)%n] = 1;
            w[i] = 0;
            // cout << i + 1 << " wildcard" << endl;
            if(a[i].size() == 4 && a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == a[i][3]){
                print(i+1);
                return;
            }
            continue;
        }
        
        auto cntval=[&](char ct){
            int res = 0;
            for(auto&c:a[i])res += c == ct;
            return res;
        };
        int cnt = 10;
        for(auto&ct:a[i]){
            int t = cntval(ct);
            if(t == 4 && w[i] == 0){
                print(i + 1);
                return;
            }
            cnt = min(cnt, cntval(ct));
        }
        
        int p = -1;
        for(int j=0;j<int(a[i].size());++j)
            if(cntval(a[i][j])==cnt && (p == -1 || v[a[i][j]] < v[a[i][p]]))
                p = j;
        
        swap(a[i][p], a[i].back());
        // cout << i + 1 << " " << a[i].back() << endl;
        
        a[(i+1)%n].push_back(a[i].back());
        a[i].pop_back();
    }
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
