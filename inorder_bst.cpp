#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define lli long long int
#define ld long double
#define vi vector<int>
#define vlli vector<lli>
#define pii pair<int, int>
#define pll pair<lli, lli>
#define pb push_back
#define all(v) v.begin(), v.end()

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;


class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};



void inorder(TreeNode* root)
{
    // base case
    if(root == NULL)
        return;

    // left subtree
    inorder(root->left);

    // current node
    cout << root->val << " ";

    // right subtree
    inorder(root->right);
}



// ========================= SAMPLE TREE =========================
//
//          4
//        /   \
//       2     6
//      / \   /
//     1   3 5
//
// inorder:
// 1 2 3 4 5 6
//
// ===============================================================

TreeNode* buildTree()
{
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(5);

    return root;
}



void solution()
{
    TreeNode* root = buildTree();

    cout << "Inorder Traversal:\n";

    inorder(root);

    cout << '\n';
}



int main()
{
    fast_io();

    int t = 1;
    // cin >> t;

    while(t--)
    {
        solution();
    }

    return 0;
}