//Added inorder traversal
//Added postorder traversal
//Added preorder traversal
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
void preorderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
void postorderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
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
    int choice;
    do{
        printf("\n====== MENU ======\n");
        printf("0. Exit\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                freetree(root);
                root=NULL;
                printf("Program exited successfully\n");
                break;
            case 1:
                freetree(root);
                root=NULL;
                printf("\nCreate Binary Tree\n");
                root=create();
                break;
            case 2:
                if(root==NULL){
                    printf("Tree is empty\n");
                }
                else{
                    printf("Preorder Traversal: ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root==NULL){
                    printf("Tree is empty\n");
                }
                else{
                    printf("Inorder Traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root==NULL){
                    printf("Tree is empty\n");
                }
                else{
                    printf("Postorder Traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=0);
    return 0;
}