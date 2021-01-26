#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int b[10][6], a[10000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) { cin >> b[i][j]; }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            a[b[i][j]] = 1;
            for (int m = 0; m < n; m++) {
                for (int n = 0; n < 6; n++) {
                    if (m != i) a[10 * b[i][j] + b[m][n]] = 1;
                }
            }
        }
    }
    int i = 1;
    while (a[i] == 1) { i++; }
    cout << i - 1;
    return 0;
}