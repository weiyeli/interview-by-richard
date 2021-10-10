//
//  main.cpp
//  LeetCode-4
//
//  Created by liweiye on 2020/5/9.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 暴力法
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count1 = (int)nums1.size();
        int count2 = (int)nums2.size();
        int countSum = count1 + count2;

        vector<int> res;
        int l1 = 0, l2 = 0;
        while (l1 < count1 && l2 < count2) {
            if (nums1[l1] <= nums2[l2]) {
                res.push_back(nums1[l1]);
                l1++;
            } else {
                res.push_back(nums2[l2]);
                l2++;
            }
        }
        while (l1 < count1) {
            res.push_back(nums1[l1]);
            l1++;
        }
        while (l2 < count2) {
            res.push_back(nums2[l2]);
            l2++;
        }
        int middleIndex = countSum / 2;
        double ans = 0.0;
        if (countSum & 1) {
            ans = res[middleIndex] / 1.0;
            return ans;
        } else {
            ans = (res[middleIndex] + res[middleIndex - 1]) / 2.0;
            return ans;
        };
    }
};

// 第K小算法
// 时间复杂度: O(log(m+n))
// 空间复杂度: O(1)
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count1 = (int)nums1.size();
        int count2 = (int)nums2.size();
        int countSum = count1 + count2;
        int left = (countSum + 1) / 2;
        int right = (countSum + 2) / 2;
        //将偶数和奇数的情况合并，如果是奇数，会求两次同样的k
        return (getKth(nums1, 0, count1 - 1, nums2, 0, count2 - 1, left) + getKth(nums1, 0, count1 - 1, nums2, 0, count2 - 1, right)) * 0.5;
    }

private:
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;

        //让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1
        if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) return nums2[start2 + k - 1];

        if (k == 1) return min(nums1[start1], nums2[start2]);

        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;

        if (nums1[i] < nums2[j]) {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        } else {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
    }
};

// 公式推导法
// 时间复杂度: O(log(m+n))
// 空间复杂度: O(1)
class Solution3 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = (int)nums1.size();
        int n = (int)nums2.size();

        // 保证数组1一定最短
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        // 要保证分割线左边的元素中的最大值一定是中位数的组成
        // 不管是m+n之和奇数还是偶数，左边的元素都需要满足的个数为 (m+n+1)/2
        int totalLeft = (m + n + 1) / 2;

        // 这里定义两个变量: i 和 j
        // i: 第一个数组分割线右边的第一个元素的下标
        // j: 第二个数组分割线右边的第一个元素的下标
        // 我们可以得出这么几个公式：
        // 1. i == m
        // 2. j == n
        // 3. i + j == m + n

        // 下面使用二分查找的方法来寻找分割线的位置
        // 在 nums1 的区间 [0, m] 里寻找恰当的分割线
        // 使得 nums1[i-1] <= nums2[j] && nums2[j - 1] <= nums1[i]
        int left = 0, right = m;
        while (left < right) {
            int i = left + (right - left + 1) / 2;
            int j = totalLeft - i;
            if (nums1[i-1] > nums2[j]) {
                // 下一轮搜索区间: [left, i - 1]
                right = i - 1;
            } else {
                // 下一轮搜索区间: [i, right]
                left = i;
            }
        }

        int i = left, j = totalLeft - i;
        int nums1LeftMax = ((i == 0) ? INT_MIN: nums1[i-1]);
        int nums1RightMin = ((i == m) ? INT_MAX : nums1[i]);
        int nums2LeftMax = ((j == 0) ? INT_MIN: nums2[j-1]);
        int nums2RightMin = ((j == n) ? INT_MAX: nums2[j]);

        int sum = m + n;
        if (sum % 2) {
            // 基数
            return max(nums1LeftMax, nums2LeftMax);
        } else {
            // 偶数
            return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin))/ 2.0;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution3 s;
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
}
