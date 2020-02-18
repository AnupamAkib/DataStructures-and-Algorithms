//http://zobayer.blogspot.com/2009/12/cse-102-practice-recursions.html?m=1
/*
Input:
5
69 87 45 21 47
Output:
47 21 45 87 69
*/

#include<bits/stdc++.h>
using namespace std;

void rev(int a[], int first, int last){
    if(first==last) return;
    rev(a, first+1, last);
    cout << a[first] << " ";
}

int main(){
    int n;
    cin >> n;
    int a[n+2];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    rev(a, 0, n);

    return 0;
}

