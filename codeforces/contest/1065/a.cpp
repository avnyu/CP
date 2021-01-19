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
    ll s, a, b, c;
    cin >> s >> a >> b >> c;
    s /= c;
    s += (s / a) * b;
    cout << s << endl;
}
int main() {
    FIO;
    // freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
