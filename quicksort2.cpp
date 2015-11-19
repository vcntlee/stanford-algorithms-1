#include <iostream>
using namespace std;

/* divide 
 * partition
 * main */

void swapped(int *a, int l, int r){
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}

int partitioned(int *a, int start, int end, int p){
    
    int pivot = a[p];
    swapped(a, p, end);
    int j = start;
    for (int i=start; i < end; i++){
        if (a[i] <= pivot){
            swapped(a, i, j);
            j++;
        }
    }
    swapped(a, end, j);
    return j;
}

int *divide(int *a, int start, int end){
    if (start >= end) return a;
    int p = (start + end)/2;
    
    int pIndex = partitioned(a, start, end, p);
    divide(a, start, pIndex-1);
    divide(a, pIndex+1, end);
    return a;
}

int main(){
    //int a[] = {3,7,2,1,5,4};
    //int n = sizeof(a)/sizeof(int);
    
    int n = 50;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    
    int *o = divide(a, 0, n-1); 

    for (int i = 0; i<n; i++){
        cout << o[i] << " ";
    }
    cout <<endl;




    return 0;
}
