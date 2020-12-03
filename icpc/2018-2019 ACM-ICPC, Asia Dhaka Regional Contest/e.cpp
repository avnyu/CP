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
#define prt(u) \
    for (auto& i : u) cout << i << " \n"[&i == &u.back()];
#define iii tuple<int,int,int>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

bool solve(){
	int n;
	cin >> n;
	if(n==0)return false;
	
	int cnt = 0;
	for(int i=0;i<n;++i){
		char t, c;
		int h1,m1,s1,h2,m2,s2,h3,m3,s3;
		cin>>t>>c>>h1>>c>>m1>>c>>s1>>c>>h2>>c>>m2>>c>>s2;
		
		if(t=='D' && iii{h1,m1,s1} > iii{9,30,0}){
			cnt++;
			continue;
		}
		if(t=='E' && iii{h1,m1,s1} > iii{12,30,0}){
			cnt++;
			continue;
		}
		
		if(iii{h1,m1,s1} < iii{8,30,0}){
			h1=8;
			m1=30;
			s1=0;
		}
		
		if(s2<s1){
			s2+=60;
			m2--;
		}
		if(m2<m1){
			m2+=60;
			h2--;
		}
		
		h3=h2-h1;
		m3=m2-m1;
		s3=s2-s1;
		
		if(t=='D' && iii{h3,m3,s3} < iii{8,0,0})cnt++;
		else if(t=='E' && iii{h3,m3,s3} < iii{9,0,0})cnt++;
	}
	
	if(cnt==0)print("All OK");
	else if(cnt==1)print("1 Point(s) Deducted");
	else if(cnt==2)print("2 Point(s) Deducted");
	else if(cnt==3)print("3 Point(s) Deducted");
	else print("Issue Show Cause Letter"); 
	return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);
    
    while (1) if(!solve()) break;

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
