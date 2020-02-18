#include<bits/stdc++.h>
using namespace std;

int dp[100];
int fibonacci(int n){ //We use DP to reduce time complexity. DP is a way of optimizing recursive solutions
    if(n==0 || n==1) return 1;
    if(dp[n]==0){
        dp[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return dp[n];
}

int main(){
    //Printing Nth fibonacci number using DP
    cout << fibonacci(40) << endl; //it takes 2.5s without DP. It just takes only 0.04s to execute with DP
    return 0;
}
