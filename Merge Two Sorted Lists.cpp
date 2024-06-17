class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the head of the merged list
        ListNode* dummy = new ListNode(-1);
        // Pointer to the current node in the merged list
        ListNode* current = dummy;
        
        // Traverse both lists until one of them becomes empty
        while (list1 && list2) {
            // Compare the values of the current nodes of both lists
            // Choose the smaller value and add it to the merged list
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Append the remaining nodes of the non-empty list to the merged list
        if (list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        // Return the head of the merged list (skip the dummy node)
        return dummy->next;
    }
};

