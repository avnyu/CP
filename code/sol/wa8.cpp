#include <cstdio>
#include <iostream>
#define NMAX 2000002
#define LOG_MAX 18
using namespace std;

int r_min[LOG_MAX][NMAX];
int r_max[LOG_MAX][NMAX];
int log[NMAX];

bool valid(int xi, int xf, int s) {
    int k = log[xf - xi + 1];
    int MIN = min(r_min[k][xi], r_min[k][xf - (1 << k) + 1]);
    int MAX = max(r_max[k][xi], r_max[k][xf - (1 << k) + 1]);
    if (1LL * MAX - 1LL * MIN <= 1LL * s) return true;
    return false;
}

int main() {
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    int n, s, l, i, k, x, strips, last_i;
    bool solutie = true;
    scanf("%d %d %d", &n, &s, &l);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        r_min[0][i] = r_max[0][i] = x;
    }

    for (i = 2; i <= n; i++) log[i] = log[i / 2] + 1;
    for (k = 1; (1 << k) <= n; k++)
        for (i = 1; i + (1 << k) - 1 <= n; i++) {
            r_min[k][i] =
                min(r_min[k - 1][i], r_min[k - 1][i + (1 << (k - 1))]);
            r_max[k][i] =
                max(r_max[k - 1][i], r_max[k - 1][i + (1 << (k - 1))]);
        }

    last_i = 0;
    for (strips = 0, i = 1; i <= n && solutie;) {
        k = l;
        while (i + k - 1 <= n && valid(i, i + k - 1, s)) k++;
        if (k == l) {  /// nu am reusit sa iau un element din dreapta pentru ca
                       /// nu respecta cerinta
            k = l;
            while (i - k + 1 > last_i && !valid(i - k + 1, i, s)) k++;
            if (i - k + 1 == last_i) solutie = false;
            // printf("1 (%d, %d)\n",i-k,i);
            last_i = i;
            i++;
        } else {
            last_i = i;
            k--;
            // printf("2 (%d, %d)\n",i,i+k-1);
            i += k;
        }
        strips++;
    }
    if (!solutie)
        printf("-1\n");
    else
        printf("%d\n", strips);
    return 0;
}
