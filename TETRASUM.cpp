// spoj: pl.spoj.com/users/redoran/

#include <iostream>
#include <cstring>

using namespace std;

const uint64_t MOD = 1000000007;
const int len = 5;

const uint64_t matrix[len][len] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
};

struct Mat
{
    uint64_t mat[len][len] = {{0}};

    explicit Mat(int val)
    {
        if (val == 1) {
            for (int i = 0; i < len; i++)
                this->mat[i][i] = 1;
        }
    }
};

uint64_t mulMatVec(const Mat mat, const uint64_t vec[len])
{
    uint64_t resVec[len] = {0};
    Mat res(0);

    for (int row = 0; row < len; row++) {
        for (int col = 0; col < len; col++) {
            res.mat[row][col] = mat.mat[row][col] * vec[col];
            resVec[row] += res.mat[row][col];
        }
    }

    return resVec[len - 1];
}

Mat mulMatMat(const Mat mat1, const Mat mat2)
{
    Mat res(0);
    uint64_t tmp;

    for (int row = 0; row < len; row++) {
        for (int col = 0; col < len; col++) {
            for (int col2 = 0; col2 < len; col2++) {
                tmp = (mat1.mat[row][col2] * mat2.mat[col2][col]);
                res.mat[row][col] += (tmp) % MOD;
                res.mat[row][col] %= MOD;
            }
        }
    }

    return res;
}

Mat fastPow(const Mat mat, uint64_t n)
{
    Mat ret(1);
    Mat cp = mat;

    while (n > 0) {
        if (n % 2 == 0) {
            cp = mulMatMat(cp, cp);
            n /= 2;
        } else {
            ret = mulMatMat(ret, cp);
            n--;
        }
    }

    return ret;
}

uint64_t tetraSum(uint64_t m, uint64_t n)
{
    uint64_t start[] = {0, 0, 0, 1, 1}, sum1 = 0, sum2 = 0;
    Mat mat(0);
    memcpy(mat.mat, matrix, sizeof(matrix));

    if (m > 3) sum1 = mulMatVec(fastPow(mat, m - 4), start);

    if (n == 3) sum2 = 1;
    else if (n == 4) sum2 = 2;
    else if (n > 4) sum2 = mulMatVec(fastPow(mat, n - 3), start);

    return (sum2 - sum1 + MOD) % MOD;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    uint64_t t, m, n;
    cin >> t;

    while (t-- > 0) {
        cin >> m >> n;
        cout << tetraSum(m, n) << "\n";
    }

    return 0;
}