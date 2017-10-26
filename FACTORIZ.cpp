#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX 8000000

bool primesFlags[MAX];

std::vector<int> factoriz(int num)
{
    std::vector<int> factors;

    if (num == 1 || num == 2) {
        factors.push_back(num);
        return factors;
    }

    while (num % 2 == 0) {
        factors.push_back(2);
        num /= 2;
    }

    for (int64_t i = 3; i < num; i += 2) {
        if (primesFlags[i]) {
            for (int64_t j = i * i; j < num; j += i) {
                primesFlags[j] = false;
            }
            while (num % i == 0) {
                num /= i;
                factors.push_back(i);
            }
        }
    }

    if (num != 1) factors.push_back(num);

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
        auto sz = res.size();
        for (int i = 1; i < sz; i++) {
            std::cout << "*" << res[i];
        }
        std::cout << "\n";
    }

    return 0;
}
