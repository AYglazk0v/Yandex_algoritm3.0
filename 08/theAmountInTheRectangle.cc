#include <vector>
#include <iostream>

int main() {
    std::vector<std::vector<int>> matrix;
    int n, m, k;
    std::cin >> n >> m >>k;
    
    matrix.resize(n);
    for (int i = 0; i != n; ++i) {
        matrix[i].resize(m);
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            if (i - 1 >= 0) {
                matrix[i][j] += matrix[i - 1][j];
            }
            if (j - 1 >= 0) {
                matrix[i][j] += matrix[i][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
    }

    for (int i = 0, x1,x2,y1,y2, sum; i != k; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        sum = 0;
        x1--,y1--,x2--,y2--;
        sum += matrix[x2][y2];
        if (x1 - 1 >= 0) {
            sum -= matrix[x1 - 1][y2];
        }
        if (y1 - 1 >= 0) {
            sum -= matrix[x2][y1 - 1];
        }
        if (x1 - 1 >= 0 && y1 - 1>= 0) {
            sum += matrix[x1 - 1][y1 - 1];
        }
        std::cout << sum << std::endl;
    }

    return 0;
}