#include <iostream>
#include <array>

using namespace std;

static const int N = 100;

array<array<int, N>, N> multiply_matrix(
    const array<array<int, N>, N> &mat1,
    const array<array<int, N>, N> &mat2)
{
    array<array<int, N>, N> res = {2};
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}

#include <chrono>

int main(int, char **)
{
    array<array<int, N>, N> m1 = {2};
    array<array<int, N>, N> m2 = {2};

    auto start = chrono::high_resolution_clock::now();
    auto res = multiply_matrix(m1, m2);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float, micro> elapsed = end - start;

    for (const auto &row : res)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << "Time taken: " << elapsed.count() << " microseconds" << endl;

    return 0;
}
