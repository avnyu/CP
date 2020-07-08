#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int>a(n), b(n);
    for ( auto &i:a ) cin >> i;
    for ( auto &i:b ) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    ll ans = 1;
    ll fac[21] = {1};
    for ( int i = 1; i < 21; ++i ) fac[i] = fac[i - 1] * i;

    while ( i < n ) {
        while ( j < n && a[j] <= b[i] ) j++;

        if ( j <= i ) {cout << 0; return 0;}

        ans *= j - i;
        i++;
    }

    cout << ans;

    return 0;
}