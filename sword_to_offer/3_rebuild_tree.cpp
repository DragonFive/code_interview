#include <vector>
#include <iostream>
using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty())
            return NULL;
        TreeNode *root = new TreeNode(pre[0]);
        //cout<<"new "<<root->val<<endl;
        if (pre.size() == 1){
            return root;
        }
        auto it = vin.begin();
        auto itp = pre.begin()+1;
        vector<int> left, right;
        vector<int> front, end;
        while (it!=vin.end()){
            if (*it == root->val)
                break;
            it++;
            itp++;
        }
        //cout<<"hehe"<<endl;
        copy(vin.begin(), it-1, back_inserter(left));
        //cout<<"hehe1"<<endl;
        copy(pre.begin()+1, itp, back_inserter(front));
        
        it++;
        copy(it,vin.end(),back_inserter(right));
        copy(itp, pre.end(), back_inserter(end));

        root->left = reConstructBinaryTree(front, left);
        root->right = reConstructBinaryTree(end, right);
        return root;
    }
    void preprint(TreeNode*root){
        if (!root) return;
        cout<<root->val<<endl;
        if (root->left) preprint(root->left);
        if (root->right) preprint(root->right);
    }
};

int main()
{
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> vin={4,7,2,1,5,3,8,6};
    Solution a;
    auto t = a.reConstructBinaryTree(pre, vin);
    a.preprint(t);
    return 0;
}