
#include <iostream>
#include<vector>
#include <stack>
#include <algorithm>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val=val;
    }
};
class Solution {
    vector<int> res;
    int targetVal, k;
public:
    void addNode(TreeNode *root, int distance){
        if(root != nullptr){
            if(distance != 0){
                addNode(root->left, distance-1);
                addNode(root->right, distance-1);
            }else
                res.push_back(root->val);
        }
    }
    int findTarget(TreeNode *root){
        if(root != nullptr){
            if(root->val == targetVal){
                addNode(root,k);
                return 1;
            }else{
                int left = findTarget(root->left), right = findTarget(root->right);
                if(left != 0){
                    if(left < k){
                        addNode(root->right, k - left -1 );
                        return left +1;
                    }else if (left == k){
                        addNode(root,0);
                        return 0;
                    }
                }else if(right != 0){
                    if(right < k){
                        addNode(root-> left, k - right -1);
                        return right + 1;
                    }else if(right == k){
                        addNode(root,0);
                        return 0;
                    }
                }
            }
        }
        return 0;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        targetVal= target->val;
        k=K;
        findTarget(root);
        return res;
    }
};

int main() {
    return 0;
}