#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
        int rows = matrix.size();
        if (rows <= 0) {
            return {};
        }
        int columns = matrix[0].size();
        if (columns <= 0) {
            return {};
        }
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int nums = rows * columns;
        vector<int> order(nums);
        int row = 0, column = 0;
        int directionIndex = 0;
        for (int index = 0; index < nums; index++) {
            order[index] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex].first;
            int nextColumn = column + directions[directionIndex].second;
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex].first;
            column += directions[directionIndex].second;
        }
        return order;
    }

    vector<int> spiralOrder2(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {};
    vector<int> order = s.spiralOrder(matrix);
    for (int i: order) {
        cout << i << " ";
    }
}
