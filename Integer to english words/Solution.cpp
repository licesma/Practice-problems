
#include <iostream>
#include<vector>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;
//Iterate through the whole array,
class Solution {
public:
    vector<string> digits;
    vector<string> tenths;
    string numberToWords(int num) {
        digits.push_back("");digits.push_back("One");digits.push_back("Two");digits.push_back("Three");digits.push_back("Four");digits.push_back("Five");
        digits.push_back("Six");digits.push_back("Seven");digits.push_back("Eight");digits.push_back("Nine");digits.push_back("Ten");digits.push_back("Eleven");digits.push_back("Twelve");
        digits.push_back("Thirteen");digits.push_back("Fourteen");digits.push_back("Fifteen");digits.push_back("Sixteen");digits.push_back("Seventeen");digits.push_back("Eighteen");digits.push_back("Nineteen");
        tenths.push_back("");tenths.push_back("");tenths.push_back("Twenty");tenths.push_back("Thirty");tenths.push_back("Forty");tenths.push_back("Fifty");tenths.push_back("Sixty");tenths.push_back("Seventy");
        tenths.push_back("Eighty");tenths.push_back("Ninety");
        stringstream ss;ss<<num;string st1 = ss.str(), st2, res;
        int n= st1.length();
        while(n<10){
            st2.append("0");n++;
        }
        st2.append(st1);
        string billion = toWord(0,0,st2[0]- 48), million= toWord(st2[1] -48, st2[2] - 48, st2[3] - 48), thousand = toWord(st2[4] - 48, st2[5] - 48, st2[6] - 48), hundred= toWord(st2[7] - 48, st2[8] - 48, st2[9] - 48);
        bool empty=true;
        if(billion.compare("") != 0){
            res.append(billion);res.append(" Billion");empty=false;
        }
        if(million.compare("") != 0){
            if(!empty)
                res.append(" ");
            res.append(million);res.append(" Million");empty=false;
        }
        if(thousand.compare("")!= 0){
            if(!empty)
                res.append(" ");
            res.append(thousand);res.append(" Thousand");empty=false;
        }
        if(hundred.compare("") != 0) {
            if(!empty)
                res.append(" ");
            res.append(hundred);empty=false;
        }else if(empty){
            return "Cero";
        }
        return res;
    }
    string toWord(int hundred, int ten, int one){
        if(ten == 1){
            one+=10;
        }
        string res;bool empty=true;
        if(hundred != 0){
            res.append(digits[hundred]);  res.append(" Hundred");empty=false;
        }
        if(1 < ten) {
            if(!empty)
                res.append(" ");
            res.append(tenths[ten]);empty=false;
        }
        if(one != 0){
            if(!empty)
                res.append(" ");
            res.append(digits[one]);
         }
        return res;
    }
};
int main() {
    
    return 0;
}