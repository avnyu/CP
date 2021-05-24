#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

int a[100001];
int d[100001];
std::deque<int> max, min, dp, pos;
void solve() {
    int i, j, k, n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        d[i] = 1e9;
    }
    j = 0;
    dp.push_back(0);
    pos.push_back(0);
    for (i = 1; i <= n; i++) {
        while (!max.empty() && max.back() < a[i]) max.pop_back();
        while (!min.empty() && min.back() > a[i]) min.pop_back();
        max.push_back(a[i]);
        min.push_back(a[i]);
        while (max.front() - min.front() > m) {
            if (dp.front() == d[j]) {
                dp.pop_front();
                pos.pop_front();
            }
            j++;
            if (max.front() == a[j]) max.pop_front();
            if (min.front() == a[j]) min.pop_front();
        }
        if (i - pos.front() >= l) d[i] = dp.front() + 1;
        while (!dp.empty() && dp.back() > d[i]) {
            dp.pop_back();
            pos.pop_back();
        }
        dp.push_back(d[i]);
        pos.push_back(i);
    }
    printf("%d", d[n] <= n ? d[n] : -1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve();

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