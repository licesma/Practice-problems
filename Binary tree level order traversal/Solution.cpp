
#include <iostream>
#include<vector>
#include <stack>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        this->left= nullptr;this->right= nullptr;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<int> depths;queue<TreeNode*> nodes;
        vector<vector<int>> res;
        if(root != nullptr){
            nodes.push(root);depths.push(0);
        }
        while(!nodes.empty()){
            res[depths.front()].push_back(nodes.front()->val);
            if(nodes.front()->left != nullptr){
                nodes.push(nodes.front()->left);depths.push(depths.front()+1);
            }
            if(nodes.front()->right != nullptr){
                nodes.push(nodes.front()->right);depths.push(depths.front()+1);
            }
            nodes.pop();depths.pop();
        }
        return res;
    }
};
int main() {
    return 0;
    }