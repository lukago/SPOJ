// Lukasz Golebiewski 203882
// spoj: pl.spoj.com/users/redoran/

#include <iostream>

using namespace std;

int abs(int x) {
    if (x < 0) x = -x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int lines, cat0_age, cat0_place, cat1_age, cat1_place, p_diff, p_diff_mod;

    cin>>lines;
    while (lines-- > 0) {
        cin>>cat0_age>>cat0_place>>cat1_age>>cat1_place;

        p_diff = abs(cat1_place - cat0_place) + 1;
        p_diff_mod = p_diff%3;

        if (cat0_age > cat1_age) {
            if (p_diff_mod != 2) cout<<"1\n";
            else cout<<"0\n";
        } else {
            if (p_diff_mod != 2 ) cout<<"0\n";
            else cout<<"1\n";
        }
    }

    return 0;
}
