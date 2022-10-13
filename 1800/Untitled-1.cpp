#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nums = {10,20,30,5,10,50};

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        stack<int> sumStack;
        sumStack.push(0);
        int sum=0;
        int best=0;
        for(auto &&index:nums){
            if(index > sumStack.top()){
                sumStack.push(index);
            }else{
                while{!sumStack.empty()}{
                    sum+=sumStack.pop();
                }
                if(sum > best){
                    best = sum;
                }
                sum=0;
            }
        }
        return best;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    printf("%d",solution.maxAscendingSum(nums));
    return 0;
}
