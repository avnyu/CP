#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int M = 1e9 + 7;

vi val(4);
vi per(4);
vi full(19);

vi type = {'(', '(', '(', 'n', 'o', '(', '(', 'n', ')', 'o',
           '(', 'n', ')', ')', 'o', 'n', ')', ')', ')'};
vi opr_pos = {4, 9, 14};
vi val_pos = {3, 7, 11, 15};
vi bracket_pos = {1, 2, 5, 6, 8, 10, 12, 13, 16, 17};
stack<int> s;
stack<int> t;

int nghichthe() {
    int res = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j) res += per[i] > per[j];
    return res;
}
int stack_cal(stack<int>& a) {
    if (a.empty()) return M;

    int res = 0, u, o, v;
    while (a.size() > 1) {
        u = a.top();
        a.pop();
        o = a.top();
        a.pop();
        v = a.top();
        a.pop();

        if (o == -1) {
            a.push(u + v);
        } else if (o == -2) {
            a.push(u - v);
        } else if (o == -3) {
            a.push(u * v);
        } else if (o == -4) {
            if (v == 0 || u % v) return M;
            a.push(u / v);
        }
    }

    res = a.top();
    a.pop();

    return res;
}
bool stack_add(stack<int>& a, int v) {
    if (a.size() && (a.top() == -3 || a.top() == -4)) {
        int u, o;
        o = a.top();
        a.pop();
        u = a.top();
        a.pop();

        if (o == -3)
            a.push(u * v);
        else if (o == -4) {
            if (v == 0 || u % v) return false;
            a.push(u / v);
        }
    } else
        a.push(v);

    return true;
}
int cal() {
    int cost = 0, u;

    while (!s.empty()) s.pop();
    while (!t.empty()) t.pop();

    for (int i = 0; i < 19; ++i) {
        if (type[i] == '(' && full[i]) {
            cost++;
            s.push(-M);
        } else if (type[i] == ')' && full[i]) {
            while (s.top() != -M) {
                t.push(s.top());
                s.pop();
            }
            s.pop();

            u = stack_cal(t);

            if (!stack_add(s, u)) return M;
        } else if (type[i] == 'n') {
            if (!stack_add(s, full[i])) return M;
        } else if (type[i] == 'o') {
            s.push(full[i]);
        }
    }

    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }
    u = stack_cal(t);

    return u == 24 ? cost : M;
}
int dfs_bracket(int p = 0, int dif = 0, int cnt = 0) {
    if (p == int(bracket_pos.size())) {
        if (dif == 0) return cal();
        return M;
    }
    int res = M;
    if (type[bracket_pos[p]] == '(') {
        if (cnt < 3) {
            full[bracket_pos[p]] = 1;
            res = min(res, dfs_bracket(p + 1, dif + 1, cnt + 1));
        }
        full[bracket_pos[p]] = 0;
        res = min(res, dfs_bracket(p + 1, dif, cnt));
    } else {
        if (dif) {
            full[bracket_pos[p]] = 1;
            res = min(res, dfs_bracket(p + 1, dif - 1, cnt));
        }
        full[bracket_pos[p]] = 0;
        res = min(res, dfs_bracket(p + 1, dif, cnt));
    }
    return res;
}
int dfs_opr(int p = 0) {
    if (p == 3) {
        return dfs_bracket();
        // return M;
    }
    int res = M;
    for (int i = -1; i > -5; --i) {
        full[opr_pos[p]] = i;
        res = min(res, dfs_opr(p + 1));
    }
    return res;
}
void solve() {
    for (auto& i : val) cin >> i;

    int cost = 0, res = M;
    iota(per.begin(), per.end(), 0);

    do {
        for (int i = 0; i < 4; ++i) full[val_pos[per[i]]] = val[i];
        cost = 2 * nghichthe();
        res = min(res, cost + dfs_opr());
    } while (next_permutation(per.begin(), per.end()));

    if (res >= M)
        print("impossible");
    else
        print(res);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    clock_t x = clock();

    int T = 1;
    // cin >> t;
    while (T--) solve();

    print("Time", (clock() - x) / 1000);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else
        cout << x << '\n';
}
