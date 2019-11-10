#include<stdio.h>
#include<stdlib.h>
#define MAX 300

int head=0, tail=MAX, ar[MAX+5];
struct stack{
    void push(int n){
        if(head>=tail){
            printf("Stack Overflow. %d is not pushed!\n", n);
            exit(1);
        }
        ar[head]=n;
        head++;
    }
    void pop(){
        head--;
        if(head<0){
            printf("Stack Underflow!\n");
            exit(1);
        }
    }
    int top(){
        if(head==0){
            printf("Stack is Empty!\n");
            exit(1);
        }
        return ar[head-1];
    }
};

int main(){
    stack anupam;

    anupam.push(2);
    anupam.push(3);
    anupam.push(4);
    anupam.push(5);
    anupam.pop();
    anupam.pop();
    anupam.push(10);
    anupam.pop();

    printf("top is %d\n\n", anupam.top());
    return 0;
}
