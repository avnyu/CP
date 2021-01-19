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
    ll n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n << ' ' << n << endl;
    } else {
        cout << (n - (m << 1) > 0 ? n - (m << 1) : 0) << ' ';
        ll x = 1;
        --n;
        while (m > 0) {
            n--;
            m -= x++;
        }
        cout << n << endl;
    }
}
int main() {
    FIO;
    // freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) { solve(); }
    return 0;
}
