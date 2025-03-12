#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int *arr;
    int front;
    int back;
    int size;
    int cap;
}Queue;

typedef struct{
    Queue* queue1;
    Queue* queue2;
} Stack;

//function to create queue of given capacity
Queue* createQueue(int cap){

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->cap = cap;
    queue->front = 0;
    queue->back = 0;
    queue->size = 0;
    queue->arr = (int*)malloc(queue->cap * sizeof(int));
    return queue;
}

//function checks if queue empty
bool queueEmpty(Queue* queue){
    return queue->size == 0;
}

//function adds item to queue
void enqueue(Queue* queue, int item){
    if(queue->size == queue->cap){
        printf("Queue is full.\n");
        return;
    }
    queue->arr[queue->back] = item;
    queue->back = (queue->back + 1) % queue->cap;
    queue->size++;
}

//function removes item from queue
int dequeue(Queue* queue){
    if(queueEmpty(queue)){
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size--;
    return item;
}

//function to get the front element of the queue
int peek(Queue* queue){
    if(queueEmpty(queue)){
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->arr[queue->front];
}

//Stack section//
Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->queue1 = createQueue(100);
    stack->queue2 = createQueue(100);
    return stack;
}

void stackPush(Stack* stack, int x) {
    // Enqueue the new element into queue1
    enqueue(stack->queue1, x);

    // Move all elements from queue1 to queue2
    while (!queueEmpty(stack->queue1)) {
        int frontElement = dequeue(stack->queue1);
        enqueue(stack->queue2, frontElement);
    }

    // Swap references of queue1 and queue2
    Queue* queueTemp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = queueTemp;
}


//function pops the top element of the stack
int stackPop(Stack* stack){
    if(queueEmpty(stack->queue1)){
        printf("Stack is empty.\n");
        return -1;
    }
    return dequeue(stack->queue1);
}

//fucntion that gets the top element of stack
int stackTop(Stack* stack){
    if(queueEmpty(stack->queue1)){
        printf("Stack is empty.\n");
        return -1;
    }
    return peek(stack->queue1);
}

//function checks if the stack is empty
bool stackEmpty(Stack* stack){
    return queueEmpty(stack->queue1);
}

//funtion free memory allocated for the stack
void freeStack(Stack* stack){
    free(stack->queue1->arr);
    free(stack->queue2->arr);
    free(stack->queue1);
    free(stack->queue2);
    free(stack);
}

// main functioN!
int main(){
    Stack* stack = createStack();
    
    stackPush(stack, 10);
    stackPush(stack, 20);
    stackPush(stack, 30);
    
    //top element
    printf("Top Element: %d\n", stackTop(stack));

    //popped element
    printf("Pop Element: %d\n", stackPop(stack));
    printf("Pop Element: %d\n", stackPop(stack));

    //prints out if stack is empty or not
    printf("Stack empty: %s\n", stackEmpty(stack) ? "Yes" : "No");

    printf("Pop element: %d\n", stackPop(stack));
    printf("Is stack empty? %s\n", stackEmpty(stack) ? "Yes" : "No");

    freeStack(stack);

    return 0;
}
