/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
     stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
       
        while(root){
            s.push(root);
            root=root->left;
        }
        
    }
    
    int next() {
        TreeNode* tp=s.top();
        int val=tp->val;
        s.pop();
    
       tp=tp->right;
        
        while(tp){
            s.push(tp);
            tp=tp->left;
            
        }
        return val;
        
    }
    
    bool hasNext() {
        return !s.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */