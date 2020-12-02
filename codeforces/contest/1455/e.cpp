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

vii a(4, {0,0});
vi hor(4), ver(4);
vi h(2), v(2);

ll cal(vii &p, int d){
    a[1].fi = a[2].se = a[3].fi = a[3].se = d;
    h[0] = h[1] = v[0] = v[1] = 2e9;
    
    for(int i=0;i<4;++i){
        hor[i] = a[i].fi - p[i].fi;
        ver[i] = a[i].se - p[i].se;
        
        if(hor[i] < h[0]){
            h[1] = h[0];
            h[0] = hor[i];
        }else if(hor[i] < h[1])
            h[1] = hor[i];
            
        if(ver[i] < v[0]){
            v[1] = v[0];
            v[0] = ver[i];
        }else if(ver[i] < v[1])
            v[1] = ver[i];
    }
    
    ll h1 = 0, v1 = 0;
    for(int i=0;i<4;++i){
        h1 += abs(hor[i] - h[1]);
        v1 += abs(ver[i] - v[1]);
    }
    
    return h1 + v1;
}
void solve(int T) {
    vii p(4), best;
    for (auto &[x,y]:p)cin>>x>>y;
    sort(p.begin(), p.end());
    
    
    ll res = 1e18;
    do{
        ll t = cal(p, 1e9);
        if(t < res){
            res = t;
            best = p;
        }
    }while(next_permutation(p.begin(), p.end()));
    
    p = best;
    
    int l = 0, add = 1 << 30;
    while(add){
        ll t1 = cal(p, l + add);
        ll t2 = cal(p, l + add + 1);
        
        if(t2 <= t1)l += add;
        
        add >>= 1;
    }
    res = min(res, min(cal(p, l), cal(p, l + 1)));
    
    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
