class Solution {
public:
    void invert(TreeNode* root){
        if(root == NULL) return;
        swap((root->left),(root->right));
        invert(root->left);
        invert(root->right);
    }
    bool isSame(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return isSame(p->left,q->left) && isSame(p->right,q->right);
    }
    bool isSymmetric(TreeNode* root) {
        invert(root->left);
        return isSame(root->left,root->right);
    }
};