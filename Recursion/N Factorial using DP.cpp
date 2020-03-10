#include<bits/stdc++.h>
using namespace std;

long long dp[1000];
long long fact(int n){
    dp[0]=1;
    if(dp[n]==0){
        for(int i=1; i<=n; i++){
            dp[i]=i*fact(i-1);
        }
    }
    return dp[n];
}

int main(){
    cout << fact(10) << endl;
    return 0;
}


