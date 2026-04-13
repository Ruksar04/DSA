//Time Complexity - O(n²)
//Space Complexity - O(1) = constant because this is in-place bubble sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int a[], int n){
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

void getRandomNumbers(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = rand()%10000;
    }
}

int main(){
    
    //it checks how much time bubble sort takes for different input sizes and draws a graph.
    
    int a[10000];
    clock_t start, end;
    double time_taken;//Actual Time
    double theoretical_time;//Expected Time
    
    srand(time(NULL));  //rand() → generates random number
                        //srand() → give different random numbers every time I run the program Without this, same random numbers may come every time.
                        //time(NULL) → gives changing seed
    
    FILE *fp = fopen("bubblesort.txt", "w");
    for(int i = 100; i<=10000; i+=400){
        getRandomNumbers(a,i);
        start = clock();
        bubble_sort(a, i);
        end = clock();
        time_taken = (double) (end-start)/CLOCKS_PER_SEC;
        theoretical_time = (double)(i*i)*1e-8;//multiplied by 0.000000001 so that 100*100 = 10000 will become together
        fprintf(fp,"%d %lf %lf\n", i, time_taken, theoretical_time);
    }
    fclose(fp);
    
    FILE *gp = popen("gnuplot -persistent", "w");
    fprintf(gp, "set title 'Bubble Sort Time Efficiency'\n");
    fprintf(gp, "set xlabel 'Input Size'\n");
    fprintf(gp, "set ylabel 'Time(seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set term png\n");
    fprintf(gp, "set output 'b_sort_efficiency_c.png'\n");
    fprintf(gp, "plot 'bubblesort.txt' using 1:2 with linespoints title 'Actual Time',""'bubblesort.txt' using 1:3 with lines lw 2 title 'Theoretical Time'\n");
    fflush(gp);
    pclose(gp);
    return 0;
}
