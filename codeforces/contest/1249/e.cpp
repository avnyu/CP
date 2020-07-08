#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int>a(n), b(n);
    for(int i = 1; i < n; ++i)cin >> a[i];
    for(int i = 1; i < n; ++i)cin >> b[i];

    vector<int>dps(2), dpe(2, c);
    int p = 0, q = 1;

    cout << "0";
    for(int i = 1; i < n; ++i)
    {
        p = 1 - p, q = 1 - q;
        dps[q] = min(dps[p], dpe[p]) + a[i];
        dpe[q] = min(dps[p] + c, dpe[p]) + b[i];
        //cout << i << " " << dps[q] << ' '<< dpe[q] << '\n';
        cout << " " << min(dps[q], dpe[q]);
    }
    cout << '\n';

    return 0;
}