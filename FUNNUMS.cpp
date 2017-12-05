#include<iostream>
#include <algorithm>

using namespace std;

uint64_t multiples[16];

uint64_t orderVal(const string &str)
{
    int sz = (int) str.size(), cnt;
    uint64_t sum = 0;

    for (int i = 0; i < sz; i++) {
        cnt = 0;
        for (int j = i + 1; j < sz; j++)
            if (str[i] > str[j]) cnt++;

        sum += cnt * multiples[sz - i - 1];
    }

    return sum + 1;
}

uint64_t printSol(string str, uint64_t order)
{
    uint64_t div;
    int sz = (int) str.size();

    while (true) {
        div = order / multiples[sz - 1];
        if (order % multiples[sz - 1] == 0) div--;

        cout << str[div];

        auto p = str.begin() + div;
        str.erase(p);

        order = order % multiples[sz - 1];
        sz--;

        if (sz == 2) {
            if (order == 1) cout << str[0] << str[1] << "\n";
            else if (order == 0) cout << str[1] << str[0] << "\n";
            break;
        }

        if (order == 0) {
            for (int i = sz - 1; i >= 0; i--) cout << str[i];
            cout << "\n";
            break;
        }
    }
}

int main()
{
    string str;
    uint64_t order;
    int t;
    multiples[0] = 1;

    cin >> t;

    for (int i = 1; i <= 15; i++)
        multiples[i] = i * multiples[i - 1];

    while (t-- > 0) {
        cin >> str >> order;

        if (order == 0 || str.size() == 1) {
            cout << str << endl;
            continue;
        }

        if (str.size() == 2) {
            if (order == 1)
                cout << str[1] << str[0] << endl;
            continue;
        }

        order += orderVal(str);
        sort(str.begin(), str.end());
        printSol(str, order);
    }
}