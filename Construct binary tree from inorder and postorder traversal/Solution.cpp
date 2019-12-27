
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
        this->val = val;
        this->left = nullptr; this->right = nullptr;
    }
};

void printf(vector <int> vec){
    cout<<"\n[";
    if(!vec.empty()){
        int i, n=vec.size();
        for (i= 0; i<n-1; i++){
            cout<<vec[i]<<", ";
        }
        cout<<vec[n-1];
    }
    cout<<"]";
}
vector<int> subVector(vector<int> vec, int start, int finish) {
    vector<int> subVec;
    int i=start;
    while(i <= finish) {
        subVec.push_back(vec[i]);
        i++;
    }
    return subVec;
}

TreeNode* returnHead(vector<int> inorder, vector<int> postorder, TreeNode* head){
    printf(inorder);printf(postorder);cout<<"\n\n";
    if(postorder.empty())
        return nullptr;
    head->val = postorder[postorder.size()-1]; int pos = 0;
    while(inorder[pos] != head->val) {
        pos++;
    }
    //cout<<"esto es pos"<< pos;


    vector<int> inorderLeft= subVector(inorder,0, pos-1), inorderRight= subVector(inorder,pos+1,inorder.size()-1), postorderLeft, postorderRight;
    pos=inorderLeft.size();
    postorderLeft= subVector(postorder,0,pos-1);
    postorderRight= subVector(postorder,pos, postorder.size()-2);
    TreeNode* left= new TreeNode(0), *right= new TreeNode(0);
    head->left= returnHead(inorderLeft, postorderLeft, left);
    head->right = returnHead(inorderRight, postorderRight, right);
    return head;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* head= new TreeNode(0);
    return returnHead(inorder, postorder, head);
}



int main() {
    return 0;
}