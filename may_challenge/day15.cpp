#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* head = nullptr;
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* odd = odd_head;
        ListNode* even = even_head;
        while(even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            if(odd->next!=nullptr) {
                even->next = odd->next;
                even = even->next;
            }
        }
        odd->next = even_head;
        return odd_head;        
    }
};

void insertNode(ListNode* head  , int val) {
    ListNode* temp = head;
    ListNode nn(val);
    if(temp == nullptr) head = &nn;
    else {
        while(temp->next!=nullptr) {
            temp = temp->next;
        } 
        temp->next = &nn;
    }
}

int main() {
    insertNode(head, 1);
    insertNode(head, 2);    
    insertNode(head, 3);    
    insertNode(head, 4);    
    insertNode(head, 5);     
    ListNode* temp = head;
    while(temp!=nullptr) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Solution s;
    head = s.oddEvenList(head);
    while(temp!=nullptr) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}