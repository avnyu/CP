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
#define viii vector<tuple<int,int,int>>
#define vc vector<char>
#define vvc vector<vc>
#define iii tuple<int,int,int>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

struct twosat{
	int n;
	// gt is g with edge reversed
	vector<vector<int>> g, gt;
	vector<bool> used;
	vector<int> order, comp;
	vector<bool> assignment;

	void dfs1(int v) {
		used[v] = true;
		for (int u : g[v]) if (!used[u]) dfs1(u);
		order.push_back(v);
	}
	void dfs2(int v, int cl) {
		comp[v] = cl;
		for (int u : gt[v]) if (comp[u] == -1) dfs2(u, cl);
	}
	bool solve_2SAT() {
		used.assign(n, false);
		for (int i = 0; i < n; ++i) if (!used[i]) dfs1(i);

		comp.assign(n, -1);
		for (int i = 0, j = 0; i < n; ++i) {
			int v = order[n - i - 1];
			if (comp[v] == -1) dfs2(v, j++);
		}

		assignment.assign(n / 2, false);
		for (int i = 0; i < n; i += 2) {
			if (comp[i] == comp[i + 1]) return false;
			assignment[i / 2] = comp[i] > comp[i + 1];
		}
		return true;
	}
};
void solve(int T) {
	int k, n;
	cin >> k >> n;
	
	twosat a;
	a.g.resize(k << 1);
	a.gt.resize(k << 1);
	a.n = k << 1;
	
	vi pos(3), val(3);
	char c;
	
	for(int i=0;i<n;++i){
		for(int j=0;j<3;++j){
			cin >> pos[j] >> c;
			pos[j]--;
			val[j] = c == 'R';
		}
		
		for(int u=0;u<3;++u)
			for(int v=0;v<3;++v) if (u!=v){
				a.g[pos[u] << 1 | !val[u]].push_back(pos[v] << 1 | val[v]);
				a.gt[pos[v] << 1 | val[v]].push_back(pos[u] << 1 | !val[u]);
			}
	}
	
	if(!a.solve_2SAT()){
		print(-1);
		return;
	}

	for(auto i:a.assignment)cout<<(i?'B':'R'); 
	cout<<'\n';
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
