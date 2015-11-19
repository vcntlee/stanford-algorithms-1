#include <iostream>
using namespace std;

void swapped(int *a, int left, int right){
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}

int partitioned(int *a, int start, int end, int p){
    int pivot = a[p];
    //cout << "pivot " << pivot  <<endl;
    swapped(a, start, p);
    int j = start+1;

    for (int i = start+1; i <= end; i++){
        if (a[i] < pivot){
            swapped(a, i, j);
            j++;
        }
    }
    swapped(a, start, j-1);
    return j-1;
}

int *divide(int *a, int start, int end, int &counter, char option){
    if (start >= end)
        return a;
    else{
        int p=0; 
        if (option == 'f') p = start; 
        else if (option == 'l') p = end;
        else {
            p = (start+end)/2;
            int least = start;
            int mid = p;
            int most = end;
            int temp; 
            for (int i = 0; i < 2; i++){
                if ( a[mid]  < a[least] ){
                    temp = least;
                    least = mid;
                    mid = temp;
                }
                if (a[mid] > a[most]){
                    temp = most;
                    most = mid;
                    mid = temp;
                }
            }
            p = mid;
        }

        counter += end - start;
        int pIndex = partitioned(a, start, end, p);
        divide(a, start, pIndex-1, counter, option);
        divide(a, pIndex+1, end, counter, option);
        return a;
    }
}


int main(){

    int counter = 0;
    int n = 10;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    char option = 'm';
    divide(a, 0, n-1, counter, option);

//    for (int *i = a; i < a+n; i++)
//        cout << *i << " ";
//    cout << endl;
    
    cout << option  << " elt counter " << counter <<endl;

    return 0;

}
