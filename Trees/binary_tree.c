//Implementation of binary tree with memory deallocation
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(){
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left=create();
    printf("Enter right child of %d\n",x);
    newnode->right=create();
    return newnode;
}
void freetree(struct node *root){
    if(root==NULL){
        return;
    }
    freetree(root->left);
    freetree(root->right);
    free(root);
}
int main(){
    struct node *root=NULL;
    root=create();
    freetree(root);
    return 0;
}