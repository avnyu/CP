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
#define prt(u)                                                                 \
    for (auto &i : u) cout << i << " \n"[&i == &u.back()];

using namespace std;

void print();
template <typename T, typename... Args> void print(T x, Args... args);

int val(char c) {
    if ('a' <= c && c <= 'z') return (c - 'a') * 2 + 1;
    if ('A' <= c && c <= 'Z') return (c - 'A') * 2;
    return -1;
}
bool cmp(string a, string b) {
    a += '!';
    b += '!';
    for (int i = 0; i < (int)min(a.size(), b.size()); ++i)
        if (val(a[i]) < val(b[i])) 
            return true;
        else if(val(a[i]) > val(b[i])) 
            return false;
    return false;
}
void solve() {
    string s;
    cin >> s;

    map<string, int> cnt;

    stack<int> st;
    st.push(1);
    st.push(1);

    for (int l = 0, r = 0;; ++r) {
        if (r == (int)s.size()) {
            if (l != r) cnt[s.substr(l, r - l)] += st.top();
            break;
        } else if (s[r] == '*') {
            if (l != r) cnt[s.substr(l, r - l)] += st.top();
            st.pop();
            st.push(st.top());
            l = r + 1;
        } else if (s[r] == '/') {
            if (l != r) cnt[s.substr(l, r - l)] += st.top();
            st.pop();
            st.push(st.top() * -1);
            l = r + 1;
        } else if (s[r] == '(') {
            l++;
            st.push(st.top());
        } else if (s[r] == ')') {
            if (l != r) cnt[s.substr(l, r - l)] += st.top();
            l = r + 1;
            st.pop();
        }
    }
    vector<string> num, den;
    for (auto &[k, v] : cnt) {
        if (v == 0)
            continue;
        else if (v > 0)
            for (; v--;) num.push_back(k);
        else
            for (; v++;) den.push_back(k);
    }

    sort(num.begin(), num.end(), cmp);
    sort(den.begin(), den.end(), cmp);

    if (num.empty())
        print(1);
    else
        for (auto &i : num) cout << i << "*\n"[&i == &num.back()];

    if (den.empty())
        print(1);
    else
        for (auto &i : den) cout << i << "*\n"[&i == &den.back()];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args> void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}
