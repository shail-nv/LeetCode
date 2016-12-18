/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    bool right = false;
    bool left = false;
    
    if (!p && !q)
    {
        return true;
    }
    
    if (!p || !q)
    return false;
    
    if (p->val == q->val)
    {
        left = isSameTree(p->left, q->left);
        right = isSameTree(p->right, q->right);
    }
    
    return left && right;
    
    
}
