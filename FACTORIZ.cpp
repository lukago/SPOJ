#include <iostream>
#include <vector>

#define MAX 8000000
#define MAXP 800000

bool primesFlags[MAX];
int primes[MAXP];
int pNum = 1;

using namespace std;

void initPrimes()
{
    for (int i = 0; i < MAX; i++) {
        primesFlags[i] = true;
    }

    for (int i = 3; i * i < MAX; i += 2) {
        if (primesFlags[i]) {
            primes[pNum++] = i;
            for (int64_t j = i * i; j < MAX; j += i) {
                primesFlags[j] = false;
            }
        }
    }

    primes[0] = 2;
    for (int i = 3; i < MAX; i += 2) {
        if (primesFlags[i]) {
            primes[pNum++] = i;
        }
    }
}

vector<int> pfactor(int num)
{
    vector<int> factors;

    if (num == 1) {
        factors.push_back(num);
        return factors;
    }

    for (int i = 0; 1LL * primes[i] * primes[i] <= num; i++) {
        while (num % primes[i] == 0) {
            factors.push_back(primes[i]);
            num /= primes[i];
        }
    }

    if (num > 1) {
        factors.push_back(num);
    }

    return factors;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    initPrimes();

    int num, t;
    cin >> t;

    while (t-- > 0) {
        cin >> num;

        auto result = pfactor(num);

        cout << result[0];
        for (int i = 1; i < result.size(); i++) {
            cout << "*" << result[i];
        }
        cout << "\n";
    }

    return 0;
}
