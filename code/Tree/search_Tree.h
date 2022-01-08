//
// Created by tsandl on 03/01/2022.
//

#ifndef LEETCODE_SEARCH_TREE_H
#define LEETCODE_SEARCH_TREE_H
#pragma once
//二叉搜索数的模拟实现
#include<iostream>
using std::cout;
using std::endl;
template<class T>
struct BSTNode
{
    BSTNode(const T& key = T())
            : _left(nullptr)
            , _right(nullptr)
            , _key(key)
    {}

    BSTNode<T>* _left;
    BSTNode<T>* _right;
    T _key;
};


template<class T>
class BSTree
{
    typedef BSTNode<T> Node;
public:
    BSTree()
            : _root(nullptr)
    {}

    ~BSTree()
    {
        Destroy(_root);
    }
    //拷贝构造
    BSTree(const BSTree<T>& tree)
    {
        _root = Copy(tree._root);
    }
    Node* Copy(Node* root)
    {
        if (root == nullptr)
            return nullptr;
        Node* tmp = new Node;
        tmp->_key = root->_key;
        tmp->_left = Copy(root->_left);
        tmp->_right = Copy(root->_right);
        return tmp;
    }
    BSTree& operator=(const BSTree& tree)
    {
        if (this != &tree)
        {
            Destroy(this->_root);
            this->_root = Copy(tree._root);
        }
        return *this;
    }
    bool Insert(const T& key)
    {
        //如果树为空，直接创建一个新结点进行插入
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        //查找要插入的位置
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            parent = cur;
            if (key < cur->_key)
            {
                cur = cur->_left;
            }
            else if (key > cur->_key)
            {
                cur = cur->_right;
            }
            else
            {
                return false;//元素在树中已经存在，不用重新插入
            }
        }
        //插入元素
        cur = new Node(key);
        if (key < parent->_key)
        {
            parent->_left = cur;
        }
        else
        {
            parent->_right = cur;
        }
        return true;
    }
    Node* Find(const T& key)
    {
        Node* cur = _root;
        while (cur)
        {
            if (cur->_key == key)
            {
                return cur;
            }
            else if (key < cur->_key)
            {
                cur = cur->_left;
            }
            else
            {
                cur = cur->_right;
            }
        }
        return nullptr;
    }
    bool Erase(const T& key)
    {
        //如果树为空，删除失败
        if (_root == nullptr)
        {
            return false;
        }
        //查找key在树中的位置
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (key == cur->_key)
            {
                break;
            }
            else if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                parent = cur;
                cur = cur->_right;
            }
        }

        //遍历了整棵树，如果key不在树中，无法删除
        if (cur == nullptr)
        {
            return false;
        }
        //如果在树中找到了key，进行删除结点,要分三种情况：
        //1.该结点只有右孩子
        //2.该结点只有左孩子
        //3.该结点左右子树都存在
        if (cur->_left == nullptr)
        {
            //情况1：
            //只有根结点和根的右孩子，此时要删除的结点正好是树的根
            if (cur == _root)
            {
                _root = cur->_right;
            }
            else
            {
                //或该结点不是树的根
                if (cur == parent->_left)
                {
                    parent->_left = cur->_right;
                }
                else
                {
                    parent->_right = cur->_right;
                }
            }
        }
            //情况2：
        else if (cur->_right == nullptr)
        {
            if (cur == _root)
            {
                _root = cur->_left;
            }
            else
            {
                if (cur == parent->_right)
                {
                    parent->_right = cur->_left;
                }
                else
                {
                    parent->_left = cur->_left;
                }
            }

        }
        else
        {
            //当前结点左右孩子都存在，直接删除不好删，可以在其子树中找一个替代结点，比如找其左子树中的最大结点，即左子树中最右侧的结点，或者找其右子树中最小的结点，即右子树中最小的结点。替换结点找到后，将替代结点中的值交给待删除结点，转换成删除替代结点。
            if (cur->_left != nullptr || cur->_right != nullptr)
            {
                //找右子树中最小的结点替换待删除的结点
                Node* repalce = cur->_right;
                parent = cur;
                while (repalce->_left)
                {
                    parent = repalce;
                    repalce = repalce->_left;
                }
                cur->_key = repalce->_key;
                if (repalce == parent->_left)
                {
                    parent->_left = repalce->_right;
                }
                else
                {
                    parent->_right = repalce->_right;
                }
                delete repalce;
                repalce = nullptr;
            }
            return true;
        }
        return false;
    }
    void Inorder()
    {
        _Inorder(_root);
    }

private:
    void _Inorder(Node* root)
    {
        if (root)
        {
            _Inorder(root->_left);
            cout << root->_key << " ";
            _Inorder(root->_right);
        }
    }
    void Destroy(Node*& root)
    {
        if (root)
        {
            Destroy(root->_left);
            Destroy(root->_right);
            root = nullptr;
        }
    }
private:
    Node* _root;
};
void TestBSTree()
{
    BSTree<int> BST1;
    BST1.Insert(5);
    BST1.Insert(3);
    BST1.Insert(4);
    BST1.Insert(1);
    BST1.Insert(7);
    BST1.Insert(8);
    BST1.Insert(2);
    BST1.Insert(6);
    BST1.Insert(0);
    BST1.Insert(9);
    BST1.Inorder();
    cout << endl;
    BST1.Find(10);
    BST1.Erase(7);
    BST1.Inorder();
    cout << endl;
    BSTree<int> copy(BST1);
    BSTree<int> BST2;
    BST2 = BST1;
    copy.Inorder();
    cout << endl;
    BST2.Inorder();
}

#endif //LEETCODE_SEARCH_TREE_H
