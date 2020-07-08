#include <bits/stdc++.h>

using namespace std;

int main() {
	double a, b, c, v0, v1, v2;
	cin >> a >> b >> c >> v0 >> v1 >> v2;
    double t11 = a / v0 + c / v1 + (a + c) / v2;
    double t12 = (a + c) / v0 + c / v1 + a / v2;
    double t13 = a / v0 + c / v1 + b / v2;
    double t21 = b / v0 + c / v1 + (b + c) / v2;
    double t22 = (b + c) / v0 + c / v1 + b / v2;
    double t23 = b / v0 + c / v1 + a / v2;
    double t31 = (a + b) / v0 + (a + b) / v1;
	double t32 = a / v0 + a / v1 + (a + c) / v0 + (a + c) / v1;
	double t33 = b / v0 + b / v1 + (b + c) / v0 + (b + c) / v1;
	t11 = min(t11, min(t12, t13));
	t21 = min(t21, min(t22, t23));
	t31 = min(t31, min(t32, t33));
	cout << fixed << setprecision(15) << min(t11, min(t21, t31)) << endl;
	return 0;
}
