#include<bits/stdc++.h>

using namespace std;

const int N = 41;
int M = 666777;
int n, k;

void mul(int a[N][N], int b[N][N])
{
    int c[N][N] = {};
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
                c[i][j] = (1LL * c[i][j] + 1LL * a[i][k] * b[k][j]) % M;
        }
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = c[i][j];
}

void pow(int a[N][N], int b)
{
    int rs[N][N] = {};
    for (int i = 0; i < N; ++i)
        rs[i][i] = 1;
    while (b)
    {
        if (b & 1)
            mul(rs, a);
        b >>= 1;
        mul(a, a);
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = rs[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int a[N][N] = {}, m[N][N] = {};
    a[0][0] = 1;

    for (int i = 0; i < N; ++i)
        m[i][0] = 1;
    for (int i = 1; i <= k; ++i)
        m[i - 1][i] = 1;

    pow(m, n);
    mul(a, m);

    long long ans = 0;
    for (int i = 0; i <= k; ++i)
    {
        ans = (ans + a[0][i]) % M;
    }
    cout << ans << '\n';

    return 0;
}