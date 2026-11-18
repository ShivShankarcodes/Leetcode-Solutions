class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          // Method-2
        if(root == NULL) return root = new TreeNode(val);
        else if(val > root->val){
            root->right = insertIntoBST(root->right,val);
        }else{
            root->left = insertIntoBST(root->left,val);
        }
        return root;


        //     Method-1
        // TreeNode* n = new TreeNode(val);
        // if(root == NULL) return root = n;
        // if(val > root->val){
        //     if(root->right != NULL)
        //         insertIntoBST(root->right,val);
        //     else 
        //         root->right = n;
        // }else{
        //     if(root->left != NULL)
        //         insertIntoBST(root->left,val);
        //     else
        //         root->left = n;
        // }
        // return root;
    }
};