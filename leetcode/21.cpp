// Recursive

// Runtime 3 ms Beats 96.91%
// Memory 14.7 MB Beats 86.4%

// O(min(list1, list2)), space O(min(list1, list2))
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        return list1;
    }
};


// Runtime 10 ms Beats 43.45%
// Memory 14.6 MB Beats 99%
// O(min(list1, list2)), space O(min(list1, list2))

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* ans = new ListNode(), *curr;
        curr = ans;
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2=list2->next;
            }
            curr = curr->next;
        }
        if(list1) curr->next = list1;
        if(list2) curr->next = list2;
        return ans->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Runtime: 20 ms, faster than 20.10% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 14.8 MB, less than 81.61% of C++ online submissions for Merge Two Sorted Lists.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *answer, *temp; 
        answer = new ListNode(); // new empty node
        temp = answer; // temp pointer to first node
        while(list1 && list2){ // while lists not empty
            if(list1->val < list2->val){ // if list1 value smaller than list 2 we increment list1 index by 1 and vice versa
                temp->next = list1; // next node equal list1 value
                list1 = list1->next; // traverse to next node
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; // value added to first node of temp, go to next node
        }
        if(list1){
            temp->next = list1; // put rest of list to temp list 
        }
        if(list2){
            temp->next = list2;
        }
        return answer->next;
    }
};
