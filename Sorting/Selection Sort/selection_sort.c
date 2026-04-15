#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int a[], int n){
    int temp, min;
    for(int i = 0; i<=n-2; i++){
        min = i;
        for(int j = i+1; j <= n-1; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
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
    double time_taken;
    double theoretical_time;
    
    srand(time(NULL));
    
    FILE *fp = fopen("selectionsort.txt", "w");
    
    for(int i = 100; i <= 10000; i+=400){
        genrandomnumbers(a, i);
        start = clock();
        selection_sort(a, i);
        end = clock();
        time_taken = (double) (end-start)/CLOCKS_PER_SEC;
        theoretical_time = (double) (i*i)*1e-8;
        fprintf(fp,"%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);
    
    FILE *gp = popen("gnuplot -persistent", "w");
    fprintf(gp,"set title 'Selection Sort Efficiency'\n");
    fprintf(gp,"set xlabel 'Input Size' \n");
    fprintf(gp, "set ylabel 'Time(seconds)'\n");
    fprintf(gp,"set grid\n");
    fprintf(gp, "set term png\n");
    fprintf(gp, "set output 'selection-sort-efficiency-c.png'\n");
    fprintf(gp, "plot 'selectionsort.txt' using 1:2 with linespoints title 'Actual Time'," "'selectionsort.txt' using 1:3 with lines lw 2 title 'Theoretical Time'\n");
    fflush(gp);
    pclose(gp);
    return 0;
}
