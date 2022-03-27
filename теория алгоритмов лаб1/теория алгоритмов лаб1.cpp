#include <iostream>

int** Create(size_t n, size_t m) {
    int** M = new int * [n];
    for (size_t i = 0; i < n; ++i)
        M[i] = new int[m];
    return M;
}

void FillRandom(int** M, const size_t x, const size_t y) {
    srand((unsigned int)time(0));

    for (size_t row = 0; row < x; row++) {
        for (size_t col = 0; col < y; col++)
            M[row][col] = rand() % 10;
    }
}

void Print(int** M, size_t x, size_t y) {
    for (size_t row = 0; row < x; ++row) {
        for (size_t col = 0; col < y; ++col)
            std::cout << M[row][col] << ' ';
        std::cout << std::endl;
    }
}

void MultiplyMatrix(int &temp, size_t x, size_t y, size_t z, int ** A, int ** B, int ** C) {
    for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < z; j++) {
            C[i][j] = 0;
            for (size_t k = 0; k < y; k++) {
                C[i][j] += A[i][k] * B[k][j];
                temp++;
            }
        }
    }
}

void Free(int** M, size_t n) {
    for (size_t i = 0; i < n; ++i)
        delete[] M[i];
    delete[] M;
}

int main()
{
    size_t x, z;
    std::cin >> x >> z;
    std::cout << "num\t" << "Tэ1\t" << "Tэ2\t" << "Tэ3\t" << "T1\t" << "T2\t" << "T3\t" << "Tэ1 / T1\t" << "Tэ2 / T2\t" << "Tэ3 / T3\t" << std::endl;

    size_t y[5] = { 8, 32, 64, 88, 108 };
    for (size_t i = 0; i < 5; i++) {
        int temp = 0;
        int O_n = x * y[i] * z;

        int** A = Create(x, y[i]);
        int** B = Create(y[i], z);
        int** C = Create(x, z);

        FillRandom(A, x, y[i]);
        FillRandom(B, y[i], z);

        MultiplyMatrix(temp, x, y[i], z, A, B, C);

        //Print(C, x, z);
        std::cout << y[i] << '\t' << temp << '\t' << O_n << std::endl;

        Free(A, x);
        Free(B, y[i]);
        Free(C, x);
    }
    

    return 0;
}
