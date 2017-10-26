#include <cmath>
#include <iostream>

using namespace std;

bool prime(int64_t n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int64_t num, t;
    cin >> t;
    while (t-- > 0) {
        cin >> num;
        int64_t root = sqrt(num);
        if (root * root == num && prime(root)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}