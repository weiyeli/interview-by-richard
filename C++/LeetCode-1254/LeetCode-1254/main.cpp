//
//  main.cpp
//  LeetCode-1254
//
//  Created by liweiye on 2020/9/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int columns = (int)grid[0].size();
        int result = 0;
        if (rows == 0) return result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        result++;
                    }
                }
            }
        }
        return result;
    }

    // 我的理解，dfs返回的是这一次深搜有没有搜到水
    // 如果找到了，就返回true，没找到就返回false
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = (int)grid.size();
        int columns = (int)grid[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= columns) {
            return false;
        }
        // 当前i、j搜索的就是水了，那说明到头了，符合条件
        if (grid[i][j]) {
            return true;
        }
        grid[i][j] = 1;
        // 上下左右搜索
        bool up = dfs(grid, i-1, j);
        bool left = dfs(grid, i, j-1);
        bool right = dfs(grid, i, j+1);
        bool down = dfs(grid, i+1, j);
        if (up && left && right && down) {
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    Solution s;
    cout << s.closedIsland(grid) << endl;
}
