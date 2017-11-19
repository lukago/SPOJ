// lukago

#include <iostream>

using namespace std;

pair<int, int> xgcd(int a, int b)
{
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

    return {p, q};
}

int mulinv(int a, int m)
{
    auto res = xgcd(a, m);
    return res.first % m;
}

int crt(int a, int b, int c, int daysStart)
{
    int days = 0;
    int m = 23 * 28 * 33;

    days += a * mulinv(28 * 33, 23) * 28 * 33;
    days += b * mulinv(23 * 33, 28) * 23 * 33;
    days += c * mulinv(23 * 28, 33) * 23 * 28;
    days %= m;

    while (days <= daysStart) days += m;

    return days - daysStart;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int p, e, i, d, cases = 0;

    while (cin >> p >> e >> i >> d) {
        if (p == -1 && e == -1 && i == -1 && d == -1) break;

        cout << "Case " << ++cases
             << ": the next triple peak occurs in " << crt(p, e, i, d) << " days.\n";
    }

    return 0;
}

