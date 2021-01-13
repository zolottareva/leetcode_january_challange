//
//  main.cpp
//  leetcode_january12
//
//  Created by Золотарева Марина Олеговна on 12.01.2021.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode* head){
    while(head -> next!= nullptr){
        std::cout << head -> val << " ";
        head = head -> next;
    }
    std::cout << head -> val << " ";
    std:: cout << std::endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int extra = 0;
    ListNode* res = new ListNode();
    res -> val = (l1 -> val + l2 -> val) % 10;
    extra = (l1 -> val + l2 -> val) / 10;
    l1 = l1 -> next;
    l2 = l2 -> next;
    
    ListNode* current = res;
    if(!l1 && !l2){
        if(extra != 0){
            res -> next = new ListNode(extra);
        }
        return res;
    }
    if(l1 && !l2){
        while (l1){
            current -> next = new ListNode((l1 -> val + extra) % 10);
            extra = (l1 -> val + extra) / 10;
            current = current -> next;
            l1 = l1 -> next;
        }
        if(extra != 0){
            current -> next = new ListNode(extra);
        }
        return res;
    }
    if(l2 && !l1){
        while (l2){
            current -> next = new ListNode((l2 -> val + extra) % 10);
            extra = (l2 -> val + extra) / 10;
            current = current -> next;
            l2 = l2 -> next;
        }
        if(extra != 0){
            current -> next = new ListNode(extra);
        }
        return res;
    }
    while(l1 != nullptr && l2 != nullptr){
        current -> next = new ListNode((l1 -> val + l2 -> val + extra) % 10);
        extra = (l1 -> val + l2 -> val + extra) / 10;
        current = current -> next;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    while (l1 != nullptr){
        current -> next = new ListNode((l1 -> val + extra) % 10);
        extra = (l1 -> val + extra) / 10;
        current = current -> next;
        l1 = l1 -> next;
    }
    while (l2 != nullptr){
        current -> next = new ListNode((l2 -> val + extra) % 10);
        extra = (l2 -> val + extra) / 10;
        current = current -> next;
        l2 = l2 -> next;
    }
    if(extra != 0){
        current -> next = new ListNode(extra);
    }
    return res;
}
int main() {
    ListNode* headFirst = new ListNode(1);
    

    ListNode* second9 = new ListNode(9);
    ListNode* headSecond = new ListNode(9, second9);

    printList(addTwoNumbers(headFirst, headSecond));
    return 0;
}
