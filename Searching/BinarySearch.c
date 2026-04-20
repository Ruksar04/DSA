/*
Selection Sort = O(n²)

Binary Search = O(logn)

Total Time Complexity = O(n²+logn) = O(n²)

Space Complexity = O(1) Both are in-place iterative algorithms
*/
#include <stdio.h>

int binarysearch(int a[], int n, int key){
    int l = 0;
    int r = n-1;
    int m;

    while(l<=r){
        m = (l+r)/2;

        if(a[m] == key){
            return m;
        }
        else if(a[m] < key){
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return -1;
}

void selectionsort(int a[], int n){
    int min, j;

    for(int i = 0; i <= n-2; i++){
        min = i;
        for(int j = i+1; j<=n-1; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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

    selectionsort(a, n);

    int key;
    printf("Enter an element to search: \n");
    scanf("%d", &key);

    int pos = binarysearch(a, n, key);

    if(pos == -1){
        printf("Element not found!");
    }
    else{
        printf("Element found at index %d", pos);
    }
    return 0;
}
