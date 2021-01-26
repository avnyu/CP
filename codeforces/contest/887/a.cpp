#include <iostream>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    int kt = 0;
    int rq = 0;
    int i = a.length() - 1;
    while (i != -1) {
        if (a[i--] == '0') rq++;
        if (rq == 6) break;
    }
    while (i != -1) {
        if (a[i--] == '1') {
            kt = 1;
            break;
        }
    }
    if (kt == 1 && rq == 6)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
