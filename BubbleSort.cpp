/* Name         : Bubble Sort */
/* Complexity   : O(n^2) */
/* Author       : Mir Anupam Hossain Akib */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=9, j, tmp;
    int ar[n+1]={5, 7, 4, 3, 9, 2, 1, 0, 3};
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j], ar[j+1]);
            }
        }
    }

    cout << "Ascending Order Sorted Array: ";
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    return 0;
}




