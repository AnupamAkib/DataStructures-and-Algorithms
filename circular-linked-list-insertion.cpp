#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
} Node;

int n, item;
Node *root = new Node(), *tmp;

void Insert(Node *nd, int element){
    if(nd -> next == NULL){
        nd -> next = (Node*) malloc(sizeof(Node));
        nd -> next -> data = element;
        nd -> next -> next = NULL;
        printf("%d is inserted\n", element);
        return;
    }
    Insert(nd -> next, element);
}

int cnt=0;
void Display(Node *nd){
    if(cnt==n){cnt=1; return;}
    printf("%d ", nd -> next -> data);
    cnt++;
    Display(nd -> next);
}

int main(){
    root -> next = NULL;

    printf("How many element you want to insert: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter element for iterator %d: ", i);
        scanf("%d", &item);
        Insert(root, item);
    }
    tmp = root;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = root -> next;

    printf("ALL DATA: ");
    Display(root);
    printf("\n");

    return 0;
}

