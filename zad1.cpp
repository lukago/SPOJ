// Lukasz Golebiewski 20388

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    vector<int> tab(213789, 0);

    int t, a;
    cin >> t;

    while (t-- > 0) {
        cin >> a;
        tab[a]++;
    }

    for (int i = 0; i < tab.size(); i++) {
        tab[i] += tab[i - 1] / 3;
    }

    for (int i = tab.size() - 1; i >= 0; i--) {
        if (tab[i] != 0) {
            cout << i;
            break;
        }
    }

    return 0;
}