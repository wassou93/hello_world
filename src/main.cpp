#include <iostream>
#include <array>

using namespace std;

static const int N = 2;

array<array<int, N>, N> multiply_matrix(
    const array<array<int, N>, N>& mat1, 
    const array<array<int, N>, N>& mat2
    ) 
{
    array<array<int, N>, N> res = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}

int main(int, char**) {
    array<array<int, N>, N> m1 = {{{1, 2}, {3, 4}}};
    array<array<int, N>, N> m2 = {{{2, 3}, {4, 5}}};
    auto res = multiply_matrix(m1, m2);

    for (const auto& row : res) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
