//
//  main.cpp
//  leetcode_january2
//
//  Created by Золотарева Марина Олеговна on 01.01.2021.
//


//Given two binary trees original and cloned and given a reference to a node target in the original tree.
//
//The cloned tree is a copy of the original tree.
//
//Return a reference to the same node in the cloned tree.
//
//Note that you are not allowed to change any of the two trees or the target node and the answer
//must be a reference to a node in the cloned tree.

#include <iostream>
#include <vector>

using std:: vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

void dfs(TreeNode* v, int value, TreeNode*& res){
    if(v){
        if(v -> val == value){
            res = v;
            return;
        }
        dfs(v -> left, value, res);
        dfs(v -> right, value, res);
    }
}
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    TreeNode* res = cloned;
    dfs(cloned, target -> val, res);
    std::cout << res -> val;
    return res;
}

int main() {
////    [7,4,3,null,null,6,19]
//    TreeNode six = TreeNode(6);
//    TreeNode nineteen = TreeNode(19);
//    TreeNode three = TreeNode(3);
//    TreeNode four = TreeNode(4);
//    TreeNode seven = TreeNode(7);
//    three.left = &six;
//    three.right = &nineteen;
//    seven.left = &four;
//    seven.right = &three;
////    TreeNode original = TreeNode(10);
////    TreeNode cloned = TreeNode(10);
//    std::cout << getTargetCopy(&seven, &seven, &three) -> val << std::endl;
    return 0;
}
