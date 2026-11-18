class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* n = new TreeNode(val);
        if(root == NULL) return root = n;
        if(val > root->val){
            if(root->right != NULL)
                insertIntoBST(root->right,val);
            else 
                root->right = n;
        }else{
            if(root->left != NULL)
                insertIntoBST(root->left,val);
            else
                root->left = n;
        }
        return root;
    }
};