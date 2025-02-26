//SINGLY-LINKED LIST
struct ListNode {
    int val; //Stores the value of the node.
    struct ListNode *next; //A pointer to the next node in the linked list.
};


//Removes all nodes with the given value from the linked list
struct ListNode* removeElements(struct ListNode* head, int val) {
    //dummy node created and allocated memory
    struct ListNode *dummy_n = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy_n -> next = head; //dummy_n points to head
    struct ListNode *curr = dummy_n;//curr set to dummy_n which will traverse the list

    //loops until last node reached
    while(curr->next != NULL){
        if(curr->next->val == val){
            struct ListNode *toDelete = curr->next;//stores reference to delete
            curr->next = curr->next->next; //removes node from list
            free(toDelete);
        }
        else{
            curr = curr->next; //moves next node
        }
    }

    struct ListNode *new_head = dummy_n -> next; //new head
    free(dummy_n);
    return new_head;
}

//creates a linked list from an array
struct ListNode* createLinkedList(int arr[], int size){
    if(size == 0)
        return NULL;
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
   head -> val = arr[0];
   head -> next = NULL;
   struct ListNode* curr = head;

   for(int i=1; i<size; i++){
    curr -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
    curr = curr -> next;
    curr -> val = arr[i];
    curr -> next = NULL;
   }
   return head;
}

//function prints out the linked list
void printList(struct ListNode *head){
    while(head){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

//function frees the linked list
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

//main function
int main() {
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;

    struct ListNode *head = createLinkedList(arr, 7);
    printf("Original list: ");
    printList(head);

    head = removeElements(head, val);
    printf("Modified list: ");
    printList(head);

    freeList(head); // Free allocated memory

    return 0;
}
