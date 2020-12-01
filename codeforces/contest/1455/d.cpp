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

void solve(int T) {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (auto&i:a) cin>>i;
    /*
    print(n, x);
    prt(a);
    */
    int l = 0, r = 0, cnt = 0;
    while(l < n){
        if(x < a[l]){
            r = l + 1;
            while(r < n && a[r - 1] <= a[r])r++;
            
            if(r == n)break;
            
            while(l < r){
                swap(a[l], x);
                if(a[l] != x)cnt++;
                l++;
            }
            l = r;
        }else l++;
    }
    
    for(int i=0;i<n-1;++i)if(a[i]>a[i+1]){
        print(-1);
        return;
    }
    print(cnt);
}
int main() {
    //ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
