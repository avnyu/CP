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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

int ask(string s, int i, int j){
    cout << s << ' ' << i << ' ' << j << endl;
    int t;
    cin >> t;
    return t;
}
void solve(int T) {
    int n;
    cin >> n;
    
    int x1 = ask("xor", 1, 2);
    int x2 = ask("xor", 2, 3);
    int x3 = ask("xor", 3, 4);
    vi a(4), g(4), cnt(2);
    
    for(int i=0;i<16;++i){
        g[0] = 0;
        g[1] = x1 & 1 << i ? 1 - g[0] : g[0];
        g[2] = x2 & 1 << i ? 1 - g[1] : g[1];
        g[3] = x3 & 1 << i ? 1 - g[2] : g[2];
        
    }
    for(int i=4;i<n;++i)a[i]=a[i-1]^ask("xor",i,i+1);
    cout<<"! ";
    for(int i=0;i<n;++i)cout<<a[i]<<" \n"[i==n-1];
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    //cin >> t;
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
