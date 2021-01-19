#include <math.h>
#include <time.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    ll s = 0, prvs = 0, ans = 0;
    for (int i = a[n - 1] - 1; i >= a[0]; --i) {
        int j = a.end() - upper_bound(a.begin(), a.end(), i);
        s += 1LL * j;
        if (s > k) {
            ++ans;
            s -= prvs;
        }
        prvs = s;
    }
    ans += s > 0;
    cout << ans;
}
int main() {
    FIO;
    // freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) { solve(); }
    return 0;
}
