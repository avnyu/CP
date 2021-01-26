#include <iostream>
using namespace std;
long n, a, b, c, d, start, len;
long day[400000], type[400000];
int main() {
    cin >> n >> a >> b >> c >> d >> start >> len;
    for (int i = 0; i < n; i++) { cin >> day[i] >> type[i]; }
    long long min_rate = 0, sup_rate = start, prs_rate = start;
    long i = 0, j = 0, futday = len;
    while (day[i] < futday && i < n) {
        sup_rate += type[i] == 1 ? c : -d;
        if (min_rate > sup_rate) min_rate = sup_rate;
        i++;
    }
    if (min_rate >= 0) {
        cout << 0;
        // cout << "-t2" << endl;
        return 0;
    }
    while (j < n) {
        prs_rate += type[j] == 1 ? a : -b;
        if (prs_rate < 0) {
            cout << -1;
            return 0;
        }
        futday += day[j] - day[j - 1];
        min_rate += type[j] == 1 ? -c + a : d - b;
        sup_rate += type[j] == 1 ? -c + a : d - b;
        while (day[i] < futday && i < n) {
            sup_rate += type[i] == 1 ? c : -d;
            if (sup_rate < min_rate) min_rate = sup_rate;
            i++;
        }
        if (min_rate >= 0) {
            cout << day[j] + 1;
            // cout << "-t4" << endl;
            return 0;
        }
        // cout << "start: " << start << "-min_rate: " << min_rate << "-j: " <<
        // j << "-futday: " << futday << endl;
        j++;
    }
    // cout << start << " " << sup_rate << " " << min_rate << endl;
    // cout << add1 << " " << add0;
    return 0;
}
