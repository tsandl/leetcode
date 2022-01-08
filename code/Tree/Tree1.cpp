//
// Created by tsandl on 24/12/2021.
//
#include<iostream>
using namespace std;
typedef struct node{
    int val;
    node* lchild;
    node* rchild;
} Node,*Tree;
void insert(Node* &root,int value){

    Node* newnode = new node();
    newnode->val = value;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    if(root == NULL){
        root = newnode;
    } else{
        Node* temp = root;//从树根开始
        while(temp != NULL){
            if(value < temp->val){
                if(temp->lchild != NULL){
                    temp = temp->lchild;
                }else{
                    temp->lchild = newnode;
                    return;
                }
            }else{
                if(temp->rchild != NULL){
                    temp = temp->rchild;
                }else{
                    temp->rchild = newnode;
                    return;
                }
            }
        }
    }
}
void inorder(Node* node)//树的中序遍历
{
    if (node != NULL)
    {
        inorder(node->lchild);
        cout<<node->val<<" ";
        inorder(node->rchild);
    }
}
int main(){
    int n,value = 0;
    Node * root = NULL;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>value;
        insert(root,value);
    }
    cout<<"start inorder"<<endl;
    inorder(root);


    return 0;
}