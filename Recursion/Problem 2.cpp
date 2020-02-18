//http://zobayer.blogspot.com/2009/12/cse-102-practice-recursions.html?m=1
/*
Input:
5
1 5 7 8 9
Output:
1 9
5 8
7 7
*/

#include<bits/stdc++.h>
using namespace std;

void pairPrint(int a[], int first, int last){
    if(first>last) return;
    cout << a[first] << " " << a[last] << endl;
    pairPrint(a, first+1, last-1);
}

int main(){
    int n;
    cin >> n;
    int a[n+2];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    pairPrint(a, 0, n-1);

    return 0;
}


