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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e6 + 7;
const int M = 1e9 + 7;
vi res(N), d(N), sndd(N);
	
void init() {
	for(int i=1;i<N;++i)for(int j=i;j<N;j+=i)d[j]++;
	for(int i=1;i<N;++i)for(int j=i;j<N;j+=i)sndd[j]+=d[i];
	res[1]=1;
	for(int i=2;i<N;++i)res[i] = (res[i-1] * sndd[i] % M) % M;
}
bool solve(){
	int n;
	cin >> n;
	if (n == 0) return false;
	print(res[n]);
	return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

	init();

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
