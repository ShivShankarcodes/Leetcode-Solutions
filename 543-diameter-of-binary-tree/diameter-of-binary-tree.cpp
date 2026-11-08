class Solution {
public:
    int diameter ;

    int levels(TreeNode* root){
        if(root == NULL ) return 0;
        int leftLevels = levels(root->left);
        int rightLevels = levels(root->right);
        diameter = max(diameter , leftLevels + rightLevels);
        return 1 + max(leftLevels , rightLevels);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        levels(root);
        return diameter;
    }
};