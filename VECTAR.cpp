// spoj: redoran

#include <iostream>

using namespace std;

const int MAXVAL = 1000007;
bool win[MAXVAL] = {false};

int init()
{
    for (int i = 1; i < MAXVAL; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (!win[i - j * j]) {
                win[i] = true;
                break;
            }
        }
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int t, x;
    cin >> t;

    init();

    while (t-- > 0) {
        cin >> x;
        if (win[x]) cout << "Win\n";
        else cout << "Lose\n";
    }


    return 0;
}