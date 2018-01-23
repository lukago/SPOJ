// redoran

#include <iostream>

using namespace std;

int costs[101], funs[101];

pair<int, int> knapsack(int budget, int partiesNum)
{
    int totalFun[partiesNum + 1][budget + 1];
    int totalCost[partiesNum + 1][budget + 1];

    for (int i = 0; i <= partiesNum; i++) {
        for (int j = 0; j <= budget; j++) {
            totalFun[i][j] = 0;
            totalCost[i][j] = 0;
        }
    }

    for (int i = 1; i <= partiesNum; i++) {
        for (int j = 1; j <= budget; j++) {
            if (costs[i - 1] <= j) {
                if (funs[i - 1] + totalFun[i - 1][j - costs[i - 1]] > totalFun[i - 1][j]) {
                    totalFun[i][j] = funs[i - 1] + totalFun[i - 1][j - costs[i - 1]];
                    totalCost[i][j] = costs[i - 1] + totalCost[i - 1][j - costs[i - 1]];
                } else {
                    totalFun[i][j] = totalFun[i - 1][j];
                    totalCost[i][j] = totalCost[i - 1][j];
                }
            } else {
                totalFun[i][j] = totalFun[i - 1][j];
                totalCost[i][j] = totalCost[i - 1][j];
            }
        }
    }

    int maxFun = totalFun[partiesNum][budget];
    int minCost = INT32_MAX;
    for (int i = 0; i <= budget; i++) {
        if (totalFun[partiesNum][i] == maxFun && totalCost[partiesNum][i] < minCost)
            minCost = totalCost[partiesNum][i];
    }

    return make_pair(minCost, totalFun[partiesNum][budget]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int budget, n;

    while (cin >> budget >> n && !(budget == 0 && n == 0)) {
        for (int i = 0; i < n; i++) {
            cin >> costs[i] >> funs[i];
        }

        if (budget == 0 || n == 0) {
            cout << "0 0\n";
        } else {
            auto result = knapsack(budget, n);
            cout << result.first << " " << result.second << "\n";
        }
    }

    return 0;
}

