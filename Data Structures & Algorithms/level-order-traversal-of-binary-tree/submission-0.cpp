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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lvlList;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            vector<int> lvl;

            for(int i=0; i<len; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front) {
                    lvl.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                }
            }
            if(lvl.size()) lvlList.push_back(lvl);
        }
        return lvlList;
    }
};
