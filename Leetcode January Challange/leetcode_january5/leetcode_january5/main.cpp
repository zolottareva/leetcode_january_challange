//
//  main.cpp
//  leetcode_january5
//
//  Created by Золотарева Марина Олеговна on 05.01.2021.
//

#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode* list){
    ListNode* current = list;
    while (current) {
        std::cout << current -> val << std::endl;
        current = current -> next;
    }
}
void addElement(ListNode* list, ListNode* element)
{
    ListNode* newNode = new ListNode(element -> val);
    if(list -> val == -101) {
        list -> val = element -> val;
        return;
    }
    while(list -> next){
         list = list -> next;
    }
    list -> next = newNode;
}
ListNode* deleteDuplicates(ListNode* head) {
    if(!head){
        return head;
    }
    ListNode* newHead = new ListNode(-101);
    int dontAdd = -101;
    while(head->next){
        if(head -> next -> val != head -> val && head -> val != dontAdd) {
            addElement(newHead, head);
            head = head->next;
        }
        else{
            dontAdd = head->val;
            head = head -> next;
        }
    }
    if(head -> val != dontAdd) addElement(newHead, head);
    if(newHead -> val == -101) return nullptr;
    return newHead;
}
int main() {
    ListNode node5 = ListNode(5);
    ListNode node5_duplicate = ListNode(5, &node5);
    ListNode node4 = ListNode(4, &node5_duplicate);
    ListNode node4_duplicate = ListNode(4, &node4);
    ListNode node4_duplicate1 = ListNode(4, &node4_duplicate);
    ListNode node4_duplicate2 = ListNode(4, &node4_duplicate1);
    ListNode node3 = ListNode(3, &node4_duplicate2);
    ListNode node2 = ListNode(2, &node3);
    ListNode node2_duplicate = ListNode(2, &node2);
    
    printList(deleteDuplicates(&node2_duplicate));
    
    return 0;
}
