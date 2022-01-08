//
// Created by tsandl on 08/01/2022.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class binaryTreeNode
{
public:
    char element = '#';
    binaryTreeNode *left = nullptr;
    binaryTreeNode *right = nullptr;
    binaryTreeNode(){}
    binaryTreeNode(int _element) : element(_element) {}
};

//先序创建二叉树
void createBinaryTree(binaryTreeNode * &tree)
{
    char tmp;
    std::cin >> tmp;
    if (tmp == '#') {
        tree = nullptr;
        return;
    }
    tree = new binaryTreeNode(tmp);
    createBinaryTree(tree->left);
    createBinaryTree(tree->right);
    return;
}
void createBinaryTree(binaryTreeNode * &tree,vector<char> &v,int &index)
{
    char tmp = v[index];
    if (tmp == '#') {
        index++;
        tree = nullptr;
        return;
    }
    tree = new binaryTreeNode(tmp);
    index++;
    createBinaryTree(tree->left,v,index);
    createBinaryTree(tree->right,v,index);
    return;
}
//先序遍历
void preOrder(binaryTreeNode *tree)
{
    if (tree) {
        std::cout << " " << tree->element;
        preOrder(tree->left);
        preOrder(tree->right);
    }
    return;
}

//先序遍历-非递归
void preOrderNonRecursive(binaryTreeNode *tree)
{
    std::stack<binaryTreeNode *> sta;
    binaryTreeNode *p = tree;
    while (!sta.empty() || p != nullptr) {
        while (p != nullptr) {
            std::cout << " " << p->element;
            sta.push(p);
            p = p->left;
        }
        if (!sta.empty()) {
            p = sta.top();
            sta.pop();
            p = p->right;
        }
    }
    return;
}

//中序遍历
void inOrder(binaryTreeNode *tree)
{
    if (tree) {
        inOrder(tree->left);
        std::cout << " " << tree->element;
        inOrder(tree->right);
    }
    return;
}

//中序遍历-非递归
void inOrderNonRecursive(binaryTreeNode *tree)
{
    std::stack<binaryTreeNode *> sta;
    binaryTreeNode *p = tree;
    while(!sta.empty() || p != nullptr) {
        while (p != nullptr) {
            sta.push(p);
            p = p->left;
        }
        if (!sta.empty()) {
            p = sta.top();
            sta.pop();
            std::cout << " " << p->element;
            p = p->right;
        }
    }
}

//后序遍历
void postOrder(binaryTreeNode *tree)
{
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout << " " << tree->element;
    }
    return;
}

//后序遍历-非递归
void postOrderNonRecursive(binaryTreeNode * tree)
{
    std::stack<binaryTreeNode *> sta;
    binaryTreeNode *cur = nullptr;
    binaryTreeNode *pre = nullptr;
    sta.push(tree);
    while (!sta.empty()) {
        cur = sta.top();
        if ((cur->left == nullptr && cur->right == nullptr) ||
            (pre != nullptr && (pre == cur->left || pre == cur->right))) {
            //没有孩子节点或孩子节点已经被访问过了，直接输出
            std::cout << " " << cur->element;
            sta.pop();
            pre = cur;
        } else {
            if (cur->right != nullptr) {
                sta.push(cur->right);
            }
            if (cur->left != nullptr) {
                sta.push(cur->left);
            }
        }
    }
    return;
}

//层次遍历
void levelOrder(binaryTreeNode *tree)
{
    std::queue<binaryTreeNode *> que;
    while (tree) {
        std::cout << " " << tree->element;
        if (tree->left) {
            que.push(tree->left);
        }
        if (tree->right) {
            que.push(tree->right);
        }
        if (que.empty()) {
            return;
        }
        tree = que.front();
        que.pop();
    }
}

int main(void)
{
    //a b d # g # # # c e # # f h # # #
    std::cout << "请输入先序序列用于构建二叉树:" << std::endl;
    binaryTreeNode *tree = nullptr;
    vector<char> v ={'a', 'b', 'd', '#', 'g', '#', '#', '#', 'c', 'e', '#', '#', 'f', 'h', '#', '#', '#'};
    int len = 0;
    createBinaryTree(tree,v,len);

    std::cout << "先序遍历结果:        ";
    preOrder(tree);
    std::cout << std::endl;

    std::cout << "先序遍历结果(非递归):";
    preOrderNonRecursive(tree);
    std::cout << std::endl;

    std::cout << "中序遍历结果:        ";
    inOrder(tree);
    std::cout << std::endl;

    std::cout << "中序遍历结果(非递归):";
    inOrderNonRecursive(tree);
    std::cout << std::endl;

    std::cout << "后序遍历结果:        ";
    postOrder(tree);
    std::cout << std::endl;

    std::cout << "后序遍历结果(非递归):";
    postOrderNonRecursive(tree);
    std::cout << std::endl;

    std::cout << "层次遍历结果(非递归):";
    levelOrder(tree);
    std::cout << std::endl;

    return 0;
}
