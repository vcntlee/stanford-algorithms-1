#include <iostream>
#include <time.h>
using namespace std;

int swapped(int *a, int victim, int sub){
    int temp = a[victim];
    a[victim] = a[sub];
    a[sub] = temp;
    return victim;
}

int partitioned(int *a, int start, int end, int p){
    int pIndex = start;
    swapped(a, p, end);
    int pivot = a[end];
    for (int i = start; i < end; i++){
        if (a[i] <= pivot){
            swapped(a, pIndex, i);
            pIndex++;
        }
    }
    pIndex = swapped(a, pIndex, end);
    return pIndex;
}

int *quicksort(int *a, int start, int end){

    if (start >= end) return a;
    int p = (start + end) / 2; 
    int pIndex = partitioned(a, start, end, p);
    quicksort(a, start, pIndex-1);
    quicksort(a, pIndex + 1, end);
    return a;
}


int main(){

    //int a[] = {7,2,1,6,4,5,3,8};
    //int a[] = {190, 89, 3, 10, 6 , 168, 74, 50, 37, 120, 302, 678, 25, 37, 65, 9, 8, 5, 10, 12, 89, 69};
    
    int n = 100000;
    int a[n];

    for (int i=0; i<n; i++){
        cin >> a[i];
    }


    int *output;
    //int n = sizeof(a)/sizeof(int);
    
    clock_t tStart = clock(); 

    output = quicksort(a, 0, n-1);
    printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    //for (int i = 0; i < n; i++)
    //    cout << output[i] << " ";
    //cout << "\n";


    return 0;
}


