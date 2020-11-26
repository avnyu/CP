#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e3 + 7;
const int M = 4e6 + 7;
const int cat_K = 8;
const int mouse_K = 4;
ii cat;
set<ii> mouse;
vvii save(M);
const vii cat_step = {{-2, 0}, {-1, -1}, {0, -2}, {-1, 1}, {1, -1}, {2, 0},
                      {1, 1},  {0, 2},   {-1, 0}, {1, 0},  {0, -1}, {0, 1}};
const vii mouse_step = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const vector<string> go = {"UU", "UL", "LL", "UR", "DL", "DD",
                           "DR", "RR", "U",  "D",  "L",  "R"};

void init() {
    for (int i = 1; i * i < M; ++i)
        for (int j = 1; j * j + i * i < M; ++j)
            for (int k = -1; k < 2; k += 2)
                for (int l = -1; l < 2; l += 2)
                    save[i * i + j * j].push_back(ii{i * k, j * l});

    for (int i = 1; i * i < M; ++i)
        for (int k = -1; k < 2; k += 2) {
            save[i * i].push_back(ii{k * i, 0});
            save[i * i].push_back(ii{0, k * i});
        }

    cat = {0, 0};
}
set<ii> get(int d) {
    set<ii> res;
    for (auto& [x, y] : save[d]) res.insert(ii{cat.fi + x, cat.se + y});
    return res;
}
int move(int k) {
    cout << go[k].size() << " " << go[k] << endl;
    cat = {cat.fi + cat_step[k].fi, cat.se + cat_step[k].se};
    int d;
    cin >> d;
    return d;
}
int _random(int k) { return rand() % k; }
int choose(int d) {
    if (mouse.empty()) return 0;
    ll bst = 1e18 + 7;
    vi t;
    for (int i = 0; i < 12; ++i) {
        ll cur = 1e18;
        for (auto& [x, y] : mouse) {
            int dx = x - cat.fi - cat_step[i].fi;
            int dy = y - cat.se - cat_step[i].se;
            cur = min(cur, 1LL * dx * dx + dy * dy);
        }
        if (t.empty() || cur < bst) {
            t.clear();
            t.push_back(i);
            bst = cur;
        } else if (cur == bst) {
            t.push_back(i);
        }
    }
    int x = _random(int(t.size()));
    return t[x];
}
set<ii> change(int k, int d) {
    set<ii> res;
    if (mouse.empty()) return get(d);

    for (auto& [x, y] : mouse)
        for (auto& [mx, my] : mouse_step) {
            int dx = x + mx - cat.fi;
            int dy = y + my - cat.se;

            if (dx * dx + dy * dy == d) res.insert(ii{x + mx, y + my});
        }
    return res;
}
void solve(int T) {
    init();

    int k, d = 1e9;
    for (;;) {
        k = choose(d);
        d = move(k);
        if (d == 0) break;
        mouse = change(k, d);
    }
}
int main() {
    srand(time(nullptr));
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}