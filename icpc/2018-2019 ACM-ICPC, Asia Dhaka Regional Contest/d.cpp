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
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define debug(x) cerr << #x << ' ' << x << '\n'
#define prt(vec) \
    for (auto& vt : vec) cout << setw(2) << vt << " \n"[&vt == &vec.back()];
#define iii tuple<int,int,int>
#define pb push_back

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 9;
const int M = 28;
const vi val = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int nrs;
vi pos(M), pool(N);
vvi conf(M), reg(N, vi(N, 1e9));
vi res(1e6);

vi cal_pool(int t){
	vi p(N, 0);
	for(int j=2;j<=t;++j){
		int k=j;
		for(auto&v:val){
			while(k%v==0){
				k/=v;
				p[pos[v]]++;
			}
			if(k==1)break;
		}
	}
	return p;
}
void init(){
	nrs = 0;
	for(int i=2;i<24;++i){
		int t = lower_bound(val.begin(), val.end(), i) - val.begin();
		if(val[t] == i)pos[i] = t;
	}
	for(int i=2;i<M;++i)conf[i] = cal_pool(i);
	for(int i=2;i<M;++i)
		for(int j1=0;j1<N;++j1)
			for(int j2=j1+1;j2<N;++j2)
				if(conf[i][j2])reg[j1][j2] = min(reg[j1][j2], conf[i][j1] / conf[i][j2]);
}
bool test(){
	for(int i=0;i<N;++i)if(pool[i]<0)return false;
	for(int j1=0;j1<N;++j1)
		for(int j2=j1+1;j2<N;++j2)
			if(pool[j1] < reg[j1][j2] * pool[j2])return false;
	return true;
}
bool check(){
	for(int i=0;i<N;++i)if(pool[i] != 0)return false;
	return true;
}
bool bruteforce(int p=2){
	if (p == M) return check();
	for(int i=pool[0] / conf[p][0] + 1;i--;){
		
		for(int j=0;j<N;++j)pool[j] -= i * conf[p][j];
		for(int j=0;j<i;++j)res[nrs++]=p;
		
		if(test() && bruteforce(p + 1))return true;
		
		for(int j=0;j<N;++j)pool[j] += i * conf[p][j];
		nrs-=i;
	}
	return false;
}
void solve(int T){
	string s;
	cin >> s;
	// print(s);
	
	for(auto&c:s)cout<<c-95<<" \n"[&c==&s.back()];
	
	fill(pool.begin(), pool.end(), 0);
	nrs=0;
	
	for(auto&c:s){
		int t = c - 95;
		
		
		if(t == 2){
			res[nrs++]=2;
		}else if(t == 4){
			res[nrs++]=2;
			res[nrs++]=2;
			t--;
		}else if(t == 8){
			res[nrs++]=2;
			res[nrs++]=2;
			res[nrs++]=2;
			t--;
		}else if(t == 16){
			res[nrs++]=2;
			res[nrs++]=2;
			res[nrs++]=2;
			res[nrs++]=2;
			t--;
		}
		
		if(t<=1)continue;
		for(int j=0;j<N;++j)pool[j] += conf[t][j]; 
	}
	
	bruteforce();
	
	sort(res.begin(), res.begin() + nrs);
	
	
	cout<<"Case #"<<T<<": ";
	for(int i=0;i<nrs;++i)cout<<char(res[i]+95);
	cout<<'\n';
	
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);
    
    init();
    
    int t = 1;
    cin >> t;
    for (int i=0;i++<t;) solve(i);
    
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
