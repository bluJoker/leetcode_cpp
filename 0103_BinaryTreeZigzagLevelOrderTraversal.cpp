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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(!root) return ans;
		
		queue<TreeNode*> q;
		q.push(root);
		bool flag = false;
		while(q.size()) {
			vector<int> path;
			for(int i = q.size() - 1; i >= 0; i--) {
				TreeNode* t = q.front();
				q.pop();
				path.push_back(t->val);
				if(t->left) q.push(t->left);
				if(t->right) q.push(t->right);
			}
			if(flag) reverse(path.begin(), path.end());
			flag = !flag;
			ans.push_back(path);
		}
		return ans;
    }
};