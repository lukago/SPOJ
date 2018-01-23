// redoran

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

struct Edge
{
    int src;
    int dest;
    int weight;

    explicit Edge(int src = 0, int dest = 0, int weight = 0)
            : src(src), dest(dest), weight(weight)
    {}
};

struct Subset
{
    int parent;
    int rank;
};

struct Graph
{
    int nodesNum;
    std::vector<Edge> edges;

    explicit Graph(int nodesNum) : nodesNum(nodesNum)
    {}
};

int find(std::vector<Subset> &subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void makeUnion(std::vector<Subset> &subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int kruksalMstSum(Graph graph)
{
    std::vector<Edge> result(graph.nodesNum);
    std::vector<Subset> subsets(graph.nodesNum);

    int edgesCnter = 0;
    int iter = 0;

    std::sort(graph.edges.begin(), graph.edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    for (int i = 0; i < graph.nodesNum; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    while (edgesCnter < graph.nodesNum - 1) {
        Edge next = graph.edges[iter++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            result[edgesCnter++] = next;
            makeUnion(subsets, x, y);
        }
    }

    int sum = 0;
    for (int i = 0; i < graph.nodesNum; i++)
        sum += result[i].weight;

    return sum;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph graph(n);

    int i, j, k;
    while (m-- > 0) {
        std::cin >> i >> j >> k;
        graph.edges.emplace_back(i, j, k);
    }

    std::cout << kruksalMstSum(graph) << std::endl;

    return 0;
}

