// redoran

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100007;

bool visited[MAX] = {false};
int total = 0;

int dfs(int root, vector<int> v[])
{
    int max0, max1 = -1, max2 = -1;
    visited[root] = true;

    for (int i = 0; i < v[root].size(); i++) {
        if (!visited[v[root][i]]) {
            max0 = dfs(v[root][i], v);
            if (max0 >= max1) {
                max2 = max1;
                max1 = max0;
            } else if (max0 > max2) {
                max2 = max0;
            }
        }
    }

    total = max(total, max1 + max2 + 2);

    return max1 + 1;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int nodesNum, edge1, edge2;

    cin >> nodesNum;

    vector<int> tree[nodesNum + 9];

    for (int i = 0; i < nodesNum - 1; i++) {
        cin >> edge1 >> edge2;
        tree[edge1].push_back(edge2);
        tree[edge2].push_back(edge1);
    }

    dfs(1, tree);
    cout << total << endl;

    return 0;
}