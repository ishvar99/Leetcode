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
#include <vector>
#include <algorithm>

class Solution {
    long long totalSum = 0;
    long long maxProd = 0;
    std::vector<long long> sums;

    int calculateSums(TreeNode* root) {
        if (!root) return 0;
        int currentSubtreeSum = root->val + calculateSums(root->left) + calculateSums(root->right);
        sums.push_back(currentSubtreeSum);
        return currentSubtreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        totalSum = calculateSums(root);
        
        for (long long s : sums) {
            long long currentProd = s * (totalSum - s);
            if (currentProd > maxProd) {
                maxProd = currentProd;
            }
        }
        
        return maxProd % 1000000007;
    }
};
