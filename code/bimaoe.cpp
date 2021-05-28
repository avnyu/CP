#include <stdio.h>

#include <iostream>

using namespace std;

int v[10000000];
int str[10000000];

int main(void) {
    int n, s, l, i;
    scanf("%d%d%d", &n, &s, &l);
    for (i = 0; i < n; i++) { scanf("%d", &v[i]); }
    if (n < l) {
        printf("-1\n");
        return 0;
    }
    int mn = v[0], mx = v[0];
    str[0] = 0;
    for (i = 1; i < n; i++) {
        if (v[i] - mn > s || mx - v[i] > s) {
            str[i] = str[i - 1] + 1;
            mn = mx = v[i];
        } else {
            str[i] = str[i - 1];
            mx = max(v[i], mx);
            mn = min(v[i], mn);
        }
    }
    int cnt = 1;
    bool ok = true;
    mx = mn = v[n - 1];
    for (i = n - 2; i >= 0; i--) {
        if (str[i] == str[i + 1]) {
            cnt++;
            mx = max(v[i], mx);
            mn = min(v[i], mn);
        } else {
            if (cnt >= l) {
                cnt = 1;
                mx = mn = v[i];
            } else {
                if (v[i] - mn > s || mx - v[i] > s) {
                    ok = false;
                } else {
                    cnt++;
                    str[i] = str[i + 1];
                    mn = min(v[i], mn);
                    mx = max(v[i], mx);
                }
            }
        }
    }
    if (cnt < l) ok = false;
    int qty = 1;
    for (i = 1; i < n; i++) {
        if (str[i] != str[i - 1]) qty++;
    }
    if (!ok)
        printf("%d\n", -1);
    else
        printf("%d\n", qty);
}
