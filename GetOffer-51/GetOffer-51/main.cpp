//
//  main.cpp
//  GetOffer-51
//
//  Created by liweiye on 2020/5/30.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int ans = 0;

    void mergesort(int l,int r, vector<int>& nums, vector<int>& tmp){
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergesort(l , mid, nums, tmp);
        mergesort(mid+1, r, nums, tmp);
        int i=l,j=mid+1;
        for(int k=l;k<=r;k++){
            if(i>mid) tmp[k]=nums[j++];//nums[i]到nums[mid]已经全部填入tmp
            else if(j>r) tmp[k]=nums[i++];//nums[mid+1]到nums[j]已经全部填入tmp
            else if(nums[i]>nums[j]) {
                tmp[k]=nums[j++];
                ans+=mid-i+1;//i肯定小于j，且nums[i]到nums[mid]是升序排序，如果nums[i]>nums[j]，说明从nums[i]到nums[mid]和nums[j]都是逆序对
            }
            else tmp[k]=nums[i++];
        }
        for(int m=l;m<=r;m++) nums[m]=tmp[m];//
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(),0);//就是用来记录某个递归函数merge后的情况，然后复制更新nums
        mergesort(0, (int)nums.size() - 1, nums, tmp);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {7, 5, 6, 4};
    Solution s;
    int res = s.reversePairs(test);
    cout << res << endl;
    return 0;
}
