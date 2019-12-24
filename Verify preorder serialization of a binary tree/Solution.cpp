
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> sons;
        int i, n= preorder.length(), flag = -1;
        for(i=0; i<n; i++){
            cout<<"\n this is i: "<< i;
            if(!sons.empty()){
                if(sons.top() == 1)
                    sons.pop();
                else
                    sons.top()++;
            }else
                flag++;
            if(isdigit(preorder[i]))
                sons.push(0);
            while(i < n-1 && preorder[i] != ','){
                i++;
            }
        }
        if(0 < flag || !sons.empty())
            return false;
        else
            return true;
    }

};

int main() {
    return 0;
}