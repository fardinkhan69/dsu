#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& employees, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(employees[mid]);
    node->left = buildTree(employees, start, mid - 1);
    node->right = buildTree(employees, mid + 1, end);
    return node;
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    int n;
    cin >> n;
    int numEmployees = (1 << n) - 1; // 2^n - 1
    vector<int> employees(numEmployees);
    for (int i = 0; i < numEmployees; ++i) {
        cin >> employees[i];
    }

    TreeNode* root = buildTree(employees, 0, numEmployees - 1);

    vector<int> hierarchy;
    inorderTraversal(root, hierarchy);

    for (int i = 0; i < hierarchy.size(); ++i) {
        cout << hierarchy[i] << " ";
    }
    cout << endl;

    return 0;
}