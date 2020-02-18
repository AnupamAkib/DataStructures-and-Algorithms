#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0) return 1; //n==1 also works
    //cout << n << " ";
    return n*factorial(n-1);
}

int main(){
    //Printing N! (factorial of N) using recursion
    cout << endl << factorial(5) << endl;
    return 0;
}
