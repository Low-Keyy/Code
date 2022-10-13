#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        vector<int> ans(size);
        vector<int> idx1(size);
        vector<int> idx2(size);
  //使用iota对向量赋0~？的连续值
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);

  // 通过比较v的值对索引idx进行排序
        sort(idx1.begin(), idx1.end(), [&nums1](int i1, int i2) { return nums1[i1] > nums1[i2];});
        sort(idx2.begin(), idx2.end(), [&nums2](int i1, int i2) { return nums2[i1] > nums2[i2];});
        int i = 0;
        size--;
        for(auto &index :idx2){
            if(nums2[index]<nums1[idx1[i]]){
                ans[index] = nums1[idx1[i]];
                i++;
            }else{
                ans[index]=nums1[idx1[size]];
                size--;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {2,7,11,15};
    vector<int> nums2 = {1,10,4,11};
    Solution so;
    auto ans = so.advantageCount(nums1,nums2);
    for(auto s:ans){
        cout<<s<<endl;
    }
    return 0;
}
