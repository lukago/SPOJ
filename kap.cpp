// szkopuł: lukago

#include <iostream>
#include <set>
#include <queue>

const int MAX_ISLANDS = 200001;

struct Island
{
    int index;
    int x;
    int y;

    explicit Island(int index = 0, int x = 0, int y = 0) : index(index), x(x), y(y)
    {}

    bool operator<(const Island &b) const
    {
        return index < b.index;
    }
};

int findMinTime(std::priority_queue<std::pair<int, Island> > queue,
                std::set<Island, bool (*)(const Island &, const Island &)> islandsX,
                std::set<Island, bool (*)(const Island &, const Island &)> islandsY)
{
    bool checked[MAX_ISLANDS] = {false};

    while (!queue.empty()) {
        int candidate = -queue.top().first;
        Island island = queue.top().second;
        queue.pop();

        if (checked[island.index])
            continue;

        checked[island.index] = true;

        if (island.index == islandsX.size())
            return candidate;

        auto iter1 = islandsX.find(island);
        auto iter2 = iter1;

        if (--iter1 != islandsX.end())
            queue.push(std::make_pair(-candidate - (island.x - iter1->x), *iter1));
        if (++iter2 != islandsX.end())
            queue.push(std::make_pair(-candidate - (iter2->x - island.x), *iter2));

        iter1 = islandsY.find(island);
        iter2 = iter1;

        if (--iter1 != islandsY.end())
            queue.push(std::make_pair(-candidate - (island.y - iter1->y), *iter1));
        if (++iter2 != islandsY.end())
            queue.push(std::make_pair(-candidate - (iter2->y - island.y), *iter2));

    }
}


int main()
{
    int n;
    std::cin >> n;

    std::set<Island, bool (*)(const Island &, const Island &)> islandsX(
            [](const Island &a, const Island &b) {
                return a.x < b.x or (a.x == b.x and a.y < b.y);
            });

    std::set<Island, bool (*)(const Island &, const Island &)> islandsY(
            [](const Island &a, const Island &b) {
                return a.y < b.y or (a.y == b.y and a.x < b.x);
            });

    std::priority_queue<std::pair<int, Island> > queue;

    for (int i = 1; i <= n; i++) {
        Island island;
        std::cin >> island.x >> island.y;
        island.index = i;

        if (i == 1)
            queue.push(std::make_pair(0, island));

        islandsX.insert(island);
        islandsY.insert(island);
    }

    std::cout << findMinTime(queue, islandsX, islandsY);

    return 0;
}
