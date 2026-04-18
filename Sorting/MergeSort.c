/*
Time Complexity:
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)*/

//Space Complexity: O(n) Because extra arrays are used

#include <stdio.h>

void merge(int B[], int C[], int A[], int p, int q){
    int i = 0;
    int j = 0; 
    int k = 0;
    
    while(i < p && j < q){
        if(B[i] <= C[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = C[j];
            j++;
        }
        k++;
    }
    
    while(i < p){
        A[k] = B[i];
        i++;
        k++;
    }
    
    while(j < q){
        A[k] = C[j];
        j++;
        k++;
    }
    
}

void mergesort(int A[], int n){
    if(n<=1) return;
    
    int mid = n/2;
    int B[mid];
    int C[n-mid];
    
    for(int i = 0; i < mid; i++){
        B[i] = A[i];
    }
    
    for(int i = mid; i < n; i++){
        C[i-mid] = A[i];
    }
    
    mergesort(B, mid);
    mergesort(C, n-mid);
    merge(B, C, A, mid, n-mid);
}


int main(){
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter array elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    printf("Array before sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    
    mergesort(a, n);
    
    printf("\nArray after sorting: \n");
    for(int i = 0 ; i < n; i++){
        printf("%d\t", a[i]);
    }
    return 0;
}
