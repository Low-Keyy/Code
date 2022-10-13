#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int size = arr.size();
        int index = 0;
        while(index < size){
            count++;
            int min = arr[index];
            int max = arr[index];
            int choice = 0;
            cout<<"index :"<<index<<endl;
            for(int i = index;i<size;i++){
                if(arr[i] <= min){
                    index = i+1;
                    if(choice == 1)
                    {
                        min = max;
                        choice = 0;
                    }
                }else{
                    if(max < arr[i])
                    max = arr[i];
                    choice = 1;
                }
                }
            }
            return count;
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {1,5,3,0,2,8,7,6,4};
    cout<<s.maxChunksToSorted(arr)<<endl;
    return 0;
}
