class Solution {
public:
    void inorder(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;
        inorder(root->left , ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int i=0;
        while(i<ans.size()-1){
            if(ans[i] >= ans[i+1])  return false;
            i++;
        }
        return true;
    }
};
