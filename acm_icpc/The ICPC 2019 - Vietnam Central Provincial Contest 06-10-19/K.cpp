#include <bits/stdc++.h>
using namespace std;

const int m = (int) 1e6 + 1;
const int sm = (int) sqrt(m) + 1;

vector<int> phi;
vector<int> digit;
vector<bool> prime;

void init()
{
    prime.assign(m + 1, true);
    prime[0] = prime[1] = false;
    phi.resize(m);
    for (int i = 1; i < m; ++i)
    {
        phi[i] = i;
    }
    for (int i = 2; i < m; ++i)
    {
        if (prime[i])
        {
            for (int j = i; j < m; j += i)
            {
                prime[j] = false;
                phi[j] -= phi[j] / i;
            }
        }
    }
    digit.resize(m);
    for (int i = 1; i < m; ++i)
    {
        digit[i] = (int) log10(i) + 1;
    }
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    init();
    string ans[2] = {"BACH", "KHOA"};

    vector<int> f;
    f.assign(m, 1);

    f[1] = 0;
    for (int i = 2; i < int(1e6 + 1); ++i)
    {
        int x = i - 1;
        int y = i - phi[i];
        int z = i - digit[i];

        if (x > 0 && f[x] == 1)
            f[i] = 0;
        else if (y > 0 && f[y] == 1)
            f[i] = 0;
        else if (z > 0 && f[z] == 1)
            f[i] = 0;
        else f[i] = 1;
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << ans[f[x]] << '\n';
    }
}