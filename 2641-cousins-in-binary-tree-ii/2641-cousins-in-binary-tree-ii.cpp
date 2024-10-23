#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        // Queue for level-order traversal (node, parent node)
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        // Iterate through each level
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;  // To store the sum of all nodes in the current level
            unordered_map<TreeNode*, int> parentSum;  // To store the sum of siblings

            vector<pair<TreeNode*, TreeNode*>> currentLevel;
            
            // Traverse all nodes at the current level and calculate the level sum
            for (int i = 0; i < levelSize; i++) {
                auto [node, parent] = q.front();
                q.pop();
                if (node == nullptr) continue;  // Ensure node is not null

                // Add current node's value to the level sum
                levelSum += node->val;
                currentLevel.push_back({node, parent});

                // Push children to the queue for the next level
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            // Calculate the sum of siblings for each parent
            for (const auto& [node, parent] : currentLevel) {
                if (parent) {
                    parentSum[parent] += node->val;  // Sibling sum
                }
            }

            // Traverse all nodes again to replace their values with cousin sum
            for (const auto& [node, parent] : currentLevel) {
                if (parent) {
                    // Cousin sum = level sum - sibling sum
                    node->val = levelSum - parentSum[parent];
                } else {
                    // Root node has no cousins, set to 0
                    node->val = 0;
                }
            }
        }

        return root;
    }
};
