/* Name         : Insertion Sort */
/* Best Case    : O(n) */
/* Worst Case   : O(n^2) */
/* Average Case : O(n^2) */
/* Author       : Mir Anupam Hossain Akib */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=9, j;
    int ar[n+1]={5, 7, 4, 3, 9, 2, 1, 0, 3};
    for(int i=0; i<n; i++){
        j = i;
        while(ar[j] < ar[j-1] && j>0){
           //Change ^ to '>' for Descending Order Sorting
            swap(ar[j], ar[j-1]);
            j--;
        }
    }
    cout << "Ascending Order Sorted Array: ";
    for(int i=0; i<n; i++){
        cout << ar[i] << " ";
    }
    return 0;
}
