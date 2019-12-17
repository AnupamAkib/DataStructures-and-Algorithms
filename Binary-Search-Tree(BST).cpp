#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* Insert(Node *nd, int data){
    if(nd == NULL){
        Node *tmp = (Node*) malloc(sizeof(Node));
        tmp -> data = data;
        tmp -> right = tmp -> left = NULL;
        nd = tmp;
        cout << data << " is inserted\n";
        return nd;
    }
    else if(data <= nd -> data ){
        nd -> left = Insert(nd -> left, data);
    }
    else{
        nd -> right = Insert(nd -> right, data);
    }
}

void preorder(Node *nd){
    if(nd == NULL) return;
    printf("%d ", nd -> data);
    preorder(nd -> left);
    preorder(nd -> right);
}

void inorder(Node *nd){
    if(nd == NULL) return;
    inorder(nd -> left);
    printf("%d ", nd -> data);
    inorder(nd -> right);
}

void postorder(Node *nd){
    if(nd == NULL) return;
    postorder(nd -> left);
    postorder(nd -> right);
    printf("%d ", nd -> data);
}

int main(){
    Node *root;
    root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 9);
    root = Insert(root, 19);
    root = Insert(root, 5);
    root = Insert(root, 12);
    root = Insert(root, 19);
    root = Insert(root, 23);

    inorder(root);

    return 0;
}




