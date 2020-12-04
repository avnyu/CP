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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

vvi manacher_cp_algo(string s){
	int n = s.size();
	vvi d(2, vi(n));
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d[0][l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d[0][i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d[1][l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d[1][i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	return d;
}
vvi manacher(string s) {
    int n = s.size(), m;
    vvi d(2, vi(n, 0));
    m = 0;
    for (int i = 0; i < n; ++i) {
        d[0][i] = m + d[0][m] > i ? min(d[0][m + m - i], m + d[0][m] - i) : 0;
        while (i - d[0][i] - 1 >= 0 && i + d[0][i] + 1 < n && s[i - d[0][i] - 1] == s[i + d[0][i] + 1]) d[0][i]++;
        if (i + d[0][i] > m + d[0][m]) m = i;
    }
    m = 0;
    for (int i = 0; i < n; ++i) {
        d[1][i] = m + d[1][m] > i ? min(d[1][m + m - i - 1], m + d[1][m] - i) : 0;
        while (i - d[1][i] - 1 >= 0 && i + d[1][i] < n && s[i - d[1][i] - 1] == s[i + d[1][i]]) d[1][i]++;
        if (i + d[1][i] > m + d[1][m]) m = i;
    }
    return d;
}
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
void solve(int T) {
	string s, t;
	cin >> s >> t;
	
	int n = s.size(), m = t.size();
	vi w(n + 1);
	auto d = manacher_cp_algo(s);
	
	for(int i=0;i<n;++i){
		d[0][i]--;
		
		w[i - d[0][i]]++;
		w[i + 1]--;
		w[i - d[1][i]]++;
		w[i]--;
	}
	for(int i=1;i<n;++i) w[i] += w[i-1];
	
	reverse(s.begin(), s.end());
	s = t + s;
	
	auto z = z_function(s);
    
    ll res = 0;
    for(int i = m + 1; i < n + m; ++i){
        int p = i - m - 1;
        p = n - 1 - p;
        res += 1LL * w[p] * min(z[i], m);
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
