#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int a[], int n){
    int key;
    for(int i = 1; i <= n; i++){
        key = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>key){
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
    clock_t start;
    clock_t end;
    double time_taken;
    double theoretical_time;
    
    srand(time(NULL));
    
    FILE *fp = fopen("insertionsort.txt", "w");
    
    for(int i = 100; i <= 10000; i+=400){
        genrandomnumbers(a, i);
        start = clock();
        insertionsort(a,i);
        end = clock();
        
        time_taken = (double)(end-start)/CLOCKS_PER_SEC;
        theoretical_time = (double)(i*i)*1e-8;
        fprintf(fp,"%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);
    
    FILE *gp = popen("gnuplot -persistent", "w");
    fprintf(gp, "set title 'Insertion Sort Efficiency'\n");
    fprintf(gp, "set xlabel 'Input Size'\n");
    fprintf(gp, "set ylabel 'Time (seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set term png\n");
    fprintf(gp, "set output 'insertion_sort_efficiency_c.png'\n");
    fprintf(gp, "plot 'insertionsort.txt' using 1:2 with linespoints title 'Actual Time',""'insertionsort.txt' using 1:3 with lines lw 2 title 'Theoretical Time'\n");
    fflush(gp);
    pclose(gp);
}
