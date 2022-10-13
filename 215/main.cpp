#include <iostream>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int temp=nums[0];
        if(size ==1){
            return temp;
        }
        if(size == 2){
            return k==1?max(nums[0],nums[1]):min(nums[0],nums[1]);
        }
        vector<int> bigs;
        vector<int> smalls;

        int j=0;

        for(int x:nums){
            if(x<=temp)
            smalls.push_back(x);
            else{
                bigs.push_back(x);
                j++;
            }
        }
        if(k<=j){
            return findKthLargest(bigs,k);
        }else{
            return findKthLargest(smalls,k-j);
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    printf(findKthLargest(nums,2));
    return 0;
}
