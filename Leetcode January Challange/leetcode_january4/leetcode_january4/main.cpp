//
//  main.cpp
//  leetcode_january4
//
//  Created by Золотарева Марина Олеговна on 04.01.2021.
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
    if(list -> val == -1) {
        list -> val = element -> val;
        return;
    }
    while(list -> next){
         list = list -> next;
    }
    list -> next = newNode;
}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* currentL1 = l1;
        ListNode* currentL2 = l2;
        ListNode* result = new ListNode(-1);
        if(!currentL1 && !currentL2) { return nullptr; }
        
        while (currentL1 || currentL2) {
            if( currentL1 && currentL2 && currentL1 -> val < currentL2 -> val){
                std::cout << "both 1" << std::endl;
                addElement(result, currentL1);
                
                printList(result);
                
                currentL1 = currentL1 -> next;
            }
            else if( currentL1 && currentL2){
                std::cout << "both 2" << std::endl;
                addElement(result, currentL2);
                
                printList(result);
                
                currentL2 = currentL2 -> next;
            }
            else if( currentL2 ){
                std::cout << "only 2" << std::endl;
                addElement(result, currentL2);
                
                printList(result);
                
                currentL2 = currentL2 -> next;
            }
            else{
                std::cout << "only 1" << std::endl;
                addElement(result, currentL1);
                
                printList(result);
                
                currentL1 = currentL1 -> next;
            }
        }
        std:: cout << std:: endl;
        return result;
    }
int main() {
    ListNode last4 = ListNode(4);
    ListNode last3 = ListNode(3, &last4);
    ListNode last1 = ListNode(1, &last3);
    
    ListNode last5 = ListNode(5);
    ListNode last2 = ListNode(2, &last5);
    ListNode last0 = ListNode(0, &last2);
    
//    ListNode* test = nullptr;
//    ListNode* testNext = new ListNode(30);
//    addElement(test, testNext);
//    printList(test);
    
//    printList(&last1);
//    printList(&last0);
    printList(mergeTwoLists(nullptr, nullptr));
    return 0;
}
