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

const double M = 1e5;
const int CNT = 50;

double cal(viii &a, double x, double y, double z){
    double res = 0;
    for(auto &[u, v, t]: a)
        res = max(res, sqrt((x-u)*(x-u) + (y-v)*(y-v) + (z-t)*(z-t)));
    return res;
}
double tsearch(viii &a, double x, double y){
    double lz = -M, rz = M;
    for(int cz = CNT; cz--;){
        double m1 = (lz + lz + rz) / 3;
        double m2 = (lz + rz + rz) / 3;
        double t1 = cal(a, x, y, m1);
        double t2 = cal(a, x, y, m2);
        if(t1 > t2)lz = m1;
        else rz = m2;
    }
    return cal(a, x, y, lz);
}
double tsearch(viii &a, double x){
    double ly = -M, ry = M;
    for(int cy = CNT; cy--;){
        double m1 = (ly + ly + ry) / 3;
        double m2 = (ly + ry + ry) / 3;
        double t1 = tsearch(a, x, m1);
        double t2 = tsearch(a, x, m2);
        if(t1 > t2)ly = m1;
        else ry = m2;
    }
    return tsearch(a, x, ly);
}
double tsearch(viii &a){
    double lx = -M, rx = M;
    for(int cx = CNT; cx--;){
        double m1 = (lx + lx + rx) / 3;
        double m2 = (lx + rx + rx) / 3;
        double t1 = tsearch(a, m1);
        double t2 = tsearch(a, m2);
        if(t1 > t2)lx = m1;
        else rx = m2;
    }
    return tsearch(a, lx);
}
void solve(int T) {
    int n;
    cin >> n;
    viii a(n);
    for(auto &[x, y, z] : a)cin >> x >> y >> z;
    /*
    print(n);
    for(auto &[x,y,z]: a)print(x,y,z);
    */
    cout << fixed << setprecision(9);
    print(tsearch(a));
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
