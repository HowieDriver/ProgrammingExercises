/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//这里都是从根节点到最底层的叶节点，长度不同是因为有些子树短，DFS会优先搜索长的
//关键在于DFS到最后不满足条件应该向前退一格
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root ==NULL) return ans;
        t.push_back(root->val);
        expectNumber -= root->val;
        
        if(expectNumber==0 && root->left==NULL && root->right==NULL)
            ans.push_back(t);
        if(root->left!=NULL) FindPath(root->left, expectNumber);
        if(root->right!=NULL) FindPath(root->right, expectNumber);
        t.pop_back();
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> t;
   
};


public class Solution {
    private ArrayList<ArrayList<Integer>> listAll = new ArrayList<ArrayList<Integer>>();
    private ArrayList<Integer> list = new ArrayList<Integer>();
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        if(root == null) return listAll;
        list.add(root.val);
        target -= root.val;
        if(target == 0 && root.left == null && root.right == null)
            listAll.add(new ArrayList<Integer>(list));
        FindPath(root.left, target);
        FindPath(root.right, target);
        list.remove(list.size()-1);
        return listAll;
    }
}
