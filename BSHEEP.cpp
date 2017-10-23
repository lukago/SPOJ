// Lukasz Golebiewski 203882
// spoj: pl.spoj.com/users/redoran/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
    double x;
    double y;
    int id;

    bool operator<(const Point &other) const
    {
        if (y != other.y) return y < other.y;
        if (x != other.x) return x < other.x;
        return id < other.id;
    }
};

double ccw(const Point &a, const Point &b, const Point &c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

std::vector<Point> convexHull(std::vector<Point> &points)
{
    int n = points.size(), k = 0;
    if (n == 1)return points;
    std::vector<Point> hull(2 * points.size());

    std::sort(points.begin(), points.end());

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && ccw(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && ccw(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }

    hull.resize(k - 1);
    return hull;
}

double calcLen(const std::vector<Point> &points)
{
    double len = 0;
    for (int i = 0; i < points.size(); ++i) {
        double x = points[i].x - points[(i + 1)].x;
        double y = points[i].y - points[(i + 1)].y;
        len += sqrt(x * x + y * y);
    }
    return len;
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

        for (int i = 0; i < pointNum; i++) {
            std::cin >> point.x >> point.y;
            point.id = i + 1;
            points.push_back(point);
        }

        auto result = convexHull(points);

        printf("%.2f\n", calcLen(result));

        for (int i = 0; i < result.size(); i++)
            printf(i==0 ? "%d" : " %d", result[i].id);

        printf("\n");
    }

    return 0;
}
