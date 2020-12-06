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
#define lcm(a, b) (long long) a / __gcd(a, b) * b
#define debug(x) cerr << #x << ' ' << x << '\n'
#define prt(u) \
    for (auto& i : u) cout << i << " \n"[&i == &u.back()];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    const ll N = 1e10;
    int n;
    string s;
    cin >> n >> s;
    
    if(n == 1){
        print(s == "1" ? N * 2 : N);
        return;
    }else if(n == 2){
        if(s == "11")print(N);
        else if(s == "10")print(N);
        else if(s == "01")print(N - 1);
        else print(0);
        return;
    }
    
    string t = "";
    while((int)t.size() < n + 3) t += "110";
    
    if(s == t.substr(0, n)){
        ll l = 0, add = 1LL << 60;
        while(add){
            if(l + add + n <= N * 3)l += add;
            add >>= 1;
        }
        print(l / 3 + 1);
    }else if(s == t.substr(1, n)){
        ll l = 0, add = 1LL << 60;
        while(add){
            if(l + add + n + 1 <= N * 3)l += add;
            add >>= 1;
        }
        print(l / 3 + 1);
    }else if(s == t.substr(2, n)){
        ll l = 0, add = 1LL << 60;
        while(add){
            if(l + add + n + 2 <= N * 3)l += add;
            add >>= 1;
        }
        print(l / 3 + 1);
    }else print(0);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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
