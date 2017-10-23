// Lukasz Golebiewski 203882
// https://adjule.pl/profile/lukago

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

const double WIDTH = 4000;
const double HEIGHT = 4000;

struct Point
{
    double x;
    double y;
};

inline double mind(const double &a, const double &b)
{
    return a < b ? a : b;
}

inline double absd(const double &a)
{
    return a < 0 ? -a : a;
}

inline double torusDist(const Point &a, const Point &b)
{
    double minX = mind(absd(a.x - b.x), WIDTH - absd(a.x - b.x));
    double minY = mind(absd(a.y - b.y), HEIGHT - absd(a.y - b.y));
    return sqrt(minX * minX + minY * minY);
}

std::pair<Point, Point> closestPairBrute(const std::vector<Point> &v, std::pair<Point, Point> result)
{
    double minDist = torusDist(result.first, result.second);
    double iterDist;

    for (auto it1 = v.begin(); it1 != v.end(); ++it1) {
        for (auto it2 = it1 + 1; it2 != v.end(); ++it2) {
            iterDist = torusDist(*it1, *it2);
            if (iterDist < minDist) {
                minDist = iterDist;
                result.first = *it1;
                result.second = *it2;
            }
        }
    }

    return result;
}

std::pair<Point, Point> closestPairOpt(const std::vector<Point> &v)
{
    if (v.size() <= 3)
        return closestPairBrute(v, {v[0], v[1]});

    size_t mid = v.size() / 2;

    std::vector<Point> vLeft(v.begin(), v.begin() + mid);
    std::vector<Point> vRight(v.begin() + mid, v.end());

    auto pL = closestPairOpt(vLeft);
    auto pR = closestPairOpt(vRight);
    auto pMin = torusDist(pL.first, pL.second) < torusDist(pR.first, pR.second) ? pL : pR;
    auto dMin = torusDist(pMin.first, pMin.second);

    std::vector<Point> strip;
    const Point &midPoint = v[mid];

    for (auto p : v) {
        if (absd(midPoint.x - p.x) < dMin)
            strip.push_back(p);
    }

    return closestPairBrute(strip, pMin);
}

std::pair<Point, Point> closest(std::vector<Point> &v)
{
    std::sort(v.begin(), v.end(), [](const Point &a, const Point &b) {
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    });

    return closestPairOpt(v);
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Point point;
    int testsNum, pointNum;

    std::cin >> testsNum;

    while (testsNum-- > 0) {
        std::cin >> pointNum;
        std::vector<Point> points;

        while (pointNum-- > 0) {
            std::cin >> point.x >> point.y;
            points.push_back(point);
        }

        auto result = closest(points);
        std::cout << result.first.x << " " << result.first.y << " "
                  << result.second.x << " " << result.second.y << "\n";
    }

    return EXIT_SUCCESS;
}