#include <iostream>
#include <time.h>
using namespace std;


int *conquer(int *left, int lsize, int *right, int rsize, int *output){
    int l = 0;
    int r = 0;
    int o = 0;
    while(l < lsize && r < rsize){
        if (left[l] < right[r]){
            output[o] = left[l];
            l++;
            o++;
        }
        else{
            output[o] = right[r];
            r++;
            o++;
        }
    }
    while (l < lsize){
        output[o] = left[l];
        o++;
        l++;
    }
    while (r < rsize){
        output[o] = right[r];
        o++;
        r++;
    }
    return output;

}

int *divide(int *a, int n){

    if (n == 1){
        return a;
    }
    else{
        
        int *left = divide(a, n/2);
        int *right = divide(a+n/2, n-n/2);
        int output[n/2 + n-n/2];
        return conquer(left, n/2, right, n-n/2, output); 
    }
}

int main(){

    int a[] = {7,2,1,6,4,5,3,8};
    //int a[] = {190, 89, 3, 10, 6 , 168, 74, 50, 37, 120, 302, 678, 25, 37, 65, 9, 8, 5, 10, 12, 89, 69};

    //int n = 100000;
    //int a[n];

    //for (int i=0; i<n; i++){
    //    cin >> a[i];
    //}
 
    int *output;
    int n = sizeof(a)/sizeof(int);
    
    clock_t tStart = clock(); 

    output = divide(a, n);
    printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++)
        cout << output[i] << " ";
    cout << "\n";

    return 0;

}
