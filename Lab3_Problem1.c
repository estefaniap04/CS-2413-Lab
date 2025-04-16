//Binary Tree Preorder Traversal
#include <stdio.h>
#include <stdlib.h>

//binary tree node structure
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//preorder traversal
void preOrder(struct TreeNode* root, int* result, int* returnSize){
    if(root == NULL)
    {
        return;
    }

    //visits root
    result[(*returnSize)] = root->val;
    *returnSize = *returnSize + 1;

    //traverses left & right
    preOrder(root->left, result, returnSize);
    preOrder(root->right, result, returnSize);
}

int* preOrderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    //allocates memory that can hold up to 100 integers
    int* result = (int*)malloc(100 * sizeof(int));
    //fills array with node values then returns the filled array
    preOrder(root, result, returnSize);
    return result;
}

int main(){
    //tree [1,null,2,3]
    struct TreeNode n3 = {3,NULL,NULL};
    struct TreeNode n2 = {2, &n3, NULL};
    struct TreeNode n1 = {1, NULL, &n2};

    int returnSize;
    int* result = preOrderTraversal(&n1, &returnSize);

    printf("Preorder Traversal: \n");
    for(int i=0; i<returnSize; i++){
        printf("%d ",result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
