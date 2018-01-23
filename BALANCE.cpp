// redoran

#include <iostream>

using namespace std;

int64_t egcd(int64_t a, int64_t b, int64_t &p, int64_t &q)
{
    int64_t prev_r = a, r = b, prev_s = 1, s = 0, prev_t = 0, t = 1, quot, temp;

    while (r != 0) {
        quot = prev_r / r;
        temp = r;
        r = prev_r - quot * r;
        prev_r = temp;
        temp = s;
        s = prev_s - quot * s;
        prev_s = temp;
        temp = t;
        t = prev_t - quot * t;
        prev_t = temp;
    }

    p = prev_s;
    q = prev_t;
    return prev_r;
}

void assign(int64_t &q1, int64_t &q2, int64_t &p1, int64_t &p2,
            int64_t &m1, int64_t &m2, int64_t &s1, int64_t &s2)
{
    q1 = q2;
    p1 = p2;
    m1 = m2;
    s1 = s2;
}

void test()
{
    int64_t a, b, d, p, q, gcd, quot;

    while (cin >> a >> b >> d && (a != 0 || b != 0 || d != 0)) {
        gcd = egcd(a, b, p, q);

        if (d % gcd != 0) {
            cout << "BRAK\n";
            continue;
        }

        quot = d / gcd;
        p *= quot;
        q *= quot;

        int64_t qoutient1 = abs(p) * gcd / b;
        int64_t qoutient2 = abs(q) * gcd / a;
        int64_t p1 = p - qoutient1 * b / gcd;
        int64_t q1 = q + qoutient1 * a / gcd;
        int64_t p2 = p + qoutient1 * b / gcd;
        int64_t q2 = q - qoutient1 * a / gcd;
        int64_t p3 = p - qoutient2 * b / gcd;
        int64_t q3 = q + qoutient2 * a / gcd;
        int64_t p4 = p + qoutient2 * b / gcd;
        int64_t q4 = q - qoutient2 * a / gcd;
        int64_t mass = abs(p) * a + abs(q) * b;
        int64_t sum = abs(p) + abs(q);
        int64_t mass1 = abs(p1) * a + abs(q1) * b;
        int64_t sum1 = abs(p1) + abs(q1);
        int64_t mass2 = abs(p2) * a + abs(q2) * b;
        int64_t sum2 = abs(p2) + abs(q2);
        int64_t mass3 = abs(p3) * a + abs(q3) * b;
        int64_t sum3 = abs(p3) + abs(q3);
        int64_t mass4 = abs(p4) * a + abs(q4) * b;
        int64_t sum4 = abs(p4) + abs(q4);

        if (!(sum1 < sum2 || (sum1 == sum2 && mass1 < mass2)))
            assign(q1, q2, p1, p2, mass1, mass2, sum1, sum2);

        if (!(sum3 < sum4 || (sum3 == sum4 && mass3 < mass4)))
            assign(q3, q4, p3, p4, mass3, mass4, sum3, sum4);

        if (!(sum1 < sum3 || (sum1 == sum3 && mass1 < mass3)))
            assign(q1, q3, p1, p3, mass1, mass3, sum1, sum3);

        if (!(sum < sum1 || (sum == sum1 && mass < mass1)))
            assign(q, q1, p, p1, mass, mass1, sum, sum1);


        p1 = p - b / gcd;
        q1 = q + a / gcd;
        p2 = p + b / gcd;
        q2 = q - a / gcd;
        mass1 = abs(p1) * a + abs(q1) * b;
        sum1 = abs(p1) + abs(q1);
        mass2 = abs(p2) * a + abs(q2) * b;
        sum2 = abs(p2) + abs(q2);

        if (!(sum1 < sum2 || (sum1 == sum2 && mass1 < mass2)))
            assign(q1, q2, p1, p2, mass1, mass2, sum1, sum2);

        if (!(sum < sum1 || (sum == sum1 && mass < mass1))) {
            q = q1;
            p = p1;
        }

        cout << abs(p) << ' ' << abs(q) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}