// redoran

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

struct Node
{

    Node *children[SIZE];
    bool isLeaf;

    Node()
    {
        isLeaf = false;
        for (auto &child : children) child = nullptr;
    }
};

bool canInsert(Node *node, string str)
{
    for (char ch : str) {
        int cur = ch - '0';

        if (node->children[cur] == nullptr) {
            Node *temp = new Node();
            node->children[cur] = temp;
        }

        node = node->children[cur];
        if (node->isLeaf) return false;
    }

    node->isLeaf = true;
    return true;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;

    while (t-- > 0) {
        cin >> n;

        vector<string> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        sort(vec.begin(), vec.end());

        bool res = true;
        Node *root = new Node();

        for (int i = 0; i < n && res; i++)
            res = canInsert(root, vec[i]);

        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}