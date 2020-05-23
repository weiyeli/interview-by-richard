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
        int n = (int)nums1.size();
        int m = (int)nums2.size();

        if (n > m)  //保证数组1一定最短
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

        while (lo <= hi)   //二分
        {
            c1 = (lo + hi) / 2;  //c1是二分的结果
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
}
