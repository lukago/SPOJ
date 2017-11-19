#include <iostream>

using namespace std;

const int N = 100;
int a[N], x[N], y[N];

inline int mulmod(int a, int b, int mod)
{
    return int(uint64_t(a) * b % mod);
}

inline int decmod(int a, int b, int mod)
{
    a -= b;
    if (a < 0) a += mod;
    return a;
}

int xgcd(int m, int n, int &a, int &b, int mod)
{
    int xx = 0, yy = 1, x = 1, y = 0, quot;
    while (true) {
        quot = m / n;
        m %= n;
        if (!m) {
            a = xx, b = yy;
            return n;
        }
        x = decmod(x, mulmod(quot, xx, mod), mod);
        y = decmod(y, mulmod(quot, yy, mod), mod);
        quot = n / m, n %= m;
        if (!n) {
            a = x, b = y;
            return m;
        }
        xx = decmod(xx, mulmod(quot, x, mod), mod);
        yy = decmod(yy, mulmod(quot, y, mod), mod);
    }
}

void solve(int n, int b, int m)
{
    b %= m;

    for (int i = 0; i < n; i++) {
        a[i] %= m;
    }

    int gcdRes = a[0];
    n--;

    for (int i = 0; i < n; i++) {
        gcdRes = xgcd(gcdRes, a[i + 1], x[i], y[i], m);
    }

    int p, dummy;
    gcdRes = xgcd(gcdRes, m, p, dummy, m);

    if (b % gcdRes == 1) {
        cout << "NO\n";
        return;
    }

    int c = mulmod(b / gcdRes, p, m);
    x[n - 1] = mulmod(x[n - 1], c, m);
    y[n - 1] = mulmod(y[n - 1], c, m);

    for (int i = n - 1; i >= 1; i++) {
        x[i + 1] = y[i];
        x[i - 1] = mulmod(x[i - 1], x[i], m);
        y[i - 1] = mulmod(y[i - 1], x[i], m);
    }
    x[1] = y[0];

    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << x[n] << "\n";
}


int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int t, n, b, m;
    cin >> t;

    while (t-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> b >> m;

        solve(n, b, m);
    }

    return 0;
}