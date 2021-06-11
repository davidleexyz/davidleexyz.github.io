#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int startRow = 0, endRow = n - 1;
        int startCol = 0, endCol = n - 1;

        int row = 0, col = 0;
        int value = 1;

        while (startRow <= endRow && startCol <= endCol) {
            for (int j = startCol; j <= endCol; ++j) {
                matrix[row][j] = value;
                value++;
            }

            startRow++;
            col = endCol;

            for (int i = startRow; i <= endRow; ++i) {
                matrix[i][col] = value;
                value++;
            }

            row = endRow;
            endCol--;

            for (int j = endCol; j >= startCol; j--) {
                matrix[row][j] = value;
                value++;
            }

            col = startCol;
            endRow--;

            for (int i = endRow; i >= startRow; i--) {
                matrix[i][col] = value;
                value++;
            }
            startCol++;
            row = startRow;
        }

        return matrix;
    }
};