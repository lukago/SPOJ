// spoj: pl.spoj.com/users/redoran/

#include <iostream>

using namespace std;

void fact(uint64_t num)
{
    if (num == 1) {
        cout << "1\n";
        return;
    }

    uint64_t pow = 0;
    while (num % 2 == 0) {
        pow++;
        num /= 2;
    }

    if (pow > 0) {
        cout << "2^" << pow << " ";
    }

    for (uint64_t i = 3; i * i <= num; i += 2) {
        pow = 0;
        while (num % i == 0) {
            pow++;
            num /= i;
        }

        if (pow > 0) {
            cout << i << "^" << pow << " ";
        }
    }

    if (num > 1) {
        cout<<num<<"^1";
    }

    cout << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    uint64_t num;

    while (cin >> num) {

        if (num == 0)
            return 0;

        multiples(num);
    }

    return 0;
}
