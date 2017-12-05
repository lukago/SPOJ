// bla2k17

#include <iostream>
#include <set>

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    set<char> explored;
    string names[100];
    uint64_t cnt, mod = 1000000007;
    int m, n;

    while (cin >> n >> m) {
        cnt = 1;

        for (int i = 0; i < n; i++)
            cin >> names[i];

        for (int i = 0; i < m; i++) {
            explored.clear();

            for (int j = 0; j < n; j++)
                explored.insert(names[j][i]);

            cnt = (cnt * explored.size()) % mod;
        }

        cout << cnt << "\n";
    }
    return 0;
}
