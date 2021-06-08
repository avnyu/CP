#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

vector<string> dic;

void init() {
    for (char c = 'a'; c <= 'z'; ++c) {
        string s = "";
        s.push_back(c);
        dic.push_back(s);
    }
    for (char c1 = 'a'; c1 <= 'z'; ++c1)
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            string s = "";
            s.push_back(c1);
            s.push_back(c2);
            dic.push_back(s);
        }
    for (char c1 = 'a'; c1 <= 'z'; ++c1)
        for (char c2 = 'a'; c2 <= 'z'; ++c2)
            for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                string s = "";
                s.push_back(c1);
                s.push_back(c2);
                s.push_back(c3);
                dic.push_back(s);
                if (dic.size() == 1010) break;
            }
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto& c : dic) {
        if (s.find(c) == string::npos) {
            print(c);
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
    for (int i = 0; i++ < t;) solve();

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