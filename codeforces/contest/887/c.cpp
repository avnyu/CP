#include <iostream>
using namespace std;
int a[100];
int kt(int k, int l, int m, int n) {
    if (a[k] - a[l] == 0 and a[m] - a[n] == 0 and a[l] - a[m] == 0)
        return 1;
    else
        return 0;
}
int main() {
    for (int i = 1; i <= 24; i++) { cin >> a[i]; }
    if (kt(1, 2, 3, 4) * kt(9, 10, 11, 12) == 1) {
        if (kt(5, 6, 19, 20) * kt(17, 18, 23, 24) * kt(21, 22, 15, 16) *
                kt(13, 14, 7, 8) ==
            1) {
            cout << "YES";
            return 0;
        }
        if (kt(5, 6, 15, 16) * kt(17, 18, 7, 8) * kt(21, 22, 19, 20) *
                kt(13, 14, 23, 24) ==
            1) {
            cout << "YES";
            return 0;
        }
    }
    if (kt(13, 14, 15, 16) * kt(17, 18, 19, 20) == 1) {
        if (kt(1, 3, 6, 8) * kt(5, 7, 10, 12) * kt(9, 11, 21, 23) *
                kt(22, 24, 2, 4) ==
            1) {
            cout << "YES";
            return 0;
        }
        if (kt(1, 3, 21, 23) * kt(5, 7, 2, 4) * kt(9, 11, 6, 8) *
                kt(22, 24, 10, 12) ==
            1) {
            cout << "YES";
            return 0;
        }
    }
    if (kt(5, 6, 7, 8) * kt(21, 22, 23, 24) == 1) {
        if (kt(3, 4, 18, 20) * kt(17, 19, 11, 12) * kt(9, 10, 13, 15) *
                kt(14, 16, 1, 2) ==
            1) {
            cout << "YES";
            return 0;
        }
        if (kt(3, 4, 13, 15) * kt(17, 19, 1, 2) * kt(9, 10, 18, 20) *
                kt(14, 16, 11, 12) ==
            1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
