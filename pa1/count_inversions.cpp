#include <time.h>
#include <iostream>
#include <sstream>

using namespace std;

class CountInversions{

    public:
        int *divide(int a[], int n, unsigned int &global){
            if (n == 1){
                return a;
            }
            else{
                int *l = divide(a, n/2, global);
                int *r = divide(a+n/2, n-n/2, global);
                return conquer(l, r, n/2, n-n/2, global);
            }
        }

        int *conquer(int *left, int *right, int lsize, int rsize, unsigned int &global){
            int l = 0;
            int r = 0;
            unsigned long long counter = 0;
            int i = 0;
            int *output = new int[lsize+rsize]; 
            while(l < lsize && r < rsize){
                if (right[r] < left[l]){
                    output[i] = right[r];
                    r++;
                    counter += lsize - l;
                    i++;
                }
                else{
                    output[i] = left[l];
                    l++;
                    i++;
                }
                
            }
            while (l < lsize){
                output[i] = left[l];
                l++;
                i++;
            }
            while (r < rsize){
                output[i] = right[r];
                r++;
                i++;
            }
            /*
            for (int i = 0; i < lsize + rsize; i++){
                cout << output[i] << " ";
            }
            */
            global += counter;
            //cout <<endl;
            //cout << "current inversions: " <<  global <<endl;
            //cout << endl;
            return output;
        }

};




int main(){
    //int input[] = {9,10,4,3};
    int size = 10;
    //int size = 50;
    int input[size];

    for (int i=0; i<size; i++){
        cin >> input[i];
    }
    
    clock_t tStart = clock(); 
    unsigned int global = 0;

    CountInversions c;

    c.divide(input, sizeof(input)/sizeof(int), global);
    printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    cout << "global main: " << global <<endl;

    return 0; 
}
