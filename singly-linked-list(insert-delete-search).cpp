#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
} Node;

void InsertAtTail(Node *nd, int element){
    if(nd -> next == NULL){
        nd -> next = (Node*) malloc(sizeof(Node));
        nd -> next -> data = element;
        nd -> next -> next = NULL;
        printf("%d is inserted at tail", element);
        return;
    }
    InsertAtTail(nd -> next, element);
}

void InsertAtMiddle(Node *nd, int it, int data){
    int cnt=1;
    bool flag=false;
    if(nd -> next == NULL){
        printf("List is empty");
        return;
    }
    while(nd -> next != NULL){
        if(cnt == it){
            Node *tmp = new Node();
            tmp -> data = data;
            tmp -> next = nd -> next;
            nd -> next = tmp;
            printf("%d is inserted at iterator %d", data, it);
            flag=true;
            return;
        }
        cnt++;
        nd = nd -> next;
    }
    if(flag==false){
        printf("Invalid Iterator!");
        return;
    }
}

void del_element(Node *nd, int element){
    Node *tmp;
    if(nd -> next == NULL) return;
    if(nd -> next -> data == element){
        tmp = nd -> next;
        nd -> next = nd -> next -> next;
        free(tmp); //free the disconnected memory
        return;
    }
    del_element(nd -> next, element);
}

int search_element(Node *nd, int key){
    int cnt=0;
    while(nd -> next !=NULL){
        if(nd -> next -> data == key){
            cnt++;
        }
        nd = nd -> next;
    }
    return cnt;
}

void Display(Node *nd){
    if(nd -> next == NULL) return;
    printf("%d ", nd -> next -> data);
    Display(nd -> next);
}


int main(){
    int n, choice, it;
    Node *root = (Node*) malloc(sizeof(Node));
    root -> next = NULL;

    while(1){
        printf("\nALL DATA: "); Display(root);
        printf("\n\n\t1. insert data at tail\n\t2. insert by iterator\n\t3. delete element\n\t4. search element\nEnter choice: ");
        scanf("%d", &choice);
        if(choice==1){
            printf("Enter element that u want to insert: ");
            scanf("%d", &n);
            InsertAtTail(root, n);
            system("cls");
        }
        else if(choice==2){
            printf("Enter iterator: ");
            scanf("%d", &it);
            printf("Enter data: ");
            scanf("%d", &n);
            system("cls");
            InsertAtMiddle(root, it, n);
        }
        else if(choice==3){
            printf("enter delete element: ");
            scanf("%d", &n);
            del_element(root, n);
            system("cls");
        }
        else{
            int search_key;
            printf("Enter Search Key: ");
            scanf("%d", &search_key);
            system("cls");
            printf("element %d found %d times", search_key, search_element(root, search_key));

        }
    }
}















