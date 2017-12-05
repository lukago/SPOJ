#include <iostream>

using namespace std;

const int N = 100;
int a[N], x[N], y[N];

inline int mulmod(int a, int b, int m)
{
    return int(int64_t(a) * b % m);
}

int xgcd(int a, int b, int &pp, int &qq)
{
    int a0 = a, b0 = b;
    int p = 1, q = 0;
    int r = 0, s = 1, prevR, prevS;
    int mod, quot;

    while (b != 0) {
        mod = a % b;
        quot = a / b;
        a = b, b = mod;
        prevR = r, prevS = s;
        r = p - quot * r;
        s = q - quot * s;
        p = prevR, q = prevS;
    }

    pp = p;
    qq = q;
    return p * a0 + q * b0;
}

void printCongSol(int n, int b, int m)
{
    b %= m;
    for (int i = 0; i < n; i++) {
        a[i] %= m;
    }

    int gcdRes = a[0], p, q;
    n = n - 1;

    for (int i = 0; i < n; i++) {
        gcdRes = xgcd(gcdRes, a[i + 1], p, q);
        x[i] = p < 0 ? p % m + m : p % m;
        y[i] = q < 0 ? q % m + m : q % m;
    }
    gcdRes = xgcd(gcdRes, m, p, q);
    p = p < 0 ? p % m + m : p % m;

    if (b % gcdRes) {
        cout << "NO\n";
        return;
    }

    int c = mulmod(b / gcdRes, p, m);
    x[n - 1] = mulmod(x[n - 1], c, m);
    y[n - 1] = mulmod(y[n - 1], c, m);

    for (int i = n - 1; i >= 1; i--) {
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

    int t, n, m, b;
    cin >> t;

    while (t-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> b >> m;

        printCongSol(n, b, m);
    }
}
