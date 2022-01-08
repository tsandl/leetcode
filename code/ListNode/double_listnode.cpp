//
// Created by tsandl on 24/12/2021.
//
#include <iostream>

#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* pre;
};

// insert before head
void headInsert(vector<int> &ans,ListNode* &head){
    int n = ans.size();
    head->val = ans[0];
    head->next = NULL;
    head->pre = NULL;
    for(int i=1;i<n;i++){
        ListNode* node = new ListNode();
        node->val = ans[i];
        node->next = head;
        head->pre = node;
        node->pre = NULL;
        head = node;
    }
}

// insert behind head
void tailInsert(vector<int> &ans,ListNode* &head){
    int n = ans.size();
    ListNode* curr = head;
    curr->pre = NULL;
    for(auto i:ans){
        ListNode* node = new ListNode();
        node->val = i;
        node->next = NULL;
        node->pre = head;
        curr->next = node;
        curr = node;
    }
}

void visit(ListNode* head){
    ListNode* curr = head;
    while(curr!=nullptr){
        cout<<curr->val<<"->";
        curr = curr->next;
    }
}
int main(){
    vector<int> ans = {3,4,5,9,8,7};
    ListNode* head = new ListNode();
    headInsert(ans,head);
    visit(head);
    return 0;
}

