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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e6 + 7;
vi pri(N);

void init(){
    iota(pri.begin(), pri.end(), 0);
    for(int i=2;i<N;++i)
        if(pri[i] == i)
            for(int j=i+i;j<N;j+=i)pri[j] = i;
}
void solve(int T) {
    init();
    
    int n;
    cin >> n;
    vi a(n);
    for (auto&i:a) cin >> i;
    /*
    print(n);
    prt(a);
    */
    vvi pos(N);
    vi cnt(n);
    set<int>s;
    ll res = 0;
    
    for(int i=0;i<n;++i){
        //print("ai");
        for(int t=a[i];t>1;){
            //cout << pri[t] << ' ';
            pos[pri[t]].push_back(i);
            s.insert(pri[t]);
            for(int k=pri[t];t%k==0;)t /= k;
        }
        //print();
        cnt[i] = s.size();
        res += cnt[i];
    }
    /*
    for(int i=0;i<N;++i)
        if(pos[i].size()){
            print(i);
            prt(pos[i]);
        }
    */
    // prt(cnt);
    
    for(int i=0;i<N;++i)pos[i].push_back(n);
    ll add = res;
    //print("res", res);
    for(int i=0;i<n;++i){
        for(int t=a[i];t>1;){
            add -= pos[pri[t]][ub(pos[pri[t]], i)] - i;
            // print("rem add", pri[t], pos[pri[t]][ub(pos[pri[t]], i)] - i);
            for(int k=pri[t];t%k==0;)t /= k;
        }
        // print("add", add);
        res += add;
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
