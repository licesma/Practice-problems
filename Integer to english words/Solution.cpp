
#include <iostream>
#include<vector>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;
//Iterate through the whole array,
class Solution {
private:
    vector<bool> A, B;
    vector<vector<int>> Graph;
    int belonging(int node){
        if(A[node])
            return 1;
        else if (B[node])
            return -1;
        else
            return 0;
    }
    void add(int node, int where){
        if(where == 1)
            A[node] = true;
        else if(where == -1)
            B[node] = true;
    }
    bool isValid(int node, int bel){
        int i, n=Graph[i].size(), partner;// I call partners two nodes that are connected
        for(i = 0; i < n; i++){
            partner= Graph[node][i];
            if(belonging(partner)== 0){
                add(partner, -bel);
                if(!isValid(partner, -bel)){
                    return false;
                }
            }else if(belonging(partner) == bel)
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int i,n = graph.size();
        if(n != 0) {
            Graph=graph;
            for (i = 0; i < n; i++) {
                A.push_back(false);
                B.push_back(false);
            }
            A[0]=true;
            return isValid((0,1);
        }
    }
};
int main() {
    ve


    return 0;
}