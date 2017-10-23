// Lukasz Golebiewski 203882
// spoj: pl.spoj.com/users/redoran/

#include <iostream>
#include <cmath>

using namespace std;

void swapDouble(double& a, double& b) {
    double tmp = a;
    a = b;
    b = tmp;
}

bool checkIfFits(double p, double q, double a, double b) {
    if (p < q) swapDouble(p, q);
    if (a < b) swapDouble(a, b);

    if (p < a && q < b) return true;

    if (p > a) {
        double p2 = p*p;
        double q2 = q*q;
        double a2 = a*a;
        double x = (2.0*p*q*a + (p2 - q2)*sqrt(p2 + q2 - a2)) / (p2 + q2);
        if (b > x) return true;
    }

    return false;
}

int main() {
    std::cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double a, b, p, q;
    int tests;
    cin>>tests;

    for (int i = 0; i < tests; i++) {
        cin>>a>>b>>p>>q;
        if (checkIfFits(p, q, a, b))
            cout<<"TAK\n";
        else
            cout<<"NIE\n";
    }

    return 0;
}

