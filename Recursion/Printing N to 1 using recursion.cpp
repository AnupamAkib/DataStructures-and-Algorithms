#include<bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n==0) return;
    cout << n << " ";
    printNum(n-1);
}

int main(){
    //printing N to 1 using recursion
    printNum(10);
    return 0;
}
