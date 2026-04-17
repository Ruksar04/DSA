/*
TIME COMPLEXITY:
Best case: O(n log n)
Average case: O(n log n)
Worst case: O(n^2)

SPACE COMPLEXITY:
Auxiliary space: O(log n) on average because of recursion stack
Worst case space: O(n)
*/
#include <stdio.h>

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while(1){
        do{
            i = i + 1;
            
        }while(a[i] < pivot);
        
        do{
            j = j - 1;
            
        }while(a[j] > pivot);
        
        if(i>=j){
            return j;
        }
        
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void quicksort(int a[], int low, int high){
    if(low < high){
        int s = partition(a, low, high);
        quicksort(a, low, s);
        quicksort(a, s+1, high);
    }
}

int main(){
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Array before sorting: \n");
    for(int i = 0 ; i < n; i++){
        printf("%d\t", a[i]);
    }
    quicksort(a, 0, n-1);

    printf("\n Array after sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    return 0;
}
