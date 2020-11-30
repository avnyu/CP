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

const int M = 1e9;
vvi per;

void init(){
    vi a={0,1,2,3};
    do{
        per.push_back(a);
    }while(next_permutation(a.begin(),a.end()));
}
ll dis(ii &a, ii &b){
    return abs(a.fi-b.fi)+abs(a.se-b.se);
}
ll ts(vii&p, ll x, ll y, ll d){
    vii t(4);
    t[0] = {x,y};
    t[1] = {x+d,y};
    t[2] = {x,y+d};
    t[3] = {x+d,y+d};
    
    ll res=1e18;
    for(auto&pi:per){
        ll cur = 0;
        for(int i=0;i<4;++i)cur+=dis(t[i], p[pi[i]]);
        res=min(res, cur);
    }
    return res;
}
ll ts(vii &p, ll x, ll y){
    ll l=0,r=M, res=1e18;
    while(l<=r){
        ll m1=(l+l+r)/3;
        ll m2=(l+r+r)/3;
        ll t1 = ts(p, x, y, m1);
        ll t2 = ts(p, x, y, m2);
        if(t1 > t2){
            res = min(res, t1);
            l = m1 + 1;
        }else{
            res = min(res, t2);
            r = m2 - 1;
        }
    }
    return res;
}
ll ts(vii &p, ll x){
    ll l=0,r=M, res=1e18;
    while(l<=r){
        ll m1=(l+l+r)/3;
        ll m2=(l+r+r)/3;
        ll t1 = ts(p, x, m1);
        ll t2 = ts(p, x, m2);
        if(t1 > t2){
            res = min(res, t1);
            l = m1 + 1;
        }else{
            res = min(res, t2);
            r = m2 - 1;
        }
    }
    return res;
}
ll ts(vii &p){
    ll l=0,r=M,res=1e18;
    while(l<=r){
        ll m1=(l+l+r)/3;
        ll m2=(l+r+r)/3;
        ll t1 = ts(p, m1);
        ll t2 = ts(p, m2);
        if(t1 > t2){
            res = min(res, t1);
            l = m1 + 1;
        }else{
            res = min(res, t2);
            r = m2 - 1;
        }
    }
    return res;
}
void solve(int T) {
    vii p(4);
    for(auto&[x,y]:p)cin>>x>>y;
    
    print(ts(p));
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();
    int t = 1;
    cin >> t;
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
