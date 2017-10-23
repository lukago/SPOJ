// Lukasz Golebiewski 203882
// spoj: pl.spoj.com/users/redoran/

#include <iostream>

using namespace std;

struct Vec3d
{
    int64_t x;
    int64_t y;
    int64_t z;

    explicit Vec3d(int64_t x = 0, int64_t y = 0, int64_t z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator==(const Vec3d &lhs)
    {
        return lhs.x == this->x && lhs.y == this->y && lhs.z == this->z;
    }

    bool operator!=(const Vec3d &lhs)
    {
        return lhs.x != this->x || lhs.y != this->y || lhs.z != this->z;
    }

    Vec3d operator-(const Vec3d &lhs) const
    {
        return Vec3d(this->x - lhs.x, this->y - lhs.y, this->z - lhs.z);
    }
};

Vec3d crossProduct(Vec3d v, Vec3d u)
{
    Vec3d vec3d;
    vec3d.x = u.y * v.z - u.z * v.y;
    vec3d.y = u.z * v.x - u.x * v.z;
    vec3d.z = u.x * v.y - u.y * v.x;
    return vec3d;
}

int64_t dotProduct(Vec3d v, Vec3d u)
{
    return v.x * u.x + v.y * u.y + v.z * u.z;
}

bool vecOnePlane(Vec3d vectors[], int len)
{
    if (len <= 3)
    {
        return true;
    }

    Vec3d vecZero(0, 0, 0);
    Vec3d vecCross(0, 0, 0);

    for (int i = 0; i < len; i++)
    {
        vecCross = crossProduct(vectors[1] - vectors[0], vectors[i] - vectors[0]);

        if (vecCross != vecZero)
        {
            break;
        }
    }

    if (vecCross == vecZero)
    {
        return true;
    }

    for (int i = 0; i < len; i++)
    {
        if (dotProduct(vecCross, vectors[i] - vectors[0]) != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tests;
    int64_t a, b, c;
    cin >> tests;
    Vec3d *vectors = new Vec3d[tests];

    for (int i = 0; i < tests; i++)
    {
        cin >> a >> b >> c;
        vectors[i] = Vec3d(a, b, c);
    }

    if (vecOnePlane(vectors, tests)) cout << "TAK\n";
    else cout << "NIE\n";

    delete[] vectors;
    return 0;
}