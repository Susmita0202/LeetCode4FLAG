struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to act as a placeholder for the merged list
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* cur = &dummy;

    // Traverse both lists and merge them
    while (list1 != NULL && list2 != NULL) {
        if (list1->val > list2->val) {
            cur->next = list2;
            list2 = list2->next;
        } else {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }

    // If either list still has elements, append them
    cur->next = (list1 != NULL) ? list1 : list2;

    // Return the merged list starting from the first actual element
    return dummy.next;
}
