#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[high]; 
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return (i + 1);
}

void quick_sort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

void getRandomNumbers(int a[], int n){
    for (int i = 0; i < n; i++){
        a[i] = rand() % 10000;
    }
}

int main(){
    int a[10000];
    clock_t start, end;
    double time_taken;
    double theoretical_time;
    FILE *fp;

    srand(time(NULL)); 

    fp = fopen("quicksort.txt","w");
    for(int i = 100; i <= 10000; i += 400){
        getRandomNumbers(a, i);
        start = clock();
        quick_sort(a, 0, i - 1);
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        theoretical_time = (double)(i * i * 1e-8); 
        fprintf(fp, "%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);

    FILE *gP;
    gP = popen("gnuplot -persistent", "w");
    fprintf(gP, "set title 'Quick Sort time Efficiency'\n");
    fprintf(gP, "set xlabel 'Input Size'\n");
    fprintf(gP, "set ylabel 'Time(seconds)'\n");
    fprintf(gP, "set grid\n");
    fprintf(gP, "set term pngcairo\n");  
    fprintf(gP, "set output 'q_sort_efficiency_c.png'\n");
    fprintf(gP, "plot 'quicksort.txt' using 1:2 with linespoints title 'Actual Time', "
                "'quicksort.txt' using 1:3 with lines lw 2 title 'Theoretical Time'\n");
    fflush(gP);
    pclose(gP);

    return 0;
}
