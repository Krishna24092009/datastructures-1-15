#include <stdio.h>
#include <stdlib.h>
// Node structure definition
struct node {
int data;
struct node *left_child;
struct node *right_child;
};
// Function to create a new node
struct node* new_node(int x) {
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->data = x;
temp->left_child = NULL;
temp->right_child = NULL;
return temp;
}
// Function to search for a node with value x
struct node* search(struct node *root, int x) {
if (root == NULL || root->data == x) return root;
if (x > root->data) return search(root->right_child, x);
return search(root->left_child, x);
}
// Function to insert a new node with value x
struct node* insert(struct node *root, int x) {
if (root == NULL) return new_node(x);
if (x > root->data) root->right_child = insert(root->right_child, x);
else root->left_child = insert(root->left_child, x);
return root;
}
// Function to find the minimum value node in a subtree
struct node* find_minimum(struct node *root) {
if (root == NULL) return NULL;
if (root->left_child != NULL) return find_minimum(root->left_child);
return root;
}
// Function to delete a node with value x
struct node* delete(struct node *root, int x) {
if (root == NULL) return NULL;
if (x > root->data) root->right_child = delete(root->right_child, x);
else if (x < root->data) root->left_child = delete(root->left_child, x);
else {
if (root->left_child == NULL && root->right_child == NULL) {
free(root);
return NULL;
} else if (root->left_child == NULL || root->right_child == NULL) {
struct node *temp = root->left_child ? root->left_child : root->right_child;
free(root);
return temp;
} else {
struct node *temp = find_minimum(root->right_child);
root->data = temp->data;
root->right_child = delete(root->right_child, temp->data);
}
}
return root;
}
// Function to perform an inorder traversal of the BST
void inorder(struct node *root) {
if (root != NULL) {
inorder(root->left_child);
printf(" %d ", root->data);
inorder(root->right_child);
}
}
// Main function to test the BST operations
int main() {
struct node *root = NULL;
// Insertion of nodes
root = insert(root, 20);
insert(root, 5);
insert(root, 1);
insert(root, 15);
insert(root, 9);
insert(root, 7);
insert(root, 12);
insert(root, 30);
insert(root, 25);
insert(root, 40);
insert(root, 45);
insert(root, 42);
// Inorder traversal before deletion
printf("Inorder traversal before deletion:");
inorder(root);
printf("\n");
// Deletion of nodes
root = delete(root, 1);
root = delete(root, 40);
root = delete(root, 45);
root = delete(root, 9);
// Inorder traversal after deletion
printf("Inorder traversal after deletion:");
inorder(root);
printf("\n");
getchar();
return 0;
}
