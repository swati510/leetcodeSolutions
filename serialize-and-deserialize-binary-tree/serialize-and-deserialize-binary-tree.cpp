/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serial="";
   int i;
    string serialize(TreeNode* root) {
         i=0;
        if(!root)return "_";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
       
        
        
        
    }
 TreeNode* deserialize(string data) {
     i=0;
     return mydeserialize(data);
 }
    // Decodes your encoded data to tree.
    TreeNode* mydeserialize(string data) {
   // cout<<data<<" "<<i<<endl;
  //   if(i>=data.length())return NULL;
     if(data[i]=='_'){
         i+=2;
         return NULL;
     }
    string res="";
    while(i<data.length()&&data[i]!=','){
        res.push_back(data[i]);
        i++;
    }
   int val=stoi(res);
 //cout<<val<<" "<<endl;
  TreeNode* root = new TreeNode(val);
  i++;
  root->left=mydeserialize(data);
  root->right=mydeserialize(data);
  return root;
    }
};