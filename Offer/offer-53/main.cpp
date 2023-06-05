#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* 搜索右边界 right */
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] <= target) i = m + 1;
            else j = m - 1;
        }
        int right = j;
        /* 若数组中无 target ，则提前返回 */
        if(j >= 0 && nums[j] != target) return 0;
        /* 搜索左边界 right */
        i = 0; j = (int)nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] < target) i = m + 1;
            else j = m - 1;
        }
        int left = i;
        cout << "right:" << right << " left:" << left;
        return right - left + 1;
    }

//    int binarySearch(vector<int>& nums, int target) {
//        int i = 0, j = nums.size() - 1;
//        while(i <= j) {
//            int m = (i + j) / 2;
//            if(nums[m] <= target) i = m + 1;
//            else j = m - 1;
//        }
//        cout << "i:" << i << " j:" << j;
//    }
};

int main() {
    Solution s;
    vector<int> arr = {8,8,8,8,8};
    s.search(arr, 8);
}
