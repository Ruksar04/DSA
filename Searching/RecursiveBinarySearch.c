/*
Time Complexity = O(n²) 
Because Bubble Sort is used before Binary Search, and Bubble Sort dominates.

Bubble Sort = O(n²)
Binary Search = O(log n)

Total: O(n²+logn) = O(n²)

Space Complexity: O(log n)
*/
#include <stdio.h>

int binarysearchrec(int a[], int low, int high, int key){
    if(low > high) return -1;
    
    int mid = (low+high)/2;
    
    if(a[mid] == key){
        return mid;
    }
    
    else if(a[mid] < key){
        return binarysearchrec(a, mid+1 , high, key);
    }
    
    else{
        return binarysearchrec(a, low, mid-1, key);
    }
}

void bubblesort(int a[], int n){
    for(int i = 0; i <= n-2; i++){
        for(int j = 0; j <= n-2; j++){
            if(a[j+1] < a[j]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter array elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    bubblesort(a, n);
    
    int key;
    printf("Enter element to search: \n");
    scanf("%d", &key);
    
    int pos = binarysearchrec(a, 0, n-1, key);
    
    if(pos == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index: %d", pos);
    }
}
