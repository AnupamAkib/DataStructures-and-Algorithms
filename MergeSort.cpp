#import<stdio.h>

/* Name: MergeSort Code with Algorithm in comment */
/* Complexity: O(nlog(n)) */
/* Author: Mir Anupam Hossain Akib */

void Merge(int arr[], int first, int mid, int last){ ///Function for merging elements in sub-array
    int temp[100]; //declare a temp array where we will store data temporarily for merging
    int left = first; //*left pointer always indicates the first element of the left part of sub-array
    int right = mid + 1; //*right pointer always indicates the position after mid value, because it is the first element of the right part of sub-array
    int i=0; //as we will keep data in temp array from zero index
    int k, x; //other variable

    while((left <= mid) && (right <= last)){ //**check if left pointer is in the left part & the right pointer is in the right part
        if(arr[left] <= arr[right]){ //**compare elements between left and right part of the sub-array
        ///just change ^ to >= if you want to sort in descending order
            temp[i] = arr[left]; //*if left part element is smaller or equal then push it in temp array
            left++; //increase left by one
        }
        else{
            temp[i] = arr[right]; //*if right part element is smaller then push it in temp array
            right++; //increase right by one
        }
        i++; //increase i to push element in temp array
    }

    /*one for loop will execute between this first two for loop below.
    Because, element will remain either in right side or in left side.*/
    for(k=right; k<=last; k++){ //**remaining elements of right part push in the temp array
        temp[i] = arr[k];
        i++;
    }

    for(k=left; k<=mid; k++){ //**remaining elements of left part push in the temp array
        temp[i] = arr[k];
        i++;
    }

    for(k=first, x=0; k<=last; k++, x++){ //return all elements in 'arr' from 'temp'.
        arr[k] = temp[x];
    }
}

void MergeSort(int arr[], int first, int last){ ///Function to sort data (MergeSort Algorithm)
    if(first == last) return; //**return when single data found
    int mid = first + (last - first) / 2; //Optimized trick of (first+last)/2 to prevent integer overflow for big data

    //now we gonna divide the whole array part by part. each sub-array will contain two parts.
    MergeSort(arr, first, mid); //*divide the array by left side
    MergeSort(arr, mid+1, last); //*divide the array by right side;
    Merge(arr, first, mid, last); //sort and merge the sub-array by calling it
}


int main(){
    int i;
    int arr[] = {6, 7, 2, 1, 5, 9, 3, 8, 0, 5, 4, 7, 3, 12, 10, 100, 11, 78}; //data to be sorted

    MergeSort(arr, 0, sizeof(arr)/4 - 1); //calling this function to sort arr

    for(i=0; i<sizeof(arr)/4; i++){ //printing the array after sorting
        printf("%d ", arr[i]);
    }

    printf("\n\n\n\n\n");
    return 0;
}






