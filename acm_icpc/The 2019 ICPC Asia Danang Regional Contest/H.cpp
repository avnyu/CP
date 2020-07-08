#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int r, c, res = 0;
// valid_col[num_of_col][num_of_valid_col_j][row_i_of_valid_col_j]
vector<vector<vector<char>>> valid_col(6);
// mark[num_of_valid_col]
vector<int> mark(6);
// row_req[num_of_row][req_i]
vector<vector<int>> row_req(6);
// col_req[num_of_col][col_j]
vector<vector<int>> col_req(6);

vector<char> for_gen(6);
vector<char> mark_row_i(6);

bool valid(vector<char>& a, int na, vector<int>& req) {
    vector<int> cnt;
    int l = 0;
    for (int i = 0; i < na; ++i) {
        if (a[i] == '1') {
            if (!i || a[i - 1] == '0') l = i;
            if (i == na - 1 || a[i + 1] == '0') cnt.emplace_back(i - l + 1);
        }
    }
    if (cnt.size() != req.size()) return false;
    for (int i = 0; i < cnt.size(); ++i)
        if (cnt[i] != req[i]) return false;
    return true;
}

void gen_col_j(int j, int step) {
    if (step == r) {
        if (valid(for_gen, r, col_req[j]))
            valid_col[j].push_back(vector<char>(for_gen));
        return;
    }
    for_gen[step] = '0';
    gen_col_j(j, step + 1);
    for_gen[step] = '1';
    gen_col_j(j, step + 1);
}

void get_input() {
    int ki, kj, rri, ccj;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> ki;
        row_req[i].assign(ki, 0);
        for (int ir = 0; ir < ki; ++ir) cin >> row_req[i][ir];
    }
    for (int j = 0; j < c; ++j) {
        cin >> kj;
        col_req[j].assign(kj, 0);
        for (int jc = 0; jc < kj; ++jc) cin >> col_req[j][jc];
    }
}

bool check_mark() {
    bool chk = true;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) mark_row_i[j] = valid_col[j][mark[j]][i];
        chk &= valid(mark_row_i, c, row_req[i]);
    }
    return chk;
}

void gen_mark(int step) {
    if (step == c) {
        res += check_mark();
        return;
    }
    for (int mi = 0; mi < valid_col[step].size(); ++mi) {
        mark[step] = mi;
        gen_mark(step + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    //freopen("in", "r", stdin);

    get_input();
    for (int j = 0; j < c; ++j) gen_col_j(j, 0);
    gen_mark(0);

    cout << res << '\n';

    return 0;
}