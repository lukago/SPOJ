// Lukasz Golebiewski 203882
// spoj: pl.spoj.com/users/redoran/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

const double DBL_MAX = std::numeric_limits<double>::max();
const double WIDTH = 4000;
const double HEIGHT = 4000;

struct Point
{
    short x;
    short y;
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

std::pair<Point, Point> closestPairBrute(const std::vector<Point> &v, double min = DBL_MAX)
{
    std::pair<Point, Point> result(v[0], v[1]);
    double iterDist;

    for (auto it1 = v.begin(); it1 != v.end(); ++it1)
        for (auto it2 = it1 + 1; it2 != v.end() && absd(it2->y - it1->y) < min; ++it2) {
            iterDist = torusDist(*it1, *it2);
            if (iterDist < min) {
                min = iterDist;
                result.first = *it1;
                result.second = *it2;
            }
        }

    return result;
}

std::pair<Point, Point> closestPairOpt(const std::vector<Point> &v)
{
    if (v.size() <= 3)
        return closestPairBrute(v);

    size_t mid = v.size() / 2;

    std::vector<Point> Pl(v.begin(), v.begin() + mid);
    std::vector<Point> Pr(v.begin() + mid, v.end());

    auto dl = closestPairOpt(Pl);
    auto dr = closestPairOpt(Pr);
    auto d = torusDist(dl.first, dl.second) < torusDist(dr.first, dr.second) ? dl : dr;
    double dlen = torusDist(d.first, d.second);

    std::vector<Point> strip;
    const Point &midPoint = v[mid];

    for (auto p : v)
        if (absd(midPoint.x - p.x) < dlen)
            strip.push_back(p);

    std::sort(strip.begin(), strip.end(), [](const Point &a, const Point &b) {
        return (a.y == b.y) ? (a.x < b.x) : (a.y < b.y);
    });

    auto tmp = closestPairBrute(strip, dlen);
    auto result = torusDist(tmp.first, tmp.second) < dlen ? tmp : d;

    return result;
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
    std::vector<Point> points;
    int testsNum, pointNum;

    std::cin >> testsNum;

    while (testsNum-- > 0) {
        std::cin >> pointNum;

        for (int i = 0; i < pointNum; i++) {
            std::cin >> point.x >> point.y;
            points.push_back(point);
        }

        auto result = closest(points);
        std::cout << result.first.x << " " << result.first.y << " "
                  << result.second.x << " " << result.second.y << "\n";
    }

    return 0;
}