#include <iostream>
using namespace std;

class k{
    public:
        int divide(int l[], int lsize, int r[], int rsize){
            if (lsize == 1 && rsize == 1){
                return *l * *r;
            }
            else{
                
                int a = divide(l, lsize/2, r, rsize/2);
                int c = divide(l+lsize/2, lsize-lsize/2, r+rsize/2, rsize-rsize/2);
                int b = getB();
                return conquer(a, c, b);
            }
            
        }
        int getB(int l[], int lsize, int r[], int rsize){
            return divide(l); 
        }

        
};
