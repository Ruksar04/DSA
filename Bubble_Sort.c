//Time Complexity - O(n²)
//Space Complexity - O(1) = constant because this is in-place bubble sort
#include <stdio.h>
int bubble_sort(int a[], int n){
    for(int i = 0; i <= n-2; i++){
        for(int j = 0; j <= n-2-i; j++){
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
    printf("Enter the elements to be inserted: \n");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter an element: \n");
        scanf("%d", &arr[i]);
    }
    
    printf("Array before sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    
    bubble_sort(arr, n);
    
    printf("\n Array After sorting: \t");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}
