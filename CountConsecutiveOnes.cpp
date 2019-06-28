//
// Created by lices on 24/06/2019.
//

#include <cmath>
#include "iostream"
#include "vector"
using namespace std;

//Given an array nums and a value val, remove all instances of that value in-place and return the new length.

class Solution {
/*
 *
 * Given a positive integer n, find the number of non-negative integers less than or equal to n,
 * whose binary representations do NOT contain consecutive ones.
 *
 * The function OnesL returns the number of integers with consecutive ones before 2^length,
 * then the function onesE checks the distance between the number received and de two closest 2^i integers, and
 * recursively calls onesL
 */
public:  double onesL(int length, int rep){
        double res;
        res=0;
        if (length>=3) {
            res = pow(2, length - 3);
            for (int i = 3; i < length - 1; i++) {
                res = res + onesL(i,2);

            }
            if (rep==1) {
                res = res + onesL(length - 1,1);
            }
        }

        return res;
    }

public: int len(int num){
        int res; res=1;
        while(num>=2){
            res++;num=num/2;

        }
        return res;
    }
public: int onesE(int num,  int length){
        int center;center=(int) pow(2,length-1)+ pow (2,length-2);
        if (length>=2) {
            if (num >= center) {
                return onesL(length + 1, 1) + num - ((int) pow(2, length) - 1);
            } else {
                num=(num - (int) pow(2, length - 1));
                return onesL(length,1) + onesE(num,len(num));

            }
        }else{
            return 0;
        }

    }
public:
    int findIntegers(int num) {
        return num +1 -onesE(num,len(num));
    }

};