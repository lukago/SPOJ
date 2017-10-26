#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX 8000000

bool primesFlags[MAX];
int maxNum = 2;
std::vector<int> primes;
std::unordered_map<int, std::vector<int>> sols;

std::vector<int> factoriz(int num)
{
    std::vector<int> factors;

    if (num == 1 || num == 2) {
        factors.push_back(num);
        return factors;
    }

    if (num > maxNum) {

        for (int64_t i = maxNum; i * i <= num; i++) {
            if (primesFlags[i]) {
                for (int64_t j = i * i; j < num; j += i) {
                    primesFlags[j] = false;
                }
            }
        }

        for (int i = maxNum; i < num; i++) {
            if (primesFlags[i]) {
                primes.push_back(i);
            }
        }

        maxNum = num;
    }

    primes.push_back(num);

    int div = num;

    for (int i = 0; div > 1; i++) {
        if (div % primes[i] == 0) {
            factors.push_back(primes[i]);
            div /= primes[i];
            i--;
            auto search = sols.find(div);
            if (search != sols.end()) {
                primes.pop_back();
                factors.insert(factors.end(), search->second.begin(), search->second.end());
                goto end;
            }
        }
    }

    primes.pop_back();

end:
    sols[num] = factors;
    return factors;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++) {
        primesFlags[i] = true;
    }

    int num, t;
    std::cin >> t;

    while (t-- > 0) {
        std::cin >> num;

        auto res = factoriz(num);

        std::cout << res[0];
        for (int i = 1; i < res.size(); i++) {
            std::cout << "*" << res[i];
        }
        std::cout << "\n";
    }

    return 0;
}
