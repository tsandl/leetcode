#include <iostream>

#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

void headInsert(vector<int> &ans,ListNode* &head){
    int n = ans.size();
//    head = new ListNode();
    head->val = ans[0];
    head->next = NULL;
    for(int i=1;i<n;i++){
        ListNode* node = new ListNode();
        node->val = ans[i];
        node->next = head;
        head = node;
    }
}

void tailInsert(vector<int> &ans,ListNode* &head){
    int n = ans.size();
    ListNode* curr = head;
    for(auto i:ans){
        ListNode* node = new ListNode();
        node->val = i;
        node->next = NULL;
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
    tailInsert(ans,head);
    visit(head);
    return 0;
}
