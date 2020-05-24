//
//  main.cpp
//  LeetCode-111
//
//  Created by liweiye on 2019/10/6.
//  Copyright © 2019 liweiye. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;

    if (root -> left == NULL && root -> right == NULL) {
        return 1;
    }

    int res = INT_MAX;
    if (root -> left != NULL) {
        res = min(minDepth(root -> left), res);
    }

    if (root -> right != NULL) {
        res = min(minDepth(root -> right), res);
    }

    return res + 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
