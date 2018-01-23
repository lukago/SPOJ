// redoran

#include <iostream>
#include <queue>

using namespace std;

const int MAXBUGS = 2005;

bool bfs(int inter, vector<int> inters[], int colors[])
{
    int tmp;
    queue<int> frontier;

    frontier.push(inter);
    colors[inter] = 1;

    while (!frontier.empty()) {
        inter = frontier.front();
        frontier.pop();

        for (int i = 0; i < inters[inter].size(); i++) {
            tmp = inters[inter][i];

            if (colors[tmp] == colors[inter]) {
                return false;
            }

            if (!colors[tmp]) {
                colors[tmp] = 3 - colors[inter];
                frontier.push(tmp);
            }
        }
    }

    return true;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    vector<int> inters[MAXBUGS];
    int colors[MAXBUGS];
    int scenariosNum, bugsNum, interNum, inter1, inter2;
    bool bug;


    cin >> scenariosNum;
    for (int k = 1; k <= scenariosNum; k++) {
        cin >> bugsNum >> interNum;

        for (int i = 1; i <= bugsNum; i++) {
            inters[i].clear();
            colors[i] = 0;
        }

        for (int i = 0; i < interNum; i++) {
            cin >> inter1 >> inter2;
            inters[inter1].push_back(inter2);
            inters[inter2].push_back(inter1);
        }

        bug = false;
        for (int i = 1; i <= bugsNum; i++) {
            if (!colors[i] && !bfs(i, inters, colors)) {
                bug = true;
                break;
            }
        }

        cout << "Scenario #" << k << ":\n";
        if (bug) cout << "Suspicious bugs found!\n";
        else cout << "No suspicious bugs found!\n";
    }

    return 0;
}