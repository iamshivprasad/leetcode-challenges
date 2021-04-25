// MergeTwoBinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode();

        if (root1 == nullptr)
        {
            newNode->val = root2->val;

            newNode->left = mergeTrees(nullptr, root2->left);
            newNode->right = mergeTrees(nullptr, root2->right);
        }
        else if(root2 == nullptr)
        {
            newNode->val = root1->val;

            newNode->left = mergeTrees(root1->left, nullptr);
            newNode->right = mergeTrees(root1->right, nullptr);
        }
        else
        {
            newNode->val = root1->val + root2->val;

            newNode->left = mergeTrees(root1->left, root2->left);
            newNode->right = mergeTrees(root1->right, root2->right);
        }

        return newNode;

    }

    TreeNode* mergeTreesIterative(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return nullptr;
        }



    }

};

int main()
{
    std::cout << "Hello World!\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
