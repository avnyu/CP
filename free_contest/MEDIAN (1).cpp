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

    vector<int>a(n);
    for ( auto &i:a ) cin >> i;
    vector<int>b(a);
    sort(a.begin(), a.end());

    for ( int i = 0; i < n; ++i ) cout << (b[i] <= a[n / 2 - 1] ? a[n / 2] : a[n / 2 - 1]) << '\n';

    return 0;
}