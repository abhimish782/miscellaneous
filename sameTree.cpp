#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int > pt,qt;
        levelorder(p,pt);
        levelorder(q,qt);
        if(pt==qt) return true;
        return false;
        
    }
    void levelorder(TreeNode* root,vector<int>&arr){
        if(root==NULL) return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr==NULL) arr.push_back(INT_MIN);
                else arr.push_back(curr->val);
                if(curr!=NULL&&curr->left!=NULL) q.push(curr->left);
                else q.push(NULL);
                if(curr!=NULL&&curr->right!=NULL) q.push(curr->right);
                else q.push(NULL);
            }
        }
        return ;
    }
};


bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        return(p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }


int main(){
    TreeNode* p=new TreeNode(1);
    p -> left = new TreeNode(2);  
    p -> right = new TreeNode(3);  
    p -> left -> left =   new TreeNode(4); 
    p -> right -> right = new TreeNode(5); 

    TreeNode* q=new TreeNode(1);
    q -> left = new TreeNode(2);  
    q -> right = new TreeNode(3);  
    q -> left -> left =   new TreeNode(4);   
    q -> right -> right = new TreeNode(5);

    // Solution1 sol;

    // cout<<sol.isSameTree(p,q)<<endl;

    //cout<<isSameTree(p,q)<<endl;
    return 0;
    
}