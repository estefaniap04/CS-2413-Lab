//Symmetric tree problem
#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//binary tree node
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//function to create new node
struct TreeNode* newNode(int val){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//frees tree memory
void freeTree(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

//checks if two tress are mirror images
bool Mirrors(struct TreeNode* t1, struct TreeNode* t2){
    if(t1 == NULL && t2 == NULL){ 
        return true;
    }
    if(t1 == NULL || t2 == NULL) {
        return false;
    }

    if(t1->val != t2->val){
        return false;
    }

    if(!Mirrors(t1->left, t2->right)){
        return false;
    }
    if(!Mirrors(t1->right, t2->left)){
        return false;
    }

    return true;

}

//main function to chekc if tree is symmetric
bool Symmetric(struct TreeNode* root){
    return Mirrors(root,root);
}

//main function
int main() {
    
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    printf("Input: root = [1,2,2,3,4,4,3]\n");
    printf("Output: %s\n", Symmetric(root) ? "true" : "false");

    freeTree(root);
    return 0;
}
