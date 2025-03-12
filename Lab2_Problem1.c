//FIFO Queue
#include <stdio.h>
#include <stdlib.h>

//stack node structure
typedef struct Node{
    int data;
    struct Node* next;
} Node;

//stack structure
typedef struct Stack{
    Node* top;
} Stack;

//Implement Queue using Stacks
typedef struct Queue{
    Stack stack1;
    Stack stack2;
} Queue;

//new queue function
Queue* myQueueCreate() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1.top = NULL;   //empty stack1
    queue->stack2.top = NULL;   //empty stack2
    return queue;
}

void QueuePush(Queue* queue, int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = queue->stack1.top;
    queue->stack1.top = newNode;        //pushes new node into stack1
}

int QueuePop(Queue* queue){
    if(queue->stack2.top==NULL){
        while(queue->stack1.top != NULL){
            Node* currentNode = queue->stack1.top;
            queue->stack1.top = queue->stack1.top->next;
            currentNode->next = queue->stack2.top;
            queue->stack2.top = currentNode;
        }
    }
    //if queue is empty returns "Queue is empty."
    if(queue->stack2.top == NULL){
        printf("Queue is empty.\n");
        return -1;
    }
    Node* currentNode = queue->stack2.top;
    queue->stack2.top = queue->stack2.top->next;
    int pop_Val = currentNode->data;
    free(currentNode);
    return pop_Val;
}

//PEEK function, to peek at the front element of the queue.
int QueuePeek(Queue* queue){
    if(queue->stack2.top==NULL){
        while(queue->stack1.top != NULL){
            Node* currentNode = queue->stack1.top;
            queue->stack1.top = queue->stack1.top->next;
            currentNode->next = queue->stack2.top;
            queue->stack2.top = currentNode;
        }
    }
    //if queue is empty returns "Queue is empty."
    if(queue->stack2.top == NULL){
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->stack2.top->data;
}

int QueueEmpty(Queue* queue){
    if(queue->stack1.top == NULL && queue->stack2.top == NULL){
        return 1; //Queue is empty
    }   
    else{
        return 0; //Queue is not empty
    }
}

void QueueFree(Queue* queue){
    //Free nodes in stack1 
    Node* currentNode;
    while(queue->stack1.top != NULL){
        currentNode = queue->stack1.top;
        queue->stack1.top = queue->stack1.top->next;
        free(currentNode);
    }

    //free nodes in stack2
    while(queue->stack2.top != NULL){
        currentNode = queue->stack2.top;
        queue->stack2.top = queue->stack2.top->next;
        free(currentNode);
    }

    //frees the queue structure
    free(queue);
}

int main() {
    Queue* queue = myQueueCreate();

    //push elements into queue
    QueuePush(queue, 10);
    QueuePush(queue, 420);
    QueuePush(queue, 30);
    QueuePush(queue, 120);

    //transfer elements from stack1 to stack2 if stack2 is empty 
    if (queue->stack2.top == NULL) {
        while (queue->stack1.top != NULL) {
            Node* currentNode = queue->stack1.top;
            queue->stack1.top = queue->stack1.top->next;
            currentNode->next = queue->stack2.top;
            queue->stack2.top = currentNode;
        }
    }

    //print the queue contents (FIFO)
    Node* currentNode = queue->stack2.top;
    printf("Queue contents: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");

    //pop an element and print it again
    printf("Popped: %d\n", QueuePop(queue));

    //transfer elements from stack1 to stack2 if stack2 is empty
    if (queue->stack2.top == NULL) {
        while (queue->stack1.top != NULL) {
            Node* currentNode = queue->stack1.top;
            queue->stack1.top = queue->stack1.top->next;
            currentNode->next = queue->stack2.top;
            queue->stack2.top = currentNode;
        }
    }

    //print the queue contents after pop
    currentNode = queue->stack2.top;
    printf("Queue contents after pop: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");

    if (QueueEmpty(queue)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // Free the queue
    QueueFree(queue);

    return 0;
}
