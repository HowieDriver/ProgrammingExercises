/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> lit;
        if(root == NULL) return ans;
        
        lit.push(root);
        while(!lit.empty()) {
            TreeNode* node = lit.front();
            lit.pop();
            ans.push_back(node->val);
            
            if(node->left != NULL)
                lit.push(node->left);
            if(node->right != NULL)
                lit.push(node->right);
        }
        return ans;
    }
    
};
