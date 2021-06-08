#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int, int>
#define mii map<pii, int>
#define all(a) (a).begin(), (a).end()
#define f first
#define s second
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep0(a, n) \
    for (int i = 0; i < n; i++) cin >> a[i]
#define si(x) cin >> x
#define sii(x, y) cin >> x >> y
#define siii(x, y, z) cin >> x >> y >> z
#define ahell 998244353
#define hell 1000000007
#define N1 2000001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountll(a)
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int i, j, k, l, n, m, ans = 0;
// int dp[2002][2002];
// int a[2002];

void solve() {
    int h;
    int s, l;
    siii(n, s, l);
    int a[n + 1];
    rep(i, 1, n + 1) si(a[i]);
    a[0] = -1000000000000;
    int dp[n + 1];
    if (s == 0) {
        cout << n;
        return;
    }
    if (l == 1) {
        cout << n;
        return;
    }
    dp[0] = 0;
    for (i = 1; i <= n; i++) dp[i] = hell;
    // cout<<a[0]<<" ";
    int lo = 0, id1 = 0, id2 = 0, pahla = 0;
    deque<int> min1, max1;
    min1.push_back(0);
    max1.push_back(0);
    set<pii> p1;
    p1.insert({dp[0], 0});
    if (l > n) {
        cout << "-1";
        return;
    }
    for (i = 1; i <= l - 1; i++) {
        while (!min1.empty() && a[min1.back()] >= a[i]) { min1.pop_back(); }
        min1.push_back(i);

        while (!max1.empty() && a[max1.back()] <= a[i]) { max1.pop_back(); }
        max1.push_back(i);
    }

    for (i = l; i <= n; i++) {
        // condition 2
        dp[i] = hell;

        // Find lo index
        while (!min1.empty() && a[min1.back()] >= a[i]) { min1.pop_back(); }
        min1.push_back(i);

        while (!max1.empty() && a[max1.back()] <= a[i]) { max1.pop_back(); }
        max1.push_back(i);

        while (lo <= i && !max1.empty() && !min1.empty() &&
               abs(a[max1.front()] - a[min1.front()]) > s) {
            while (!min1.empty() && min1.front() == lo) { min1.pop_front(); }
            while (!max1.empty() && max1.front() == lo) { max1.pop_front(); }
            lo++;
        }

        if (i - l + 1 >= lo) {
            while (id2 < i - l) {
                id2++;
                p1.insert({dp[id2], id2});
            }

            while (id1 < lo - 1 && id2 >= id1) {
                p1.erase(p1.find({dp[id1], id1}));
                id1++;
            }

            // pii q1=*(p1.begin());
            //  cout<<i<<" "<<q1.f<<" "<<q1.s<<"\n";

            if (sz(p1) > 0) dp[i] = (p1.begin())->f + 1;
        }
    }

    if (dp[n] >= hell)
        cout << "-1";
    else
        cout << dp[n];
}

main() {
    ios int i, j, test;
    test = 1;

    //
    // precal();
    // si(test);

    while (test--) { solve(); }
}
