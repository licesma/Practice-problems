//
// Created by lices on 24/06/2019.
//

#include "iostream"
#include "vector"
using namespace std;

//Given an array nums and a value val, remove all instances of that value in-place and return the new length.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,n;n=nums.size();
        for (i=0;i<n;i++){
            if (nums[i]==val){
                nums[i]=nums[n-1];
                nums.pop_back();
                i--;n--;
            }
        }
        return n;
    }
};