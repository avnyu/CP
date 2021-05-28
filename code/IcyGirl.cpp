#include <bits/stdc++.h>
#define N 10000007
using namespace std;

multiset<int> st, rt;
int dp[N], n, l, s, a[N];

int main() {
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    rt.insert(dp[0] = 0);
    for (int i = 1, j = 1; i <= n; i++) {
        st.insert(a[i]);
        for (; *st.begin() < a[i] - s || *st.rbegin() > a[i] + s; j++)
            st.erase(st.find(a[j])), rt.erase(rt.find(dp[j - 1]));
        if (i - j + 1 < l)
            dp[i] = N;
        else
            dp[i] = *rt.begin() + 1;
        rt.insert(dp[i]);
    }
    cout << (dp[n] >= N ? -1 : dp[n]) << endl;
    return 0;
}
