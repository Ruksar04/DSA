/*
Worst case: O(n^2)
Best case: O(n)
Average case: O(n^2)
  */
#include <stdio.h>
void insertionsort(int a[], int n){
    int key;
    for(int i = 1; i < n; i++){
        key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
    a[j+1] = key;
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
    printf("Array before sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    
    insertionsort(a,n);
    printf("\nArray after sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
}
