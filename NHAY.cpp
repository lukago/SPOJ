// redoran

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int len;
    string pattern, hay;

    while (cin >> len) {
        cin >> pattern >> hay;
        string phay = pattern + "#" + hay;
        int n = (int) phay.length();
        vector<int> z(n, 0);

        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && phay[r - l] == phay[r]) r++;
                z[i] = r - l;
                r--;
            } else {
                int k = i - l;
                if (z[k] < r - i + 1) z[i] = z[k];
                else {
                    l = i;
                    while (r > 0 && phay[r - l] == phay[r]) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }

        bool flag = true;
        for (int i = len; i < n; i++) {
            if (z[i] == len) {
                cout << i - len - 1 << '\n';
                flag = false;
            }
        }

        if (flag) cout << '\n';
    }
}