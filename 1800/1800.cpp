#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        stack<int> sumStack;
        sumStack.push(0);
        int sum=0;
        int best=0;
        for(auto index:nums){
            if(index > sumStack.top()){
                sumStack.push(index);
            }else{
                while(!sumStack.empty()){
                    sum+=sumStack.top();
                    sumStack.pop();
                }
                if(sum > best){
                    best = sum;
                }
                sumStack.push(index);
                sum=0;
            }
        }
        while(!sumStack.empty()){
                    sum+=sumStack.top();
                    sumStack.pop();
                }
                if(sum > best){
                    best = sum;
                }
        return best;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {10,20,30,5,10,50};
    Solution solution;
    cout<<solution.maxAscendingSum(nums)<<endl;
    return 0;
}