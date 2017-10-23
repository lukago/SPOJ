#include <iostream>

using namespace std;

// Lukasz Golebiewski 203882
// spoj: pl.spoj.com/users/redoran/
int main() {
    ios_base::sync_with_stdio(false);

    double n;
    while (cin>>n) {
        while(n > 9) n /= 18;
        if (n > 1) cout<<"A\n";
        else cout<<"B\n";
    }

    return 0;
}
