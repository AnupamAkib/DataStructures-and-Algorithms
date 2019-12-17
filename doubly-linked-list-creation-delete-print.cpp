#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} Node;

void InsertAtTail(Node *nd, int data){
    if(nd -> next == NULL){
        nd -> next = new Node();
        nd -> next -> data = data;
        nd -> next -> prev = nd;
        nd -> next -> next = NULL;
        cout << data << " is inserted at tail";
        return;
    }
    InsertAtTail(nd -> next, data);
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
            nd -> next -> prev = tmp;

            nd -> next = tmp;
            tmp -> prev = nd;

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
    if(nd -> next == NULL){
        cout << element << " not found in the list";
        return;
    }
    if(nd -> next -> data == element){
        Node *tmp = nd -> next;
        nd -> next = tmp -> next;
        if(tmp -> next != NULL){
            nd -> next -> prev = nd;
        }
        free(tmp);
        cout << element << " is deleted";
        return;
    }
    del_element(nd -> next, element);
}

void Display(Node *nd, string method){
    if(method=="forward"){
        if(nd -> next == NULL) return;
        printf("%d ", nd -> next -> data);
        Display(nd -> next, method);
    }
    else if(method=="reverse"){
        while(nd -> next != NULL){
            nd = nd -> next;
        }
        while(nd -> prev != NULL){
            printf("%d ", nd -> data);
            nd = nd -> prev;
        }
        /*
        if(nd -> next == NULL) return; //for printing recursively
        Display(nd -> next, method);
        printf("%d ", nd -> next -> data);
        */
    }
}

int main(){
    Node *root = new Node();
    root -> next = root -> prev = NULL;
    int choice, n, it;

    while(1){
        cout << "\n\nForward print: ";
        Display(root, "forward");
        cout << endl << "Reverse print: ";
        Display(root, "reverse");
        printf("\n\n\t1. Insert at tail\n\t2. Insert by Iterator\n\t3. Delete element\n");
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==1){
            cout << "Enter insert element: ";
            cin >> n;
            system("cls");
            InsertAtTail(root, n);
        }
        else if(choice==2){
            cout << "Enter iterator to insert: ";
            cin >> it;
            cout << "Enter insert element: ";
            cin >> n;
            system("cls");
            InsertAtMiddle(root, it, n);
        }
        else{
            cout << "Enter an element to delete: ";
            cin >> n;
            system("cls");
            del_element(root, n);
        }
    }
    return 0;
}












