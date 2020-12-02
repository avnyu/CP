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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
	string s;
	cin >> s;
	int n = s.size();
	
	if(s.back()=='a')s+='s';
	else if(s.back() == 'i')s+="os";
	else if(s.back() == 'y'){
		s.pop_back();
		s+="ios";
	}else if(s.back()=='l')s+="es";
	else if(s.back()=='n'){
		s.pop_back();
		s+="anes";
	}else if(n>1 && s[n-1]== 'e' && s[n-2]=='n'){
		s.pop_back();
		s.pop_back();
		s+="anes";
	}else if(s.back()=='o')s+='s';
	else if(s.back()=='r')s+="es";
	else if(s.back()=='t')s+="as";
	else if(s.back()=='u')s+='s';
	else if(s.back()=='v')s+="es";
	else if(s.back()=='w')s+="as";
	else s+="us";
	
	print(s);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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
