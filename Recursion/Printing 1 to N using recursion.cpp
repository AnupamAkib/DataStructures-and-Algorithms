#include<bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n==0) return;
    printNum(n-1);
    cout << n << " ";
}

int main(){
    //printing 1 to N using recursion
    printNum(10);
    return 0;
}
