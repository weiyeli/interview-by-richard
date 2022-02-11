//
//  main.cpp
//  LeetCode-215
//
//  Created by ricardooli on 2022/2/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = partition(a, l, r);
        if (q == index) {
            return a[q];
        } else if (index < q) {
            return quickSelect(a, l, q-1, index);
        } else {
            return quickSelect(a, q+1, r, index);
        }
    }
    
    int partition(vector<int>& a, int l, int r) {
        swap(a[l], a[rand()%(r-l+1)+l]);
        int v = a[l];
        // a[l+1...i] <= v; a(j...r] >= v
        int i = l+1, j = r;
        while (true) {
            while (i <= r && a[i] < v) {
                i++;
            }
            while (j >= l+1 && a[j] > v) {
                j--;
            }
            if (i > j) {
                break;
            }
            swap(a[i], a[j]);
            i++;
            j--;
        }
        swap(a[l], a[j]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, (int)nums.size() - 1, (int)nums.size() - k);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> a = {3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(a, 4) << endl;
    return 0;
}
