#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int sum=0;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void sumbst(TreeNode *root,int low,int high)
{
    if(root->left!=NULL)
        sumbst(root->left, low, high);
    if(root->right!=NULL)
        sumbst(root->right, low, high);
    if(root->val<=high&&root->val>=low)
        sum += root->val;
    return;
}
int main()
{
    int low, high;
    TreeNode *root;
    root=new TreeNode(10,new TreeNode(5,new TreeNode(3),new TreeNode(7)),new TreeNode(15,NULL,new TreeNode(18)));
    cin >> low >> high;
    sumbst(root, low, high);
    cout << sum << endl;
    return 0;
}