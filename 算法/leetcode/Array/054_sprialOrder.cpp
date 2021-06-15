#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int startRow = 0, endRow = matrix.size()-1;
        int startCol = 0, endCol = matrix[0].size()-1;

        int row = 0, col = 0;
        std::vector<int> result;

        while (startRow <= endRow && startCol <= endCol) {
            for (int j = startCol; j <= endCol; ++j) {
                result.push_back(matrix[row][j]);
            }

            startRow++;
            col = endCol;

            if (startRow > endRow) return result;

            for (int i = startRow; i <= endRow; ++i) {
                result.push_back(matrix[i][col]);
            }

            row = endRow;
            endCol--;

            if (startCol > endCol) return result;

            for (int j = endCol; j >= startCol; j--) {
                result.push_back(matrix[row][j]);       
            }

            col = startCol;
            endRow--;

            if (startRow > endRow) return result;

            for (int i = endRow; i >= startRow; i--) {
                result.push_back(matrix[i][col]);
            }
            startCol++;
            row = startRow;
        }

        return result;
    }
};