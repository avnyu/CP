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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

struct trie {
    vector<trie*> nxt;
    trie() : nxt(26) {}
    trie* add(char c) {
        if (!nxt[c - 'a']) nxt[c - 'a'] = new trie;
        return nxt[c - 'a'];
    }
    int cnt() {
        int res = 1;
        for (int i = 0; i < 26; ++i)
            if (nxt[i]) res += nxt[i]->cnt();
        return res;
    }
    void travel(int h = 1) {
        print(h);
        for (int i = 0; i < 26; ++i)
            if (nxt[i]) {
                print(char('a' + i));
                nxt[i]->travel(h + 1);
            }
    }
};
void solve() {
    string s, t;
    int k;
    cin >> s >> t >> k;

    int n = s.size(), sav = k;

    trie* r = new trie;
    for (int i = 0; i < n; ++i) {
        trie* x = r;
        k = sav;
        int j = i;
        while (j < n && k - ('1' - t[s[j] - 'a']) >= 0) {
            k -= ('1' - t[s[j] - 'a']);
            x = x->add(s[j]);
            j++;
        }

        k += '1' - t[s[i] - 'a'];
    }

    print(r->cnt() - 1);

    // r->travel();
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
        cout << x << '\n';
    }
}