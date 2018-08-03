/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int plen = pre.size();
        int vlen = vin.size();
        if(plen<1 || vlen <1)
            return NULL;
        vector<int> vleft, vright;
        vector<int> pleft, pright;
        int index=0;
        for(int i=0; i<plen; ++i) {
            if(vin[i] == pre[0]) {
                index = i;
                break;
            }
        }
        TreeNode *node = new TreeNode(pre[0]);
        
        for(int i=0; i<index; ++i) {
            vleft.push_back(vin[i]);
            pleft.push_back(pre[i+1]);
        }
        for(int i=index+1; i<vlen; ++i) {
            vright.push_back(vin[i]);
            pright.push_back(pre[i]);
        }
        node->left = reConstructBinaryTree(pleft, vleft);
        node->right = reConstructBinaryTree(pright, vright);
        return node;
    }
};
