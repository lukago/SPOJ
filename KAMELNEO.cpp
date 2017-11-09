// spoj: pl.spoj.com/users/redoran/

#include <iostream>
#include <cstring>

using namespace std;

bool arrEqu(const int arr1[], int sz)
{
    for (int i = 0; i < sz; i++) {
        if (arr1[i] != i + 1)
            return false;
    }
    return true;
}

int changeColor(int index, int impulses, const int prev[], int curr[], int sz)
{
    if (impulses == 0)
        return index + 1;


    for (int j = 1; j < impulses; j++) {
        for (int i = 0; i < sz; i++) {
            curr[i] = prev[curr[i] - 1];
        }

        if (arrEqu(curr, sz)) {
            impulses = impulses % (j + 1);
            j = -1;
        }
    }

    return curr[index];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q, a, k;
    cin >> n;

    int *pr = new int[n];
    int *curr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> pr[i];
    }

    cin >> q;

    while (q-- > 0) {
        cin >> a >> k;
        memcpy(curr, pr, n * sizeof(int));
        cout << changeColor(a - 1, k, pr, curr, n) << "\n";
    }

    delete[] curr;
    delete[] pr;

    return 0;
}