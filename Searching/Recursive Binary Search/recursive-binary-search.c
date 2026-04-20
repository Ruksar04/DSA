/*
Time Complexity for binary search
Best Case: O(1) (middle element matches immediately)
Average Case: O(log n)
Worst Case: O(log n)

Space Complexity: O(log n)

As i am using insertion sort in this program then time complexity will be -
Total Time Complexity = Add both: O(n²)+O(log n)

Dominant term is: O(n²)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int binarysearchrec(int a[], int low, int high, int key){
    if(low > high) return -1;

    int mid = (low + high)/2;

    if(a[mid] == key){
        return mid;
    }
    else if(a[mid] < key){
        return binarysearchrec(a, mid+1, high, key);
    }
    else{
        return binarysearchrec(a, low, mid-1, key);
    }
}

void insertionsort(int a[], int n){
    int key, j;
    for(int i = 1; i <= n-1; i++){
        key = a[i];
        j = i - 1;
        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}

void genrandomnumbers(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = rand()%10000;
    }
}

int main(){
    int a[10000];
    clock_t start, end;
    double time_taken, theoretical_time;

    srand(time(NULL));

    FILE *fp = fopen("recursive-binary-search.txt", "w");

    for(int i = 100; i <= 10000; i+=400){
        genrandomnumbers(a, i);
        insertionsort(a, i);
        int key = a[i/2];

        start = clock();
        binarysearchrec(a, 0, i-1, key);
        end = clock();

        time_taken = (double) (end-start)/CLOCKS_PER_SEC;
        theoretical_time = log2(i)*1e-8;
        fprintf(fp, "%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);

    FILE *gp = popen("gnuplot -persistent", "w");

    fprintf(gp, "set title 'Recursive Binary Search Efficiency'\n");
    fprintf(gp, "set xlabel 'Input Size'\n");
    fprintf(gp, "set ylabel 'Time(seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set term png\n");
    fprintf(gp, "set output 'recursive_binarysearch_efficiency_c.png'\n");
    fprintf(gp, "plot 'recursive-binary-search.txt' using 1:2 with linespoints title 'Actual Time'," "'recursive-binary-search.txt' using 1:3 with lines lw 2 title 'Theoretical Time'\n");
}
