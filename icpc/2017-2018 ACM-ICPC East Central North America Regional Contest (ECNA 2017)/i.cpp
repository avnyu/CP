#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int n = 4;
const int M = 1e9+7;
vi v(4);
vi pv(4);
vi tv(4);
vi o(3);
vi po(3);
vi pri={0,0,1,1};
vi u(4);
int cnt = 0;

int nghichthe(){
	int res = 0;
	for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)res += pv[i] > pv[j];
	return res;
}
int check(){
	cnt++;
	int cost = 2 * nghichthe();
	int val = 0;
	
	if(pri[o[po[0]]] < pri[o[po[1]]])cost++;
	if(pri[o[po[1]]] < pri[o[po[2]]])cost++;
	
	for(int i=0;i<n;++i)u[i] = 0;
	for(int i=0;i<n;++i)tv[i] = v[pv[i]];
	
	
	
	return val == 24 ? cost : M;
}
int cal(){
	iota(all(pv),0);
	iota(all(po),0);
	int res = M;
	
	do{
		do{
			res=min(res, check());
		}while(next_permutation(all(po)));
	}while(next_permutation(all(pv)));
	
	return res;
}
int dfs(int p=0){
	if(p==3){
		return cal();
	}
	int res=M;
	for(int i=0;i<4;++i){
		o[p] = i;
		res = min(res, dfs(p+1));
	}
	return res;
}
void solve() {
	for(int i=0;i<n;++i)cin >> v[i];
	
	int res=dfs();
	
	if(res == M)print("impossible");
	else print(res);
	
	print(cnt);
}
int main() {
    //ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	//clock_t time_start = clock();
	
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    //print("Time:", (clock() - time_start) / 1000);

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
