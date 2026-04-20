/*
BINARY SEARCH
Time Complexity: O(log n)
Space Complexity: O(1)

BINARY SEARCH + SELECTION SORT
Total Time Complexity: O(n²)
Total Space Complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}

void selectionsort(int a[], int n){
    int min, j;
    for(int i = 0; i <= n-2; i++){
        min = i;
        for(int j = i+1; j<= n-1; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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

    FILE *fp = fopen("binary-search.txt", "w");

    for(int i = 100; i <= 10000; i+=400){
        genrandomnumbers(a, i);
        selectionsort(a, i);
        int key = a[i/2];

        start = clock();
        binarysearch(a, i, key);
        end = clock();

        time_taken = (double) (end-start)/CLOCKS_PER_SEC;
        theoretical_time = log2(i)*1e-8;

        fprintf(fp, "%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);

    FILE *gp = popen("gnuplot -persistent", "w");

    fprintf(gp, "set title 'Binary Search Efficiency'\n");
    fprintf(gp, "set xlabel 'Input Size'\n");
    fprintf(gp, "set ylabel 'Time(seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set term png\n");
    fprintf(gp, "set output 'binary-search-efficiency-c.png'\n");
    fprintf(gp, "plot 'binary-search.txt' using 1:2 with linespoints title 'Actual Time',""'binary-search.txt' using 1:3 with lines lw 2 title 'Theoretical Time'");
    return 0;
}
