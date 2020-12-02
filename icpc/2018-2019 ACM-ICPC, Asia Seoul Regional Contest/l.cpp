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

void solve(int T) {
	int m, n, w, h;
	cin >> m >> n >> w >> h;
	vi a(m), d(n);
	for(auto&i:a)cin>>i;
	for(auto&i:d)cin>>i;
	
	vi pre(n + 1), need(n);
	
	int cur=0;
	for(int i=0;i<n;++i){
		cur+=pre[i];
		
		need[i]+=d[i]-cur;
		
		pre[i+1]+=d[i]-cur;
		pre[i+w]-=d[i]-cur;
	}
	
	// for(int i=0;i<n;++i)cout<<need[i]<<" \n"[i==n-1];
	
	priority_queue<ii>pq;
	for(int i=0;i<m;++i)pq.push(ii{a[i]/w,i});
	
	priority_queue<iii>out;
	
	vvi res(m);
	for(int i=0;i<n;++i){
		while(out.size()){
			auto [req, rem, id] = out.top();
			
			if(-req == i){
				// print("return", id);
				pq.push(ii{rem, id});
				out.pop();
			}else break;
		}
		
		while(pq.size() && need[i]){
			auto t = pq.top();	pq.pop();
			need[i]--;
		
			// print("assign", i, t.se);
			res[t.se].push_back(i);
			if(t.fi>1)out.push(iii{-i-w-h,t.fi-1,t.se});
		}
		
		if(need[i]){
			print(-1);
			return;
		}
	}
	
	print(1);
	for(auto&i:res)for(auto&j:i)cout<<j+1<<" \n"[&j == &i.back()];
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
