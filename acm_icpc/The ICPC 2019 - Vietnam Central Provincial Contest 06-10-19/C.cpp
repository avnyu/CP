#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        {
            cout << "YES\n";
            continue;
        }
        if (x2 == 0 && y2 == 0)
        {
            cout << "NO\n";
            continue;
        }
        if (x1 == 0 && y1 == 0)
        {
            cout << "NO\n";
            continue;
        }
        if (__gcd(abs(x1), abs(y1)) == __gcd(abs(x2), abs(y2)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}