
#include <iostream>
#include<vector>
#include <stack>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int i, n = nums.size();
    int f1, s1, f2, s2;
    if(n < 3)
        return false;
    f1=nums[0];
    bool two=false, anotherFirst = false;
    for (i = 1; i < n; i++){
        if(two){
            if(s1 < nums[i]){
                return true;
            }
            else if(f1 < nums[i] && nums[i] < s1){
                s1=nums[i];
            }else if(nums[i] < f1){
                if(anotherFirst){
                    if( nums[i] < f2){
                        nums[i]= f2;
                    }else if(f2 < nums[i]){
                        f1=f2;
                        s1=nums[i];
                        anotherFirst=false;
                    }
                }else{
                    f2=nums[i];
                    anotherFirst=true;
                }
            }

        }else{
            if(nums[i] < f1)
                f1 = nums[i];
            else if(f1 < nums[i]){
                two = true;
                s1= nums[i];
            }
        }
    }
    return false;
}


int main() {
    return 0;
}