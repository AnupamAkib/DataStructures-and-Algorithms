#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    //Printing Nth fibonacci number using recursion
    /*for(int i=0; i<10; i++){ //printing the series
        cout << fibonacci(i) << " ";
    }*/
    cout << fibonacci(7) << endl; //7th fibonacci number in the series
    return 0;
}
