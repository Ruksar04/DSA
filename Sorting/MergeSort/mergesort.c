#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void merge_sort(int A[], int n){
    if(n<=1) return;
    int mid = n / 2;
    int B[mid];
    int C[n-mid];
    
    for(int i = 0; i < mid ; i++){
        B[i] = A[i];
    }
    
    for(int i = mid; i < n; i++){
        C[i-mid] = A[i];
    }
    
    merge_sort(B, mid);
    merge_sort(C, n-mid);
    merge(B, C, A, mid, n-mid);
}

void genrandomnumbers(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = rand()%10000;
    }
}

int main(){
    int a[10000];
    clock_t start , end;
    double time_taken, theoretical_time;
    
    srand(time(NULL));
    
    FILE *fp = fopen("mergesort.txt", "w");
    for(int i = 100; i <= 10000; i+=400){
        genrandomnumbers(a, i);
        start = clock();
        merge_sort(a, i);
        end = clock();
        
        time_taken = (double)(end-start)/CLOCKS_PER_SEC;
        theoretical_time = i*log2(i)*1e-8;
        fprintf(fp, "%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);
    
    
    FILE *gp = popen("gnuplot -persistent", "w");
    fprintf(gp,"set title 'Merge Sort Efficiency'\n");
    fprintf(gp, "set xlabel 'Input Size'\n");
    fprintf(gp, "set ylabel 'Time(seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set term png\n");
    fprintf(gp, "set output 'merge_sort_efficiency_c.png'\n");
    fprintf(gp, "plot 'mergesort.txt'using 1:2 with linespoints title 'Actual Time',""'mergesort.txt' using 1:3 with lines lw 2 title 'Theoretical Time'");
    fflush(gp);
    pclose(gp);
    return 0;
}
