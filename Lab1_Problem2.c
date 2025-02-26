//////////////////// Problem 2 ////////////////////////////
//reverse the list and return the reversed list 

//Singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

//function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next; // Store next node
        curr->next = prev; // Reverse the link
        prev = curr;       // Move prev forward
        curr = next;       // Move curr forward
    }
    
    return prev; // New head of reversed list
}

// Function to create a linked list from an array
struct ListNode* createLinkedList(int arr[], int size){
    if(size==0)
        return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;
        
    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

//function prints out linked list
void printList(struct ListNode* head){
    while(head){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

//function to free the linked list
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

//main function to test the reverseList function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createLinkedList(arr, 5);

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    freeList(head); //free allocated memory

    return 0;
}
