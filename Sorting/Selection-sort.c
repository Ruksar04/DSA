//Selection sort always takes O(n²) time because it scans the remaining array to find minimum in every iteration, and uses constant space O(1) since it is in-place.

#include <stdio.h>

void selectionsort(int a[], int n){
    int min ;
    for(int i = 0; i <= n-2; i++){
        min = i;
        for(int j = i+1; j <= n-1; j++){
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
    int a[10];
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("enter element: \n");
        scanf("%d\n", &a[i]);
    }
    printf("Before Sorting: \n");
    
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    
    
    selectionsort(a, n);
        printf("After Sorting: \n");

    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
}
