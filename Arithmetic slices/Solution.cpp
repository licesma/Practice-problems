
#include <iostream>
#include<vector>
#include <stack>
#include <algorithm>
using namespace std;
//Iterate through the whole array,
class Solution {
public:
    int slicesCombinations(int length){
        return (length-1)*(length-2)/2;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        int i, n=A.size(), length=1, res = 0, distance;
        if(n >= 3){
            distance= A[1]-A[0];
            for(int i=2; i<n; i++){
                if(A[i] - A[i-1] == distance)
                    length++;
                else{
                    if(length >= 3){
                        res += slicesCombinations(length);
                    }
                    length=1, distance= A[i] - A[i-1];
                }
            }
        }
        return res;
    }

};

int main() {
    return 0;
}