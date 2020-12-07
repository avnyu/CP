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

const vi s4 = {2, 0, 2 ,0};
const vi s5 = {2, 1, 2, 0, 0};

void solve() {
    int k, n;
    cin >> k >> n;
    vi a(n);
    for(auto&i:a)cin>>i;
    
    if(k < 4 || k == 6){
        print(0);
        return;
    }
    
    if(k == 4)
        for(auto&i:a)i=s4[i];
    else if(k == 5)
        for(auto&i:a)i=s5[i];
    else
        for(auto&i:a){
            if (i == 0) i = k - 4;
            else if(i == 1) i = 2;
            else if(i == 2) i = 1;
            else if(i == k - 4) i = 1;
            else i = 0;
        }
    
    print(n);
    prt(a);
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
