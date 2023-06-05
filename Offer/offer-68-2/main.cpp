#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    TreeNode* ans;
    // 递归方法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    // 定义root根节点的子树是否找到p或者是q
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))) {
            ans = root;
        }
        // 左子树或者右子树找到都算找到
        return left || right || root->val == p->val || root->val == q->val;
    }
};

class Solution2 {
public:
    unordered_map<TreeNode *, TreeNode *> father;
    unordered_map<TreeNode *, bool> isVisited;

    void dfs(TreeNode *root) {
        if (root->left) {
            father[root->left] = root;
            dfs(root->left);
        }
        if (root->right) {
            father[root->right] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root] = nullptr;
        // 构造father数组
        dfs(root);
        while(p != nullptr) {
            isVisited[p] = true;
            p = father[p];
        }
        while(q != nullptr) {

        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
