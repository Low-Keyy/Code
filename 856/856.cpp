#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s){
        stack<int> pteStack;
        for(auto v:s){
            if(v =='('){
                pteStack.push(-1);
            }else{
                int temp = 0;
                while(pteStack.top() != -1){
                    temp += pteStack.top();
                    pteStack.pop();
                }
                pteStack.pop();
                if(temp == 0){
                    temp = 1;
                }else{
                    temp*=2;
                }
                pteStack.push(temp);
            }

        }
        return pteStack.top();
    }
};

int main(int argc, char const *argv[])
{
    string s="(()(()))" ;
    Solution solution;
    cout<<solution.scoreOfParentheses(s)<<endl;
    return 0;
}