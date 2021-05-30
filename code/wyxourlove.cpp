#include <bits/stdc++.h>

#define MAX_N 10010000
int a[MAX_N];
std::vector<int> duan;
int main() {
    int n, s, l;
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int max = 1, min = 1;
    for (int i = 1; i <= n; i++) {
        if (a[max] < a[i]) max = i;
        if (a[min] > a[i]) min = i;
        if (abs(a[max] - a[min]) > s) {
            duan.push_back(std::min(max, min));
            duan.push_back(std::max(max, min));
            max = min = std::max(max, min);
        }
    }
    int ans = duan.size() / 2 + 1;
    int pre = 0;
    for (int i = 0; i < duan.size(); i += 2) {
        int L = duan[i], R = duan[i + 1];
        if (R - pre - 1 < l) ans = -1;
        pre = std::max(L, pre + l);
    }
    printf("%d\n", ans);
    return 0;
}