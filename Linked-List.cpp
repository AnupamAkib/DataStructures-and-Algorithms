#include <stdio.h>
#include <malloc.h>

typedef struct node Node; //Lets call 'struct node' as simply 'Node' :)
struct node{
    int data; //it will hold data that we will insert.
    Node *next; //it will point the address of next node
};

int main(){
    int choice=1;
    Node *root=NULL, *temp; //we use temp pointer because we don't want to lose the root. temp will traverse the whole linked list from the root.

    while(choice){
        Node *newNode = (Node*) malloc(sizeof(Node)); //dynamic memory allocation for newNode
        printf("Enter data: ");
        scanf("%d", &newNode -> data); //input data into the data part of newNode
        newNode -> next = NULL; //always set next of newNode NULL. Otherwise, we can't get where the linked list is finished.
        if(root==NULL){
            root = temp = newNode; //if root is null then assign newNode in it and also keep it in a struct to pointer named 'temp'
        }
        else{
            temp -> next = newNode; //if root is not null then keep data of newNode in the next of temp. temp holds the current node.
            temp = newNode; //temp holds the current node. after doing previous operation, current node is newNode. So, assign it in temp.
        }
        printf("Do you want to add more data? (0/1):\n"); //check if user wants to add more data into the linked list.
        scanf("%d", &choice); //loop will break if choice==0
    }


    //now we will print all the elements of linked list that we've just created.
    temp = root; //temp will traverse linked list. So, it will start traversing from the root.
    printf("\nYour created linked list elements:\n");
    while(temp != NULL){ //do it while linked list is not finished. (finding NULL means linked list is finished.)
        printf("%d ", temp -> data); //print data that struct to pointer 'temp' holds now.
        temp = temp -> next; //temp will traverse the next node
    }

    return 0;
}





