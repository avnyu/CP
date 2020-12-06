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
    int n;
    cin >> n;
    vi a(n), pos(n), used(n), res;
    for(int i=0;i<n;++i){
        cin >> a[i];
        a[i]--;
        pos[a[i]]=i;
    }
    
    for(int i=n;i--;){
        while(pos[i] != i){
            if(used[pos[i]]){
                print(-1);
                return;
            }
            int p = pos[i];
            swap(a[p], a[p+1]);
            pos[a[p]] = p;
            pos[a[p+1]] = p+1;
            used[p]=1;
            res.push_back(p+1);
        }
    }
    if((int)res.size() != n-1){
        print(-1);
        return;
    }
    for(auto&p:res)print(p);
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
